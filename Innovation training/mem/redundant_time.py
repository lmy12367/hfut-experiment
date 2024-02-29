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
    start = 1
    end = 50
    n = 4
    m = 5
    W_ori = mynetwork.fl.W
    x = np.linspace(start, end, n)
    # print(x)
    W = W_ori.T
    T_exp = mem.mem_variation(W, 3)
    T_exp = mem.KM(W, T_exp)
    #计算不同情况下的test_rate
    iteration = np.zeros(n)
    for i in tqdm.trange(n):
