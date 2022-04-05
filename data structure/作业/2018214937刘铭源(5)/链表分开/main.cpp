#include<iostream>
#include<stdlib.h>
#include"head.h"
#include<ctime>
using namespace std;
int main()
{	time_t begin,end;
	double ret;
	begin=clock();
	link_queue s1,s2,s3;
	node * s,* t,*z;
	int i;
	for(i = 0;i < 500; i++)
	{
		s1.append(rand()%500);
	}
		for(i = 0;i < 500; i++)
	{
		s2.append(rand()%500);
	}
		t = s1.sort_fast(s1.front->next);
		s = s2.sort_fast(s2.front->next);
		z = s3.merge(t,s);
	
	for(i = 0;i<1000;i++)
	{
		cout << z ->date << "  ";
		z = z ->next;
	}
		end=clock();
	ret=double (end-begin)/CLOCKS_PER_SEC;
	cout<<endl;
	cout<<ret;
	return 0;
}
