#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
using namespace std;
#define MAX_VERTEX_NUM 26
typedef struct ArcNode{
        int adjvex;
        struct ArcNode *nextarc;
        ArcNode(){nextarc=NULL;}
        }ArcNode;
typedef struct VNode{
        int data;
        ArcNode *firstarc;
        VNode(){firstarc=NULL;}
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct{
        AdjList vertices;
        int vexnum,arcnum;
}ALGraph;
bool TopologicalSort(ALGraph G,int *indegree)
{
        stack<int> s;
        int i,k;
        for(i=1;i<G.vexnum+1;i++)
         {
                if(!indegree[i])
                        s.push(i);
        }
        int count=0;
        ArcNode *p;
        while(!s.empty())
        {
                i = s.top();
                s.pop();
                cout<<G.vertices[i].data<<"->";
                count++;
                for(p=G.vertices[i].firstarc;p;p=p->nextarc)
                {
                	 k = p->adjvex;
                     indegree[k]--;
                     if(!indegree[k])
                        s.push(k);
                }
        }
        if(count<G.vexnum)

                return false;
        return true;
}
int main()
{
        int i;
        ALGraph g;
        cout<<"载入图中..."<<endl;
        ifstream fin("in.txt");
        fin>>g.vexnum>>g.arcnum;
        for(i=1;i<g.vexnum+1;i++)
                g.vertices[i].data = i;
        int b,e;
        ArcNode *p;
        int *indegree = new int[g.vexnum+1];
        memset(indegree,0,sizeof(int)*(g.vexnum+1));
        for(i=1;i<g.arcnum+1;i++)
        {
        	fin>>b>>e;
                cout<<"第"<<i<<"条边："<<b<<"->"<<e<<endl;
                p = new ArcNode();
                p->adjvex = e;
                p->nextarc = g.vertices[b].firstarc;
                g.vertices[b].firstarc = p;
                indegree[e]++;
        }
        if(TopologicalSort(g,indegree))
                cout<<"正常完成！"<<endl;
        else
        cout<<"该有向图有回路！"<<endl;

        return 0;
}
