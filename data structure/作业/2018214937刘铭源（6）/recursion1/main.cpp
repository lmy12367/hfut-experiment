#include <iostream>
#include<stack>

using namespace std;

stack<int> b;
int Fact(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return (n*Fact(n-1));
    }
}
void n_Fact(int n)
{
    stack<int> a;
    int num = 1;
    L0:
        if(n > 0)
        {
           a.push(n);
           num = num * n;
           n = n - 1;
           goto L0;
           L1:
               ;

        }
        if( !a.empty())
        {
            a.pop();
            goto L1;

        }
        cout <<num<<endl;

}

void nn_fact(int n)
{
    int num = 1;
     for(;n!=0;n--)

      {

             num = num *n;
       }


    cout <<num<<endl;
}
int main()

{
    cout <<Fact(10)<<endl;
    n_Fact(10);
   nn_fact(10);
   return 0;
}
