# 忆阻器相关函数的模块
import numpy as np


# 一. 忆阻器真实矩阵初始化（4种）
#     input：权值矩阵
#     return：仿真的忆阻器矩阵
#     1- 理想情况下
def mem_ideal(weight_train):
    return np.ones(shape=weight_train.shape)


#     2- variation 的初始化：W_new = W_old * exp(normal(0,scale,size))
def mem_variation(weight_train, scale):
    """返回一个有variation的忆阻器矩阵"""
    tmp = np.exp(np.random.normal(0, scale, size=weight_train.shape))
    return tmp

#     2.1 variation初始化，加上冗余行的情况
def mem_vari_redundant(weight_train, scale, num_redundant):
    """返回一个含有冗余行的variation矩阵"""
    row = weight_train.shape[0]
    col = weight_train.shape[1]
    result = np.exp(np.random.normal(0, scale, size=(row + num_redundant, col)))
    return result

#     3- SAF0 和 SAF1的初始化
#     4- 既有variation 又有 SAF
def mem_SAF(weight_train):
    """返回一个有SAF的矩阵"""
    for i in range(15):
        pass
    pass
    # return


# 二. 忆阻器真是矩阵和权值矩阵映射函数



def SWV(weight_train, weight_T):
    result = abs(weight_train - weight_T).sum()
    return result


def SWV_map(weight_train, T_mem_exp):
    """返回行映射的所有情况下的SWV值矩阵"""
    row_n = weight_train.shape[0]
    result = np.zeros(shape=(row_n, row_n))
    # print(result.shape)
    for i in range(row_n):
        tmp = weight_train[i]
        # print(tmp)
        T_tmp = T_mem_exp * tmp
        tmp = abs(T_tmp - tmp)
        # print(tmp)
        tmp = tmp.sum(axis=1)
        # print(tmp)
        result[i] = tmp
    return result

def SWV_map_redundant(weight_train, T_mem_exp):
    row_n = weight_train.shape[0]
    col_n = T_mem_exp.shape[0]
    result = np.zeros(shape=(row_n, col_n))
    for i in range(row_n):
        tmp = weight_train[i]
        T_tmp = T_mem_exp * tmp
        tmp = abs(tmp - T_tmp)
        tmp = tmp.sum(axis=1)
        result[i] = tmp
    return result

#     1- 贪心算法
#         description：基于贪心算法的映射
#         input：权值矩阵，忆阻器矩阵
#         return：新映射的忆阻器矩阵

def greedy(weight_train, T_mem_exp):
    n = weight_train.shape[0]
    SWV = SWV_map(weight_train, T_mem_exp * weight_train)
    match = np.ones(weight_train.shape[0], int) * -1
    for i in range(n):
        # print(SWV)
        tmp = SWV[i, :].argmin()
        # print(tmp)
        match[i] = tmp
        SWV[:, tmp] = 9999999
    # print(match)
    T_mem_after = np.zeros(shape=T_mem_exp.shape)
    for i in range(n):
        T_mem_after[match[i]] = T_mem_exp[i]
    return T_mem_after


def dfs(topW, topT, visW, visT, SWV_map, match_T, slack_T, w):
    w = int(w)
    visW[w] = True
    for i in range(visT.shape[0]):
        if visT[i]:
            continue
        gap = topW[w] + topT[i] - SWV_map[w, i]  # 注意选取的是权值最小的边
        # if gap == 0:
        if abs(gap - 0) <= 0.0001:
            visT[i] = True
            if match_T[i] == -1 or dfs(topW, topT, visW, visT, SWV_map, match_T, slack_T, match_T[i]):
                match_T[i] = w
                return True
        else:
            slack_T[i] = min(slack_T[i], gap)
    return False

