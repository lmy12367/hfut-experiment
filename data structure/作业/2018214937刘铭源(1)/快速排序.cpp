#include<iostream>
#include<Windows.h>
#include<fstream>
#pragma comment(lib,"winmm.lib")
#include<cstdlib>
using namespace std;
int pp(int *arr,int left,int right)
{
	int temp=arr[left];
	while(left<right)
	{
		while(left<right && arr[right]>=temp)
		{
			right--;
		}
		arr[left]=arr[right];
		while(left<right && arr[left]<=temp)
		{
			left++;
		}
		arr[right]=arr[left];
		
	}
	arr[left]=temp;
	return left;
}
void quick(int *arr,int left,int right){
	if(left<right)
	{
		int pi=pp(arr,left,right);
		quick(arr,left,pi-1);
		quick(arr,pi+1,right);
	}
}
void quicksort(int *arr,int len)
{
	quick(arr,0,len-1);
}
int main()
{
	fstream inout;
	inout.open("数据.txt",ios::out);
	int arr[500000];
	for(int i=0;i<500000;i++)
	{
		arr[i]=rand();
		inout<<arr[i]<<" ";
	 } 
	inout.close();
	inout.open("数据.txt",ios::in);
	DWORD start, end;
	int len=sizeof(arr)/sizeof(arr[0]);
	start=GetTickCount();
	quicksort(arr,len);
	end=GetTickCount()-start;
	for(int k=0;k<len;++k)
	{
		if(k%10==0)
		{
			cout<<endl;
		}
		cout<<arr[k]<<"  ";
	}
	cout<<"排序时间"<<end<<endl;

	return 0;
}
 
