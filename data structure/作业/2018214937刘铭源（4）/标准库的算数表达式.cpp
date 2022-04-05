#include <iostream>
#include <stack>//栈的文件
#include <string>//字符串文件
using namespace std;
stack <double> num;//数字栈
stack <char> op;//字符栈
void dealString(string station)
{     //字符串转数字操作符进栈
 double Nownum = 0;	//初始化
 for (int i = 0; i<station.length(); i++)
    {//扫描进栈
 		if (station[i] >= '0'&&station[i] <= '9')
 		 {
		 			Nownum *= 10;
					Nownum += station[i] - '0';
					}
		else
            {
					num.push(Nownum);//数字压栈
					Nownum = 0;
                	op.push(station[i]);//操作符压栈
    		};
		}
			num.push(Nownum);
	}
int inPriority(char a)
{    //操作符优先级判断函数，数字越大越优先
            switch (a)
            {
			case '*':
			case '/':
					return 2;//乘除同级
			case '+':
			case '-':
					return 1;//加减同级
			case '(':
					return 3;
			case ')':
					return 4;//右括号大于左括号
			default:
					cout << "error" << endl;//否则输出错误
			return -1;
			}
	}
double dealNum(double n1, double n2, char op)
 {     //数字处理函数
	switch (op)
	 {
	case '+':
			return n2 + n1;//加减乘除四种情况
	case '-':
			return n2 - n1;
	case '*':
			return n2*n1;
	case '/':
			return n2 / n1;
	default:
			return 0;
				}
	}
double cal()
{
	double num1, num2, num3 = 0;//初始化
	char op1, op2;
	num1 = num.top();
	num.pop();
	num2 = num.top();
	num.pop();
	op1 = op.top();
	op.pop();
	while (op.size()>0)
        {
			if (inPriority(op1) == 4)
                {            //判断是否为右括号
						num.push(num2);
						num1 = cal();
						if (op.size()>0)
                            {
								num2 = num.top();
								num.pop();
								op1 = op.top();
								op.pop();
								if (op.size() == 0)
                                    {
									return dealNum(num1, num2, op1);
			                 	}
			            }
			            else
                            {
     			            	return num1;
				             	break;
				           	}
    		}
			if (inPriority(op.top()) == 4)
                {
						op.pop();
						num2 = cal();
						if (op.size() == 0)
                            {
									return dealNum(num1, num2, op1);
						}
			}
			if (inPriority(op1) == 3)
                {    //判断是否为左括号
						return num1;
			}
			if (inPriority(op.top()) == 3)
                {
				num.pop();
				op.pop();
				return dealNum(num1, num2, op1);
			}
			if (inPriority(op1)>inPriority(op.top()))
                {    //判断优先级并计算
				num1 = dealNum(num1, num2, op1);
				num2 = num.top();
				num.pop();
				op1 = op.top();
				op.pop();
			}
			else
                {
				num2 = dealNum(num2, num.top(), op.top());
				num.pop();
				op.pop();
			}
		}
		return dealNum(num1, num2, op1);
		}
		int main()
		{
		        while (1)
                {        //循环输入，结束直接关闭即可
				string station;
				cout << "输入算式： " << endl;
				cin>>station;
				dealString(station);
				cout << "结果为： " << cal() << endl << endl;
				}
	}
