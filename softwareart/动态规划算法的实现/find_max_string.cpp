#include<iostream>
#include<string>
using namespace std;

void find_max(string s1, string s2)
{
    bool have = false;
    int a[100][100];
    int maxe[1][2];
    maxe[0][0] = 0;
    maxe[0][1] = 0;
    int temple;
       temple=0;
    for(int i = 0; i < s1.size(); i++)
    {
        for(int j = 0; j < s2.size(); j++)
       {
           a[i][j] = 0;
       }
    }
     for(int i = 0; i < s1.size(); i++)
    {
        for(int j = 0; j < s2.size(); j++)
       {
          if(s1[i] == s2[j])
            a[i][j] = 1;
       }
    }
     for(int i = 0; i < s1.size(); i++)
    {
        for(int j = 0; j < s2.size(); j++)
       {
          if(a[i][j] == 1)
             have = true;
       }
    }

    if(have==false)
    {
        cout <<"û��������"<<endl;
    }
    else
    {
        for(int i = 0; i < s1.size(); i++)
      {

         for(int j = 0; j < s2.size(); j++)
       {
            if(a[i][j] == 1)
                 {
                     int m,n;
                     m = i;
                     n = j;
                     do
                     {
                        temple ++;
                        m++;
                        n++;
                     }while(a[m][n]==1);
                     if(maxe[0][0] < temple)
                     {
                         maxe[0][0] = temple;
                         maxe[0][1] = i;
                     }
                     temple = 0;
                 }
       }
    }

    for (int k = 0; k < maxe[0][0];k++)
    {
        cout <<s1[maxe[0][1] + k]<<" ";
    }

    }




}

int main()
{
    //�涨�ַ����ĳ��Ȳ�����100
    string s1;
    string s2;
    cout <<"�����������ַ���"<<endl;
    cout <<"��һ���ַ�����";
     cin>>s1;
     cout <<"�ڶ����ַ�����";
     cin>>s2;
    find_max(s1,s2);


}
