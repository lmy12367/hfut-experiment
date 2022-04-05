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
	int i,j,k;
	for(i = 0; i < 500;i++)
	{
		num_1[i] = rand()%1000;
	}
	for(i = 0; i < 500;i++)
	{
		num_2[i] = rand()%1000;
	}
	time_t begin,end;
	double ret;
	begin=clock();
	BubbleSort(num_1,500);
	BubbleSort(num_2,500);
	for(i = 0,j = 0,k = 0;i < 1000;i++)
	{
		if(num_1[j] < num_2[k])
		{
			num_3[i] = num_1[j];
			j++;
		}
		else
		{
			num_3[i] = num_2[k];
			k++;
		}
	}
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