#     2- KM算法
#         description：基于KM算法的映射
#         input：权值矩阵，忆阻器矩阵
#         return：新映射的忆阻器矩阵
def KM(weight_train, T_mem_exp):
    """通过KM算法得到映射完成后的T_mem_exp矩阵"""
    n = weight_train.shape[0]
    m = T_mem_exp.shape[0]
    if T_mem_exp.shape[0] == n:
        SWV = SWV_map(weight_train, T_mem_exp)
    else:
        SWV = SWV_map_redundant(weight_train,T_mem_exp)
    SWV = - SWV
    topW = SWV.max(axis=1)  # W权值矩阵的顶标
    # print(topW)
    topT = np.zeros(m)  # T矩阵的顶标
    visW = np.ones(n, bool) * False
    visT = np.ones(m, bool) * False
    match_T = np.ones(m, int) * -1
    slack_T = np.ones(m) * np.inf
    for i in range(n):
        slack_T = np.ones(m) * np.inf
        # print(i)
        # print(match_T)
        while True:
            visW = np.zeros(n, bool) * False
            visT = np.zeros(m, bool) * False
            if dfs(topW, topT, visW, visT, SWV, match_T, slack_T, i):
                break
            d = np.inf
            for j, slack in enumerate(slack_T):
                if not visT[j] and slack < d:
                    d = slack
            # print(d)
            for j in range(m):
                if visT[j]:
                    topT[j] += d
            for j in range(n):
                if visW[j]:
                    topW[j] -= d
    T_mem_after = np.zeros(shape=weight_train.shape)
    for i in range(m):
        if match_T[i] != -1:
            T_mem_after[match_T[i]] = T_mem_exp[i]
    # print(T_mem_after - T_mem_exp)
    return T_mem_after

# 三. 加速器友好的神经网络训练
#     1- 训练函数
#         description：加速器友好训练的函数主体
#         input：映射完成后的忆阻器阵列，权值矩阵
#         return：新的权值
def retrain(weight_train, T_mem_exp, mynetwork):
    n = weight_train.shape[0]
    m = weight_train.shape[1]
    before_train = 0
    num_iter = 0
    while True:
        num_iter += 1
        # 更新权值SWV
        update_SWV = T_mem_exp * weight_train
        # 找到最大的SWV的权重
        max = update_SWV.max()
        # loc_x = int(max/n)
        # loc_y = max - loc_x * n
        # 将该权重缩小，乘上0.5
        # 将该权重的F设为0
        for i in range(n):
            for j in range(m):
                if  abs(update_SWV[i,j] - max) <= 0.00001:
                    weight_train[i,j] = weight_train[i,j] * 0.5
                    # mynetwork.fl.W = weight_train.T
                    mynetwork.fl.F[j, i] = 0
        mynetwork.train()# 重新训练神经网络
        test_ratio = mynetwork.test()
        # print(test_ratio)
        if (test_ratio - before_train) < 0.03:
            break# 是则结束
        before_train = test_ratio
    mynetwork.fl.F = np.ones(weight_train.T.shape)
    return num_iter
    # 否则继续循环

def retrain_test(weight_train, T_mem_exp, mynetwork, time):
    n = weight_train.shape[0]
    m = weight_train.shape[1]
    before_train = 0
    num_iter = 0
    while True:
        num_iter += 1
        # 更新权值SWV
        update_SWV = T_mem_exp * weight_train
        # 找到最大的SWV的权重
        max = update_SWV.max()
        # loc_x = int(max/n)
        # loc_y = max - loc_x * n
        # 将该权重缩小，乘上0.5
        # 将该权重的F设为0
        for t in range(time):
            for i in range(n):
                for j in range(m):
                    if  abs(update_SWV[i,j] - max) <= 0.00001:
                        weight_train[i,j] = weight_train[i,j] * 0.5
                        mynetwork.fl.F[j, i] = 0
        mynetwork.train()# 重新训练神经网络
        test_ratio = mynetwork.test()
        # print(test_ratio)
        if (test_ratio - before_train) < 0.03:
            break# 是则结束
        before_train = test_ratio
    mynetwork.fl.F = np.ones(weight_train.T.shape)
    return num_iter
    # 否则继续循环