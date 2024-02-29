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
    #======================忆阻器异常故障干扰=================
    n = 5
    W_ori = mynetwork.fl1.W
    x = np.linspace(1, n, n)
    #初始化参数列表用于绘图
    delta = np.zeros(n)
    before_SWV = np.zeros(n)
    after_SWV = np.zeros(n)
    before_acc = np.zeros(n)
    after_acc = np.zeros(n)
    after_retrain = np.zeros(n)

    for i in tqdm.trange(n):
        # print(i+1)
        #执行KM算法前
        W = W_ori.T
        T_mem_exp = mem.mem_variation(W, 1.5)
        tmp = T_mem_exp[0:W.shape[0], :]
        T_mem = tmp * W
        # mem.mem_SAF(tmp)
        mynetwork.fl1.W = T_mem.T
        before_SWV[i] = mem.SWV(W, T_mem_exp * W)
        # print(before_SWV[i])
        before_acc[i] = mynetwork.test()
        print(before_acc[i])
        #KM算法后
        tmp = mem.KM(W, tmp)
        # T_mem_exp = mem.greedy(W, T_mem_exp)#贪心算法

        after_SWV[i] = mem.SWV(W, tmp * W)
        # print(after_SWV[i])
        mynetwork.fl1.W = (tmp * W).T
        after_acc[i] = mynetwork.test()
        print(after_acc[i])
        mem.retrain(W, T_mem_exp, mynetwork)
        after_retrain[i] = mynetwork.test()

        delta[i] = after_acc[i] - before_acc[i]
    avg_acc = delta.sum()/n
    print('Average of increasing: %f',avg_acc)
    fig = plt.figure()
    ax1 = fig.add_subplot(1, 2, 1)
    ax1.plot(x, before_acc, label='Acc_before')
    ax1.plot(x, after_acc, label='Acc_after')
    ax1.legend()

    ax2 = fig.add_subplot(1, 2, 2)
    ax2.plot(x, before_SWV, label='SWV_before')
    ax2.plot(x, after_SWV, label='SWV_after')
    ax2.legend()

    fig.show()