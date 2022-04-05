#include <iostream>
#include "yanghui.h"

using namespace std;

void Out_Number(int n)
{
    int s1,s2;
    _queue Q;
    for( int i = 0; i < n;i++)
        cout<<" ";
    cout<<1<<endl;
    Q.append(1);
    for(int i = 2;i <= n;i++)
    {
        s1 = 0;
    for( int k = 0 ;k < n - i +1;k++)
        cout<<" ";
        for(int j = 1;j <= i-1 ; j++)
        {
            Q.get_front(s2);
            Q.serve();
            cout<<s1+s2;
            cout<<" ";
            Q.append(s1+s2);
            s1 = s2;
        }
        cout<<1<<endl;
        Q.append(1);
    }
}

int main()
{
    int x;
    cin>>x;
    Out_Number(x);
}

