#include <iostream>
#include"node.h"
int getx(node a1 ,node a2, node a3, node a4);
bool whether(node a1, node a2, node a3, node a4);
using namespace std;
int main()
{
   int  x1,x2,x3,x4,y1,y2,y3,y4;
    node a1;
    node a2;
    node a3;
    node a4;
    cout <<"请输入两条线段端点的坐标："<<endl;
    cout <<"第一条线段的坐标：";
    cin >>x1>>y1>>x2>>y2;
    a1.n_set(x1,y1);
    a2.n_set(x2,y2);
    cout <<"第二条线段的坐标：";
    cin >>x3>>y3>>x4>>y4;
    a3.n_set(x3,y3);
    a4.n_set(x4,y4);
    bool m;
    m = whether( a1, a2,  a3,  a4);
    if(m)
      cout <<"有交点"<<endl;
      else
        cout <<"无交点"<<endl;

    return 0;
}
int getx(node a1 ,node a2, node a3, node a4)
{
   int m1, n1,m2,n2,m3,n3;
    m1 = a1.x - a2.x;
    m2 = a1.x - a3.x;
    m3 = a1.x - a4.x;
    n1 = a1.y - a2.y;
    n2 = a1.y - a3.y;
    n3 = a1.y - a4.y;
    //cout << ((m1*n2 - n1*m2) * (m1*n3 - n1*m3))<<endl;
     return ((m1*n2 - n1*m2) * (m1*n3 - n1*m3));

}


bool whether(node a1, node a2, node a3, node a4)
{
    int i , j;
    i = getx(a1,a2,a3,a4);
    j = getx(a3,a4,a1,a2);
    if((i <= 0) &&(j <= 0))
        return true ;
    else
       return false;


}

