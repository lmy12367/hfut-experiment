import Activators
import CNN
import DNN
import MNIST
import numpy as np


class MNISTNetwork():
    # =============================构造网络结构=============================
    def __init__(self):
        self.loadDataSet()
        # 初始化构造卷积层：输入宽度、输入高度、通道数、滤波器宽度、滤波器高度、滤波器数目、补零数目、步长、激活器、学习速率
        self.cl1 = CNN.ConvLayer(28, 28, 1, 5, 5, 6, 0, 1, Activators.TanhActivator(),
                                 0.02)  # 输入28*28 一通道，滤波器5*5的6个，步长为1，不补零，所以输出为24*24深度6
        # 构造降采样层，参数为输入宽度、高度、通道数、滤波器宽度、滤波器高度、步长
        self.pl1 = CNN.MaxPoolingLayer(24, 24, 6, 2, 2, 2)  # 输入24*24，6通道，滤波器2*2，步长为2，所以输出为12*12，深度保持不变为6
        # 初始化构造卷积层：输入宽度、输入高度、通道数、滤波器宽度、滤波器高度、滤波器数目、补零数目、步长、激活器、学习速率
        self.cl2 = CNN.ConvLayer(12, 12, 6, 5, 5, 12, 0, 1, Activators.TanhActivator(),
                                 0.02)  # 输入12*12，6通道，滤波器5*5的12个，步长为1，不补零，所以输出为8*8深度12
        # 构造降采样层，参数为输入宽度、高度、通道数、滤波器宽度、滤波器高度、步长
        self.pl2 = CNN.MaxPoolingLayer(8, 8, 12, 2, 2, 2)  # 输入8*8，12通道，滤波器2*2，步长为2，所以输出为4*4，深度保持不变为12。共192个像素
        # 全连接层构造函数。input_size: 本层输入向量的维度。output_size: 本层输出向量的维度。activator: 激活函数
        self.fl = DNN.FullConnectedLayer(192, 10, Activators.TanhActivator(), 0.02)  # 输入192个像素，输出为10种分类概率,学习速率为0.05

    # 根据输入计算一次输出。因为卷积层要求的数据要求有通道数，所以onepic是一个包含深度，高度，宽度的多维矩阵
    def forward(self, onepic):  # 池化层不改变深度，只改变宽高  因为池化层的计算是一层一层的提取运算的
        # print('图片：',onepic.shape)
        self.cl1.forward(onepic)  # 返回值6*24*24深度，高度，宽度  即self.cl1.output_array   卷积核为1*5*5    6*24*24
        # print('第一层卷积结果：',self.cl1.output_array.shape)
        self.pl1.forward(self.cl1.output_array)  # 通过最大池化层后，深度不变仍为6 ，卷积核为 2*2 尺寸改变  self.pl1.output_array 6*12*12
        # print('第一层采样结果：',self.pl1.output_array.shape)
        self.cl2.forward(self.pl1.output_array)  # 卷积核为 6*5*5  计算之后尺寸为 self.cl2.output_array 12*8*8
        # print('第二层卷积结果：',self.cl2.output_array.shape)
        self.pl2.forward(self.cl2.output_array)  # 卷积核为 12*2*2  深度不变仍为12  计算之后尺寸为 self.pl2.output_array 12*4*4
        # print('第二层采样结果：',self.pl2.output_array.shape)
        flinput = self.pl2.output_array.flatten().reshape(-1,
                                                          1)  # 转化为列向量  结果为12*4*4=192  a是个矩阵或者数组，a.flatten()就是把a降到一维，默认是按横的方向降
        # print(self.pl2.output_array.shape[0])
        # print(self.pl2.output_array.shape[1])
        # print(self.pl2.output_array.shape[2])
        # print(len(flinput))
        self.fl.forward(flinput)  # flinput尺寸为192*1，全连接层的w是10*192
        # print('全连接层结果：',self.fl.output)#self.fl.output尺寸为 10*1  因为经过了 W*t+b   W为10*192
        return self.fl.output

    def backward(self, onepic, labels):
        # 计算误差
        # delta = np.multiply(self.fl.activator.backward(self.fl.output), (labels - self.fl.output))  # 计算输出层激活函数前的误差
        haha = np.exp(self.fl.output) / np.exp(self.fl.output).sum()  # 相当于softmax
        # print(haha.sum())
        delta = (labels - self.fl.output) * (1 - self.fl.output ** 2)
        # delta =  (labels - haha)    #尺寸为 10*1 我自己的误差算法，上面是原来的算法，上面的正确率太低
        # print('输出误差：',delta.shape)

        # 反向传播
        self.fl.backward(delta)  # 计算了全连接层输入前的误差，以及全连接的w和b的梯度   误差传递公式 error_j=W.T点乘error_k   self.fl.delta=
        self.fl.update()  # 更新全连接层的权重w和偏量b
        # print('全连接层输入误差：', self.fl.delta.shape)
        sensitivity_array = self.fl.delta.reshape(
            self.pl2.output_array.shape)  # 将误差转化为同等形状  self.pl2.output_array 形状为12*4*4
        self.pl2.backward(self.cl2.output_array, sensitivity_array)  # 计算第二采样层的输入误差。参数为第二采样层的 1、输入，2、输出误差
        # print('第二采样层的输入误差：', self.pl2.delta_array.shape)
        self.cl2.backward(self.pl1.output_array, self.pl2.delta_array,
                          Activators.TanhActivator())  # 计算第二卷积层的输入误差。参数为第二卷积层的 1、输入，2、输出误差，3、激活函数
        self.cl2.update()  # 更新权重w和偏量b 6*12*12          12*8*8
        # print('第二卷积层的输入误差：', self.cl2.delta_array.shape)
        self.pl1.backward(self.cl1.output_array, self.cl2.delta_array)  # 计算第一采样层的输入误差。参数为第一采样层的 1、输入，2、输出误差
        # print('第一采样层的输入误差：', self.pl1.delta_array.shape)
        self.cl1.backward1(onepic, self.pl1.delta_array,
                           Activators.TanhActivator())  # 计算第一卷积层的输入误差。参数为第一卷积层的 1、输入，2、输出误差，3、激活函数
        self.cl1.update()  # 更新权重w和偏量b
        # print('第一卷积层的输入误差：', self.cl1.delta_array.shape)

    def train(self):
        for i in range(1):  # 迭代训练10次。每个迭代内，对所有训练数据进行训练，更新（训练图像个数/batchsize）次网络参数
            # print('迭代：', s)
            for k in range(self.train_data_set.shape[
                               0]):  # 使用每一个样本进行训练image.shape[0]#图片垂直尺寸image.shape[1]#图片水平尺寸image.shape[2]#图片通道数

                # 正向计算
                onepic = self.train_data_set[k]
                onepic = np.array([onepic])  # 卷积神经网络要求的输入必须包含深度、高度、宽度三个维度。
                result = self.forward(onepic)  # 前向计算一次
                # print(result.flatten())
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
        # print('Runtime for training %f \nright ratio is %f' % (
        # time.time() - beforetime,right / test_data_set.shape[0]))  # 打印输出正确率

    def loadDataSet(self):
        # =============================加载数据集=============================
        self.train_data_set, self.train_labels = MNIST.get_training_data_set(600,
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