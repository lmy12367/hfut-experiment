#include <iostream>
#include<stack>
using namespace std;

void Fact(int n)
{
    if(n > 0)
       {
          Fact(n-1);
          cout <<n;
          Fact(n -1);
       }
}

void Fact1(int n)
{
   stack<int> s;
      L0:
       if(n > 0)
       {
           s.push(n);
           n = n - 1;
           goto L0;
           L1:
             cout <<n;
             n = n - 1;
             goto L0;

       }
          if ( !s.empty() )
            {
             n = s.top();
             s. pop();
            goto L1;
          }
 }


 void Fact2(int n)
 {
     stack<int> s;




     while(n > 0)
     {
        s.push(n);
        n = n - 1;
     }
     while(!s.empty())
     {
         n = s.top();
         s. pop();
        cout <<n;
        n = n - 1;
        while(n > 0)
        {
             while(n > 0)
       {
          s.push(n);
          n = n - 1;
       }

        }


     }




 }










int main()
{
        Fact(6);
        cout <<endl;
        Fact1(6);
        cout <<endl;
        Fact2(6);
    return 0;
}
