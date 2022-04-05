#include<iostream>
#include<stdlib.h>
#include"head.h"
#include<ctime>
using namespace std;
int main()
{
	time_t begin,end;
	double ret;
	begin=clock();
	link_queue s1,s2,s3;
	node * s,* t;
	int i;
	for(i = 0;i < 500; i++)
	{
		s1.append(rand()%500);
	}
		for(i = 0;i < 500; i++)
	{
		s2.append(rand()%500);
	}
	s = s1.front;
	for(i = 0;i < 500; i++)
		s = s->next;
	s ->next = s2.front->next;

	s3.sort_fast(s);
	for(i = 0;i<1000;i++)
	{
		cout << s ->date << "  ";
		s = s ->next;
	}
	end=clock();
	ret=double (end-begin)/CLOCKS_PER_SEC;
	cout<<endl;
	cout<<ret;
	return 0;
}
