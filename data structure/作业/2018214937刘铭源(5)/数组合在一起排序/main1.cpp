#include<iostream> 
#include<stdlib.h>
#include<ctime>
using namespace std;
void BubbleSort(int arr[], int n);
int main()
{
	int num_1[500]; 
	int num_2[500];
	int num_3[1000];
	int i;
	for(i = 0; i < 500;i++)
	{
		num_1[i] = rand()%1000;
	}
	for(i = 0; i < 500;i++)
	{
		num_2[i] = rand()%1000;
	}
	for(i = 0;i < 500;i++)
	{
		num_3[i] = num_1[i];
	}
		for(i = 0;i < 500;i++)
	{
		num_3[i+500] = num_1[i];
	}
	time_t begin,end;
	double ret;
	begin=clock();
	BubbleSort(num_3,1000);
	end=clock();
	ret=double (end-begin)/CLOCKS_PER_SEC;
	cout<<ret;	
	
}
void BubbleSort(int arr[], int n)//Ã°ÅÝÅÅÐò 
{
    for (int i = 0; i < n - 1; i++)
		{
		    for (int j = 0; j < n - i - 1; j++)
				{
					if (arr[j] > arr[j + 1])
						{
							 int temp = arr[j];
							arr[j] = arr[j + 1];
							arr[j + 1] = temp;
						}                 
				}         
		}
}

