import Activators
import CNN
import DNN
import MNIST
import numpy as np


class MNISTNetwork():
    # =============================构造网络结构=============================
    def __init__(self):
        self.loadDataSet()
        self.fl1 = DNN.FullConnectedLayer(784, 192, Activators.SigmoidActivator(), 0.01)  # 输入192个像素，输出为10种分类概率,学习速率为0.05
        self.fl = DNN.FullConnectedLayer(192, 10, Activators.IdentityActivator(), 0.01)

    # 根据输入计算一次输出。因为卷积层要求的数据要求有通道数，所以onepic是一个包含深度，高度，宽度的多维矩阵
    def forward(self, onepic):  # 池化层不改变深度，只改变宽高  因为池化层的计算是一层一层的提取运算的
        # print('图片：',onepic.shape)
        flinput = onepic.flatten().reshape(-1,1)
        self.fl1.forward(flinput)  # fl1input尺寸为192*1，全连接层的w是10*192
        self.fl.forward(self.fl1.output)
        return self.fl.output

    def backward(self, onepic, labels):
        # 计算误差
        # delta = np.multiply(self.fl.activator.backward(self.fl.output), (labels - self.fl.output))  # 计算输出层激活函数前的误差
        haha = np.exp(self.fl.output) / np.exp(self.fl.output).sum()  # 相当于softmax
        # print(haha.sum())
        # delta = (labels - self.fl.output) * (1 - self.fl.output ** 2)
        delta =  (labels - haha)    #尺寸为 10*1 我自己的误差算法，上面是原来的算法，上面的正确率太低
        # print('输出误差：',delta.shape)

        # 反向传播
        self.fl.backward(delta)  # 计算了全连接层输入前的误差，以及全连接的w和b的梯度   误差传递公式 error_j=W.T点乘error_k   self.fl.delta=
        self.fl.update()  # 更新全连接层的权重w和偏量b
        # print('全连接层输入误差：', self.fl1.delta.shape)
        self.fl1.backward(self.fl.delta)
        self.fl1.update()


    def train(self):
        for i in range(1):  # 迭代训练10次。每个迭代内，对所有训练数据进行训练，更新（训练图像个数/batchsize）次网络参数
            for k in range(self.train_data_set.shape[0]):
                # 正向计算
                onepic = self.train_data_set[k]
                onepic = np.array([onepic])  # 卷积神经网络要求的输入必须包含深度、高度、宽度三个维度。
                result = self.forward(onepic)  # 前向计算一次
                # print(result.fl1atten())
                labels = self.train_labels[k].reshape(-1, 1)  # 获取样本输出，转化为列向量
                # print(labels)
                self.backward(onepic, labels)

    def test(self):
        right = 0
        for k in range(self.test_data_set.shape[0]):  # 使用每一个样本进行训练
            # 正向计算
            onepic = self.test_data_set[k]
            onepic = np.array([onepic])  # 卷积神经网络要求的输入必须包含深度、高度、宽度三个维度。
            result = self.forward(onepic)  # 前向计算一次
            labels = self.test_labels[k].reshape(-1, 1)  # 获取样本输出，转化为列向量
            # print(result)
            pred_type = result.argmax()
            # print(pred_type)
            real_type = labels.argmax()
            # print(pred_type,real_type)
            if pred_type == real_type:
                right += 1
        return right / self.test_data_set.shape[0]


    def loadDataSet(self):
        # =============================加载数据集=============================
        self.train_data_set, self.train_labels = MNIST.get_training_data_set(700,
                                                                             False)  # 加载训练样本数据集，和one-hot编码后的样本标签数据集。样本数量越大，训练时间越久，也越准确
        # print(type(train_data_set))    <class 'list'>
        self.test_data_set, self.test_labels = MNIST.get_test_data_set(100,
                                                                       False)  # 加载测试特征数据集，和one-hot编码后的测试标签数据集。训练时间越久，也越准确
        self.train_data_set = np.array(self.train_data_set).astype(bool).astype(int)  # 可以将图片简化为黑白图片
        self.train_labels = np.array(self.train_labels)
        self.test_data_set = np.array(self.test_data_set).astype(bool).astype(
            int)  # 可以将图片简化为黑白图片  将数据转化为bool布尔型，True  false  进而转化为0、1数据
        self.test_labels = np.array(self.test_labels)

        print('样本数据集的个数：%d' % len(self.train_data_set))
        print('测试数据集的个数：%d' % len(self.test_data_set))