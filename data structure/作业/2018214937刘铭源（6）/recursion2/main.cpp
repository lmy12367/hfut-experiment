#include <iostream>
#include<stack>

using namespace std;

int Fact(int n)
{
    if(n < 3)
    {
        return n;
    }
    else
    {
        return (Fact(n - 1) + Fact(n - 2));
    }
}


void Fact1(int n)
{stack<int> a;

        if(n <3)
        {
            a.push(n);
        }
        else
        { a.push(1);
            a.push(2);
         L0:


            int x = (a.top());
            a.pop();
            int y = (a.top());
            a.push(x);
            a.push(x+y);
            n = n - 1;
            if(n > 2)
             goto L0;
        }

        cout <<a.top()<<endl;
       L1:


    if ( !a.empty() )
    {
      a.pop();
      goto L1;
  }



}

void Fact2(int n)
{
    stack<int> a;
      if(n <3)
        {
            a.push(n);
        }
     else
        { a.push(1);
            a.push(2);

         while(n> 2)
         {
            int x = (a.top());
            a.pop();
            int y = (a.top());
            a.push(x);
            a.push(x+y);
            n = n - 1;
         }
        }

        cout <<a.top()<<endl;

    while( !a.empty() )
    {
      a.pop();

    }
}

int main()
{

     cout <<Fact(5)<<endl;
     Fact1(5);
         Fact2(5);
    return 0;
}
