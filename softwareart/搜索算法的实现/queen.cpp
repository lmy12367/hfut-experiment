#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int n,a[21];
void print()				//打印棋子
{int i=1;

	for(;i<=n;i++)
		cout<<a[i];
	   cout<<" ";
	if(i%7==0)
       cout<<endl;

}

int Try(int x,int y)			//测试x行y列可否摆放棋子，成功返回1，否则返回0

{

	int j=1;
	while(j<x)					//与数组中已放好的数比较
	{if((a[j] == y) || (abs(x-j) == abs(a[j]-y)))

			return 0;

		j++;					//右移一格继续尝试

	}

	return 1;

}
void place(int x)				//递归函数
{
	int y;
	if(x>n)						//棋子第n行已摆好，则打印成功方案
	{
		print();

	}
	else

	{

		for(y=1;y<=n;++y)		//该行棋子依次从左向右移
         if(Try(x,y))		//如果可以摆放

			{
				a[x]=y;			//给a[x]赋值
				place(x+1);		//继续下一行的递归
			}
	}

}
int main()

{

	cin>>n;
	place(1);			//从第1行开始递归
	return 0;

}

