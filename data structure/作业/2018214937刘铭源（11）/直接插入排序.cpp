#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <time.h>
using namespace std;
clock_t begin_1,end_1,begin_2,end_2,begin_3,end_3,begin_4,end_4,begin_5,end_5,begin_6,end_6;
double time_length1,time_length2,time_length3,time_length4,time_length5,time_length6;

/*double time(fuction())
{
	clock_t begin,end;
	double time_length;
	begin=clock();
	fuction();
	end=clock();
	time_length = (double)(end-begin)/CLOCKS_PER_SEC;
    return time_length;
	
}*/
void InsertSort(int a[],int len)//直接插入排序 
{
    int i,j;
    int tmp;
	for(i=0;i<len;i++)
    {
        tmp=a[i];
        j=i-1; //从右向左在有序区找到插入位置
        while(j>=0&&tmp<a[j])
        {
           	a[j+1]=a[j]; //元素后移
            j--;
        }
        a[j+1]=tmp; //在j+1处插入a[i];
        
    }
	for(i=0;i<len;i++)
    {
        cout<<a[i]<<" ";
	}
		
	cout<<endl;
    }

void shellInsert(int a[],int n)//希尔排序 
{
    int i,j,gap;
    int tmp;
    gap=n/2;
    while(gap>0)
    {
        for(i=gap;i<n;i++)
         {
            tmp=a[i];
            j=i-gap;
            while(j>0&&tmp<a[j])
            { 
                a[j+gap]=a[j];
                j=j-gap;
            }
            a[j+gap]=tmp;
        }
        gap=gap/2;
    }
    for(i=0;i<n;i++)
        {
        	cout<<a[i]<<" ";
		}
		
	cout<<endl;
}

void BubbleSort(int* a, int n)//冒泡排序
{
    int i ,j;
    int tmp;
    for (i = 0; i < n- 1; i++)
    {
        for (j = n-1; j >i; j--)
        {
            if (a[j] <a [j -1])
            {
                tmp = a[j];
                a[j] = a[j -1];
                a[j -1] = tmp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
    	cout<<a[i]<<" ";
	}
	
	cout<<endl;
}


void SelectSort(int a[], int n) //直接选择排序 
{
    int i, j, k;
    int tmp;
    for (i = 0; i < n - 1; i++) 
	{
        k = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[k])
             k = j;
        if (k!= i)
		 {
            tmp = a[i];
            a[i] = a[k];
            a[k] = tmp;
         }
    }
    for(int i=0;i<n;i++)
    {
    	cout<<a[i]<<" ";
	}
	cout<<endl;
}

void sift(int a[],int low ,int high)
{
    int i=low,j=2*i; 			//a[j] 是a[i]的左孩子
    int tmp=a[i]; 
    while(j<=high)
    {
        if(j<high&&a[j]<a[j+1])       //若右孩子较大，把j指向右孩子
            j++;
        if(tmp<a[j])
        {
            a[i]=a[j];			  //将a[j]调整到双亲节点
            i=j;                         	     //修改值，以便继续向下筛选
            j=2*i;
        }
        else
            break;
     }
    a[i]=tmp;
}
 
void heapsort(int a[],int n)//堆排序 
{
    int i;
    int tmp;
    for(i=n/2;i>=0;i--)
        sift(a,i,n);     				//循环建立初始堆
    for(i=n-1;i>=1;i--)			     // 进行n-1趟排序，每次排序元素减一
    {	
        tmp=a[0];     				//将最后一个元素同当前区间内的a[1]交换
        a[0]=a[i];
        a[i]=tmp;
        sift(a,0,i-1);				//筛选a[1]节点，得到i-1个节点的堆
    }
    for(int i=0;i<n;i++)
    {
    	cout<<a[i]<<" ";
	}
	cout<<endl;
}


void QuickSort(int a[], int left, int right)
{
	int i = left; 
	int j = right;
	if(i > j)
		return;
	int temp = a[left];
	while(i != j)
	{
		while(a[j] >= temp && i < j)
			j--;
		while(a[i] <= temp && i < j)
			i++;
		if(i < j)
			swap(a[i], a[j]);
	}
	//将基准temp放于自己的位置，（第i个位置）
	swap(a[left], a[i]);
	QuickSort(a, left, i - 1);
	QuickSort(a, i + 1, right);
	
}

int main()
{
	ofstream outFlie;
	outFlie.open("suijishu.txt");
	int i,j,N;
	cout<<"please input a number:";
	cin>>N; 
	srand ( (unsigned)time(NULL));
	for(i=0;i<N;i++)
	{
		j=rand() % N;
		outFlie<<j<<"  ";	
	}
	outFlie.close();
		
	ifstream fin; 
	fin.open("suijishu.txt");
	int num;
	int a[N];
	int k=0;
	while(!fin.eof() )
	{	  
		fin>>num;
		if(fin.eof()) break;
		a[k]=num;
		k++;
	
	}
	fin.close()	;
	cout<<endl;
	
	//int a[5]={2,3,1,9,7};
	begin_1=clock();
	InsertSort(a,N);
	end_1=clock();
	time_length1 = (double)(end_1-begin_1)/CLOCKS_PER_SEC;
	cout<<"直接插入排序："<<time_length1<<"second."<<endl;
	
	begin_2=clock();
	shellInsert(a,N);
	end_2=clock();
	time_length2 = (double)(end_2-begin_2)/CLOCKS_PER_SEC;
	cout<<"希尔排序："<<time_length2<<"second."<<endl;
	
	begin_3=clock();
	BubbleSort(a,N);
	end_3=clock();
	time_length3 = (double)(end_3-begin_3)/CLOCKS_PER_SEC;
	cout<<"冒泡排序："<<time_length3<<"seconds."<<endl;
	
		
	begin_4=clock();
	SelectSort(a,N);
	end_4=clock();
	time_length4 = (double)(end_4-begin_4)/CLOCKS_PER_SEC;
	cout<<"选择排序："<<time_length4<<"seconds."<<endl;
	
	begin_5=clock();
	heapsort(a,N);
	end_5=clock();
	time_length5 = (double)(end_5-begin_5)/CLOCKS_PER_SEC;
	cout<<"堆排序："<<time_length5<<"seconds."<<endl;
	
	begin_6=clock();
	QuickSort(a,0,N-1);
	for(int i=0;i<N;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	end_6=clock();
	time_length6 = (double)(end_6-begin_6)/CLOCKS_PER_SEC;
	cout<<"快速排序："<<time_length6<<"seconds."<<endl;
	
	return 0;
}
