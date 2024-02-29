# 使用全连接神经网络类，和手写数据加载器，实现验证码识别。
import pickle

import matplotlib.pyplot as plt
import numpy as np



# 网络模型类
import tqdm

import Mynetwork

if __name__ == '__main__':

    # =============================构造网络结构=============================
    mynetwork = Mynetwork.MNISTNetwork()
    # n = input("please input number of training: ")
    # n = int(n)
    n = 5
    # =============================迭代训练=============================
    right_ratio = np.zeros(n)
    for i in tqdm.trange(n):
        mynetwork.train()
        right_ratio[i] = mynetwork.test()
    #=============================保存训练结果===============================
    fname = 'cnn_module.sav'
    pickle.dump(mynetwork, open(fname, 'wb'))
    # =============================评估结果=============================
    x = np.linspace(1, n, n)
    plt.plot(x, right_ratio, ls="-", lw=2, label='Right ratio')  # 测试正确率随迭代次数变化曲线
    plt.xlabel('times of training')
    plt.ylabel('Right ratio')
    plt.legend()
    plt.show()
    # yl[cishu]=right/test_data_set.shape[0]
    # print(yl)
    # print('Runtime for training %f \n right ratio is %f' % (time.time()-beforetime, right/test_data_set.shape[0]))  # 打印输出正确率
    # x = range(len(yl))
    # plt.plot(yl)
    # plt.show()
