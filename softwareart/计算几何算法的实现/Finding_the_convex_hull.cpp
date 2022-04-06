#include <iostream>
#include <utility>
#include <vector>
#include<ctime>
#include <algorithm>
using namespace std;
typedef pair<double, double> Point;
Point startPoint;
double direction(Point a, Point b, Point c)
{
        Point a1,a2;
        a1.first =c.first -a.first ;
        a1.second=c.second-a.second;
         a2.first =b.first -a.first;
         a2.second=b.second-a.second;
        return (a1.first*a2.second-a1.second*a2.first);
}
bool on_segment(Point a, Point b, Point c)
{
    double min_x,max_x,min_y,max_y;
    if(b.first<c.first)
    {
        min_x = b.first;
        max_x = c.first;
    }
    else
    {
         min_x = c.first;
        max_x = b.first;
    }

    if(b.second<c.second)
    {
        min_y = b.second;
        max_y = c.second;
    }
    else
    {

        min_y = c.second;
        max_y = b.second;
    }
     if (a.first >=min_x && a.first <=max_x && a.second>=min_y && a.second<=max_y)
        return true;
     else
        return false;


}
bool sortByPolorAngle(const Point &a1, const Point &a2)
{     double d=direction(  startPoint,  a1,  a2);
         if (d<0)
            return true;
        else if (d>0)
            return false;
         else if (d==0 && on_segment(startPoint, a1, a2) )
           return true;
         else if (d==0 && on_segment(a2,startPoint,a1) )
            return true;
        else
         return false;
}
void find_convex_hull(vector<Point> & point)
 {     Point p0=point[0];
        int k=0;
         for (int i=1;i<point.size();i++)
            {
               if (point[i].second<p0.second || point[i].second==p0.second && point[i].first<p0.first)
                           {
                                p0=point[i];
                                    k=i;
                           }
            }

            point.erase(point.begin()+k);
              point.insert(point.begin(),p0);
                 vector<Point> convex_hull;
                  do {
                        convex_hull.push_back(point[0]);
                         startPoint=point[0];
                          point.erase(point.begin());
                        sort(point.begin(),point.end(),sortByPolorAngle);
                        if (point[0]==convex_hull[0])
                            break;
                        point.push_back(convex_hull[convex_hull.size()-1]);
                         } while (1);
            for (int i=0;i<convex_hull.size();i++)
                {
                     cout<<convex_hull[i].first<<' ' <<convex_hull[i].second<<endl;
                 }
 }
int main()
{
	clock_t start,end;
	start=clock();
   vector<Point> a;
    for(int i = 0; i < 10;i++)
    {
        int x,y;
        cout <<"请输入点的坐标:";
        cin>>x>>y;
        Point  b;
         b.first = x;
         b.second = y;
         a.push_back(b);

    }
    find_convex_hull(a);
	end=clock();
	cout<<"time"<<end-start<<"ms"<<endl;
	system("Pause");
    return 0;
}
