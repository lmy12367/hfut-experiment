#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int n,a[21];
void print()				//��ӡ����
{int i=1;

	for(;i<=n;i++)
		cout<<a[i];
	   cout<<" ";
	if(i%7==0)
       cout<<endl;

}

int Try(int x,int y)			//����x��y�пɷ�ڷ����ӣ��ɹ�����1�����򷵻�0

{

	int j=1;
	while(j<x)					//���������ѷźõ����Ƚ�
	{if((a[j] == y) || (abs(x-j) == abs(a[j]-y)))

			return 0;

		j++;					//����һ���������

	}

	return 1;

}
void place(int x)				//�ݹ麯��
{
	int y;
	if(x>n)						//���ӵ�n���Ѱںã����ӡ�ɹ�����
	{
		print();

	}
	else

	{

		for(y=1;y<=n;++y)		//�����������δ���������
         if(Try(x,y))		//������԰ڷ�

			{
				a[x]=y;			//��a[x]��ֵ
				place(x+1);		//������һ�еĵݹ�
			}
	}

}
int main()

{

	cin>>n;
	place(1);			//�ӵ�1�п�ʼ�ݹ�
	return 0;

}

