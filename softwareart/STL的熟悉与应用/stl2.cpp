#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
    vector<int> array1;//����һ��vector
    vector<int>::iterator it;
    vector<int>::iterator ip;
    srand(time(0));
    for(int i =0; i < 10;i++)//���� 10 �������
    {
        array1.push_back(rand()%100);
    }
    /***************************************************************/
    sort(array1.begin(),array1.end());//ʹ�� sort ������������� ÿ��Ԫ�ص�ֵ
    for(it =array1.begin();it !=array1.end();it++ )
    {
        cout <<*it<<" ";
    }
    cout <<endl;

    sort(array1.begin(),array1.end(),greater<int>());//ʹ�� sort ������������� ÿ��Ԫ�ص�ֵ
      for(it =array1.begin();it !=array1.end();it++ )
    {
        cout <<*it<<" ";
    }
    /****************************************************************/
    int x = rand()%100;
   ip=find(array1.begin(),array1.end(),x);//���÷����㷨 find ����ĳ�������
   if(*ip!=x)
       cout<<"NO"<<endl;

else
       cout<<"YES"<<endl;
/******************************************************************/
    int min = array1[0];//�� min �� max �ҳ������е�СԪ�ظ���Ԫ�أ��������
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
