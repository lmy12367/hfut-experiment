import pickle
import numpy as np
import Memristor as mem
import matplotlib.pyplot as plt
import tqdm
from Mynetwork import MNISTNetwork


# 由于使用了逻辑回归函数，所以只能进行分类识别。识别ont-hot编码的结果
if __name__ == '__main__':
    #读取数据
    mynetwork = pickle.load(open('cnn_module.sav','rb'))
    #测试test集合的分类准确率
    #======================忆阻器异常故障干扰=======================
    start = 0.6
    end = 2
    n = 8
    W_ori = mynetwork.fl.W
    x = np.linspace(start, end, n)
    # print(x)
    #初始化参数列表用于绘图
    ideal = np.ones(n) * mynetwork.test()
    before_map = np.zeros(n)
    greed = np.zeros(n)
    bi_map = np.zeros(n)
    bi_retrain = np.zeros(n)
    #计算不同情况下的test_rate
    for i in tqdm.trange(n):
        W = W_ori.T#转置
        T_mem_exp_ori = mem.mem_variation(W, x[i])#仿真映射到的忆阻器矩阵（仅考虑variation）
        #before-map的情况
        T_mem = T_mem_exp_ori * W
        mynetwork.fl.W = T_mem.T
        before_map[i] = mynetwork.test()
        #进行KM算法映射的情况
        T_mem_exp_KM = mem.KM(W, T_mem_exp_ori)
        T_mem = T_mem_exp_KM * W
        mynetwork.fl.W = T_mem.T
        bi_map[i] = mynetwork.test()
        #贪心算法映射的情况
        T_mem_exp_greedy = mem.greedy(W, T_mem_exp_ori)
        T_mem = T_mem_exp_greedy * W
        mynetwork.fl.W = T_mem.T
        greed[i] = mynetwork.test()
        # retrain后的情况
        mem.retrain(W, T_mem_exp_KM, mynetwork)
        T_mem = T_mem_exp_KM * W
        mynetwork.fl.W = T_mem.T
        bi_retrain[i] = mynetwork.test()
    #画图
    fig = plt.figure()
    axis = fig.add_subplot(111)
    axis.plot(x, ideal, label='ideal')
    axis.plot(x, before_map, label='before_map')
    axis.plot(x, bi_map, label='bi_map')
    axis.plot(x, bi_retrain, label='bi_retrain')
    axis.plot(x, greed, label='greed')
    axis.set_xlabel('scale')
    axis.set_ylabel('test_rate')
    axis.legend(bbox_to_anchor=(1.05,0), loc=3)
    fig.show()
