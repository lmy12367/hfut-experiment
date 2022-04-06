#include<iostream>
#include<list>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	clock_t start,end;
	start=clock();
    list<int> l;
    list<int>::iterator it1;
    list<int>::iterator ip;
    srand(time(0));
    for(int i = 0;i < 10; i++)
    {
        l.push_back(rand()%100);
    }

   for(it1 = l.begin(); it1!= l.end(); it1++)
   {
       cout <<*(it1)<<" ";
   }

  cout <<endl;
    l.insert(l.begin(),rand());
   for(it1 = l.begin(); it1!= l.end(); it1++)
   {
       cout <<*(it1)<<" ";
   }
    cout <<endl;
     int x = rand()%100;
   ip = find(l.begin(),l.end(),x);
   if(*ip!=x)
   {
       l.insert(l.end(),x);
   }

else
   cout<<"YES"<<*ip<<endl;
   l.sort();
 for(it1 = l.begin(); it1!= l.end(); it1++)
   {
       cout <<*(it1)<<" ";
   }
   cout <<endl;
    l.pop_back();
    for (it1 = l.begin(); it1 != l.end(); it1++)
    {
        cout << *it1 << " ";
    }
     cout <<endl;

     l.clear();
    cout <<"Çå¿ÕÍê³É"<<endl;
	end=clock();
	cout<<"time"<<end-start<<"ms"<<endl;
	system("Pause");

    return 0;
}
