#include <iostream>
#include <stack>//ջ���ļ�
#include <string>//�ַ����ļ�
using namespace std;
stack <double> num;//����ջ
stack <char> op;//�ַ�ջ
void dealString(string station)
{     //�ַ���ת���ֲ�������ջ
 double Nownum = 0;	//��ʼ��
 for (int i = 0; i<station.length(); i++)
    {//ɨ���ջ
 		if (station[i] >= '0'&&station[i] <= '9')
 		 {
		 			Nownum *= 10;
					Nownum += station[i] - '0';
					}
		else
            {
					num.push(Nownum);//����ѹջ
					Nownum = 0;
                	op.push(station[i]);//������ѹջ
    		};
		}
			num.push(Nownum);
	}
int inPriority(char a)
{    //���������ȼ��жϺ���������Խ��Խ����
            switch (a)
            {
			case '*':
			case '/':
					return 2;//�˳�ͬ��
			case '+':
			case '-':
					return 1;//�Ӽ�ͬ��
			case '(':
					return 3;
			case ')':
					return 4;//�����Ŵ���������
			default:
					cout << "error" << endl;//�����������
			return -1;
			}
	}
double dealNum(double n1, double n2, char op)
 {     //���ִ�����
	switch (op)
	 {
	case '+':
			return n2 + n1;//�Ӽ��˳��������
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
	double num1, num2, num3 = 0;//��ʼ��
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
                {            //�ж��Ƿ�Ϊ������
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
                {    //�ж��Ƿ�Ϊ������
						return num1;
			}
			if (inPriority(op.top()) == 3)
                {
				num.pop();
				op.pop();
				return dealNum(num1, num2, op1);
			}
			if (inPriority(op1)>inPriority(op.top()))
                {    //�ж����ȼ�������
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
                {        //ѭ�����룬����ֱ�ӹرռ���
				string station;
				cout << "������ʽ�� " << endl;
				cin>>station;
				dealString(station);
				cout << "���Ϊ�� " << cal() << endl << endl;
				}
	}
