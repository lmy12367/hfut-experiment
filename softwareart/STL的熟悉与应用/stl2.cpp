#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
    vector<int> array1;//定义一个vector
    vector<int>::iterator it;
    vector<int>::iterator ip;
    srand(time(0));
    for(int i =0; i < 10;i++)//插入 10 个随机数
    {
        array1.push_back(rand()%100);
    }
    /***************************************************************/
    sort(array1.begin(),array1.end());//使用 sort 按升序排序，输出 每个元素的值
    for(it =array1.begin();it !=array1.end();it++ )
    {
        cout <<*it<<" ";
    }
    cout <<endl;

    sort(array1.begin(),array1.end(),greater<int>());//使用 sort 按降序排序，输出 每个元素的值
      for(it =array1.begin();it !=array1.end();it++ )
    {
        cout <<*it<<" ";
    }
    /****************************************************************/
    int x = rand()%100;
   ip=find(array1.begin(),array1.end(),x);//。用泛型算法 find 查找某个随机数
   if(*ip!=x)
       cout<<"NO"<<endl;

else
       cout<<"YES"<<endl;
/******************************************************************/
    int min = array1[0];//用 min 和 max 找出容器中的小元素个大元素，并输出。
    int max = array1[0];
      for(it =array1.begin() +1 ;it !=array1.end();it++ )
    {
        if(min > *it)
            min = *it;
         if(max < *it)
            max = *it;

    }
    cout <<min<<endl;
    cout <<max<<endl;

    return 0;
}
