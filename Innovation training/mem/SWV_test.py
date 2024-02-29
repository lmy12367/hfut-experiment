import pickle
import numpy as np
import Memristor as mem
import matplotlib.pyplot as plt
import tqdm
from DNN_ins import MNISTNetwork


# 由于使用了逻辑回归函数，所以只能进行分类识别。识别ont-hot编码的结果
if __name__ == '__main__':
    #读取数据
    mynetwork = pickle.load(open('dnn_module.sav','rb'))
    #测试test集合的分类准确率
    #======================忆阻器异常故障干扰=======================
    start = 1.4
    end = 3
    n = 20
    m = 10
    W_ori = mynetwork.fl.W
    x = np.linspace(start, end, n)
    # print(x)
    #初始化参数列表用于绘图
    ideal = np.ones(n) * mynetwork.test()
    before_map = np.zeros(n)
    before_map_SWV = np.zeros(n)
    greed = np.zeros(n)
    greed_SWV = np.zeros(n)
    bi_map = np.zeros(n)
    bi_map_SWV = np.zeros(n)
    bi_retrain = np.zeros(n)
    bi_retrain_SWV = np.zeros(n)
    #计算不同情况下的test_rate
    for i in tqdm.trange(n):
        before_map_tmp = 0
        before_map_SWV_tmp = 0
        greed_tmp = 0
        greed_SWV_tmp = 0
        bi_map_tmp = 0
        bi_map_SWV_tmp = 0
        bi_retrain_tmp = 0
        bi_retrain_SWV_tmp = 0
        for j in range(m):
            mynetwork = pickle.load(open('dnn_module.sav', 'rb'))
            W = W_ori.T#转置
            T_mem_exp_ori = mem.mem_variation(W, x[i])#仿真映射到的忆阻器矩阵（仅考虑variation）
            #before-map的情况
            T_mem = T_mem_exp_ori * W
            mynetwork.fl.W = T_mem.T
            before_map_tmp += mynetwork.test()
            before_map_SWV_tmp += mem.SWV(W,T_mem)
            #进行KM算法映射的情况
            # T_mem_exp_KM = mem.KM(W, T_mem_exp_ori)
            # bi_map_tmp += mynetwork.test()
            # bi_map_SWV_tmp += mem.SWV(W,T_mem)
            #贪心算法映射的情况
            T_mem_exp_greedy = mem.greedy(W, T_mem_exp_ori)
            T_mem = T_mem_exp_greedy * W
            mynetwork.fl.W = T_mem.T
            greed_tmp += mynetwork.test()
            greed_SWV_tmp += mem.SWV(W,T_mem)
            # mynetwork.fl.W = W_ori
            # retrain后的情况
            # mem.retrain(W, T_mem_exp_KM, mynetwork)
            # T_mem = T_mem_exp_KM * W
            # mynetwork.fl.W = T_mem.T
            # bi_retrain_tmp += mynetwork.test()
            # bi_retrain_SWV_tmp += mem.SWV(W,T_mem)
        before_map[i] = before_map_tmp/m
        before_map_SWV[i] = before_map_SWV_tmp/m
        greed[i] = greed_tmp/m
        greed_SWV[i] = greed_SWV_tmp/m
        # bi_map[i] =bi_map_tmp/m
        # bi_map_SWV[i] =bi_map_SWV_tmp/m
        # bi_retrain[i] = bi_retrain_tmp/m
        # bi_retrain_SWV[i] = bi_retrain_SWV_tmp/m
    #画图
    fig = plt.figure()
    axis1 = fig.add_subplot(121)
    axis1.plot(x,before_map,label = 'before-map',marker = '.',lw = 1)
    axis1.plot(x,greed,label = 'greed',marker = '.',lw = 1)
    # axis1.plot(x,bi_map,label = 'bi-map',marker = '.',lw = 1)
    # axis1.plot(x,bi_retrain,label = 'bi-retrain',marker = '.',lw = 1)
    axis1.set_xlabel('σ')
    axis1.set_ylabel('test rate')
    axis1.legend()
    axis2 = fig.add_subplot(122)
    axis2.plot(x, before_map_SWV, marker = '.',lw = 1,label='before-map')
    # axis2.plot(x, bi_map_SWV, label='bi-map',marker = '.',lw = 1)
    axis2.plot(x, greed_SWV, marker = '.',lw = 1,label='greed')
    # axis2.plot(x, bi_retrain_SWV, marker = '.',lw = 1,label='bi-retrain')
    axis2.set_xlabel('σ')
    axis2.set_ylabel('SWV')
    axis2.legend()
    fig.show()
