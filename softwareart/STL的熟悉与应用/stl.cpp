#include<vector>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{	clock_t start,end;
	start=clock();
    vector<int> array1;
    vector<int>::iterator it1;
    vector<int>::iterator ip;
    srand(time(0));
    for(int i = 0;i < 10; i++)
    {
        array1.push_back(rand()%100);
    }

   for(it1 = array1.begin(); it1!= array1.end(); it1++)
   {
       cout <<*(it1)<<" ";
   }

  cout <<endl;
  array1.insert(array1.begin(),rand());
   for(it1 = array1.begin(); it1!= array1.end(); it1++)
   {
       cout <<*(it1)<<" ";
   }
    cout <<endl;

   int x = rand()%100;
   ip=find(array1.begin(),array1.end(),x);
   if(*ip!=x)
   {
   		cout<<"no,没有找到"<<endl; 
       array1.insert(array1.end(),x);
   }

else
   cout<<"YES，找到了"<<*ip<<endl;
  
 sort(array1.begin(),array1.end());
 for(it1 = array1.begin(); it1!= array1.end(); it1++)
   {
       cout <<*(it1)<<" ";
   }
   cout <<endl;
 
   array1.pop_back();
    for (it1 = array1.begin(); it1 != array1.end(); it1++)
    {
        cout << *it1 << " ";
    }
     cout <<endl;
    array1.clear();
    cout <<"清空完成"<<endl;
    end=clock();
	cout<<"time"<<end-start<<"ms"<<endl;
	system("Pause");
    return 0;
}
