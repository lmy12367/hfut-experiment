#include<iostream>
#include<string>
#include<ctime>
using namespace std;
int mine(int x1,int x2, int x3); 
void change(string s1, string s2);
int main()
{	clock_t start,end;
	start=clock();
    string s1, s2;
    cout <<"ÇëÊäÈë×Ö·û´®a£º";
    cin>>s1;
    cout <<endl;
    cout <<"ÇëÊäÈë×Ö·û´®b£º";
    cin>>s2;
    cout <<endl;
    change(s1,s2);
	end=clock();
	cout<<"time"<<end-start<<"ms"<<endl;
	system("Pause");
    return 0;
}
int mine(int xx1,int xx2, int xx3)
{
    int tt1, tt2;
    tt1 = min(xx1,xx2);
    tt2 = min(tt1,xx3);
    return tt2;
}
void change(string s1, string s2)
{
     const char* n_s1 = s1.c_str();
     const char* n_s2 = s2.c_str();
     int temple;
    int b[100][100];
    for(int i = 0; i < s1.length(); i++)
        b[0][i] = i;
    for(int j = 0; j< s2.length(); j++)
        b[j][0] = j;
    for(int k = 1; k <= s1.length() ; k++)
        for(int m = 1; m <=s2.length(); m++)
    {
        if( n_s1[k-1] == n_s2[m-1])
            b[k][m] = b[k-1][m-1];
        else
           {
               temple = mine((b[k-1][m-1]),(b[k][m-1]),(b[k-1][m]));
             b[k][m] = temple +1 ;
           }
    }

    cout <<"yes,ÐèÒª"<<(b[(s1.length() )][(s2.length() )])<<"²½"<<endl;
    for(int l =0; l < s1.length(); l++)
    {
        for(int n = 0; n < s2.length(); n++)
        {
            cout << b[l][n]<<" ";
        }
        cout <<endl;
    }

}
