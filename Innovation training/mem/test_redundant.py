import pickle
import numpy as np
import Memristor as mem
import matplotlib.pyplot as plt
import tqdm
# import minpy
from DNN_ins import MNISTNetwork

if __name__ == '__main__':
    # 读取数据
    mynetwork = pickle.load(open('dnn_module.sav', 'rb'))
    # 测试test集合的分类准确率
    # ======================忆阻器异常故障干扰=======================
    start = 0
    end = 120
    n = 7
    m = 3
    W_ori = mynetwork.fl.W
    x = np.linspace(start, end, n)
    # print(x)
    # 初始化参数列表用于绘图
    scale_14 = np.zeros(n)
    scale_16 = np.zeros(n)
    scale_18 = np.zeros(n)
    scale_22 = np.zeros(n)
    scale_24 = np.zeros(n)
    scale_28 = np.zeros(n)
    #
    for i in tqdm.trange(n):
        scale_14_tmp = 0
        scale_16_tmp = 0
        scale_18_tmp = 0
        scale_22_tmp = 0
        scale_24_tmp = 0
        scale_28_tmp = 0
        for j in range(m):
            W = W_ori.T  # 转置
            # scale = 2
            T_mem_exp = mem.mem_vari_redundant(W, 1.4, int(x[i]))
            T_mem_exp = mem.KM(W, T_mem_exp)
            T_mem = T_mem_exp * W
            mynetwork.fl.W = T_mem.T
            scale_14_tmp += mynetwork.test()
            # scale = 2.4
            T_mem_exp = mem.mem_vari_redundant(W, 1.6, int(x[i]))
            T_mem_exp = mem.KM(W, T_mem_exp)
            T_mem = T_mem_exp * W
            mynetwork.fl.W = T_mem.T
            scale_16_tmp += mynetwork.test()
            # scale = 2.4
            T_mem_exp = mem.mem_vari_redundant(W, 1.8, int(x[i]))
            T_mem_exp = mem.KM(W, T_mem_exp)
            T_mem = T_mem_exp * W
            mynetwork.fl.W = T_mem.T
            scale_18_tmp += mynetwork.test()
            # scale = 2.4
            T_mem_exp = mem.mem_vari_redundant(W, 2.2, int(x[i]))
            T_mem_exp = mem.KM(W, T_mem_exp)
            T_mem = T_mem_exp * W
            mynetwork.fl.W = T_mem.T
            scale_22_tmp += mynetwork.test()
            # scale = 2.8
            T_mem_exp = mem.mem_vari_redundant(W, 2.4, int(x[i]))
            T_mem_exp = mem.KM(W, T_mem_exp)
            T_mem = T_mem_exp * W
            mynetwork.fl.W = T_mem.T
            scale_24_tmp += mynetwork.test()
            # scale = 3.2
            T_mem_exp = mem.mem_vari_redundant(W, 2.8, int(x[i]))
            T_mem_exp = mem.KM(W, T_mem_exp)
            T_mem = T_mem_exp * W
            mynetwork.fl.W = T_mem.T
            scale_28_tmp += mynetwork.test()
        scale_14[i] = scale_14_tmp/m
        scale_24[i] = scale_24_tmp/m
        scale_28[i] = scale_28_tmp/m
        scale_16[i] = scale_16_tmp/m
        scale_18[i] = scale_18_tmp/m
        scale_22[i] = scale_22_tmp/m
    # 绘图
    fig = plt.figure()
    axis = fig.add_subplot(111)
    axis.plot(x, scale_14, marker='.', label='1.4')
    axis.plot(x, scale_16, marker='.', label='1.6')
    axis.plot(x, scale_18, marker='.', label='1.8')
    # axis.plot(x, scale_22, marker='.', label='2.2')
    axis.plot(x, scale_24, marker='.', label='2.4')
    axis.plot(x, scale_28, marker='.', label='2.8')


    axis.set_xlabel('bi-map redundant')
    axis.set_ylabel('test rate')
    axis.set_ylim(0,1)
    axis.legend(bbox_to_anchor=(1.05, 0), loc=3)
    fig.show()

