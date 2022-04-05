#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int ShortestPathvalue[32][32]={0};//存储最短路径值
int ShortestPathmatrix[32][32]={0};//存储具体路径
char _mapName[32][50]={"科教楼","东风广场","1号楼","3号楼",
"5号楼","7号楼","9号楼","11楼","西操场","建筑艺术学院","图书馆",
"1教","3教","5教","7教","9教","11教","网球场","篮球场","风雨操场",
"体育馆","东操场","生物基础实验室","第一食堂","注册中心",
"校医院","教育超市","北大门","小北门","西门","健身馆","食品与工程学院"};
int _distance[32][32]={0};//距离信息，distance[0][1]
//边信息
typedef struct EdgeNode
{
	//顶点下标
	int adjvex;
	//权值
	int weight;
	//指向下一个邻接点
	struct EdgeNode *next; 
 } edgenode;
 //顶点表结点
 typedef struct VertexNode
 {
 	//顶点数据
	 char data[50];
	 //边表头指针
	 EdgeNode *firstedge; 
  } VertexNode, AdjList[100];
 //集合 
 typedef struct
 {
 	AdjList adjList;
 	int numVertexes,numEdges;//顶点和边数 
 }GraphAdjList;
 class AdjacencyList
 {
 	public:
 		void ShowALGraph(GraphAdjList *G);
 		void Test();
    //初始化地图
    	void InitMap(GraphAdjList *G);
    //创建地图
   		void CreateALGraph(GraphAdjList *G);
   		//计算各个顶点之间最短路径
   		void ShortestPath_Floyd(GraphAdjList *G, int P[32][32], int D[32][32]);
   		//输出路径长度和具体路径
    	void ShowShortestResult(int originPos,int endPos);
  } ;
void AdjacencyList::CreateALGraph(GraphAdjList *G) 
{
	EdgeNode *e;
	//读入顶点信息，建立顶点表
	 for (int i = 0; i < G->numVertexes; i++)
	 {
	  //读入顶点信息
        strcpy(G->adjList[i].data, _mapName[i]);
        //将边表置为空表
        G->adjList[i].firstedge = NULL;
	}
	//建立边表（头插法）
	for (int i = 0; i < G->numVertexes; i++)
    {
        for (int j = 0; j < i; j++)
        {
        	int temp;
            if (_distance[i][j] != 0 || _distance[j][i] != 0)
            {
            	if(_distance[i][j] != 0)
            	{
				temp = _distance[i][j];
                _distance[j][i] = _distance[i][j];
            	}
				else
            	{ 
                temp = _distance[j][i];
                _distance[i][j] = _distance[j][i];

            	}
				e = new EdgeNode;
            	e->adjvex = j;
				e->next = G->adjList[i].firstedge;
				e->weight = temp;
                G->adjList[i].firstedge = e;
                e = new EdgeNode;
                e->adjvex = i;
                e->next = G->adjList[j].firstedge;
                e->weight = temp;
                G->adjList[j].firstedge = e;
            }  
		}
	} 
}
void AdjacencyList::Test(){
	cout<<"欢迎使用本系统"<<endl; 
}
void AdjacencyList::ShowALGraph(GraphAdjList *G) {
    for (int i = 0; i < G->numVertexes; i++)
    {
    	cout << "顶点" << i << ": " << G->adjList[i].data << "--firstedge--";
        EdgeNode *p = new EdgeNode;
        p = G->adjList[i].firstedge;
        while (p)
        {
            cout << p->adjvex << "--Weight: " << p->weight << "--Next--";
                        p = p->next;
        }
        cout << "--NULL" << endl;
    }
}
//初始化地图基本数据
void AdjacencyList::InitMap(GraphAdjList *G) {
	//输入顶点数和边数
    G->numVertexes = 32;
    G->numEdges = 59;
    _distance[0][2] = 600;
    
    _distance[1][2] = 300;
    _distance[1][7] = 3100;
    _distance[1][6] = 2500;
    
    _distance[2][7] = 2600;
    _distance[2][16] =3600;
    _distance[2][3] = 200;
    
    _distance[3][7] = 2000;
    _distance[3][14] =4000;
    _distance[3][4] = 200;
    
    _distance[4][11] =1500;
    _distance[4][8] = 3500;
    _distance[4][5] = 200;
     
	_distance[5][9] = 3500;
	
	_distance[6][7] = 200;
	_distance[6][10] = 3500;
	
	_distance[7][10] = 4000;
	_distance[7][14] = 2560;
	_distance[7][16] = 3000;
	
	_distance[8][11] = 2000;
    _distance[8][9] = 3000;
    
    _distance[9][11] = 1000;
    
    _distance[10][17] = 6000;
    _distance[10][13] = 4500;

    _distance[11][16] = 3000;
    _distance[11][12] = 300;

	_distance[12][16] = 2000;
    _distance[13][17] = 6000;
    _distance[13][18] = 6500;
    _distance[13][15] = 2500;
    _distance[13][14] = 300;
    
    _distance[14][15] = 300;
    _distance[14][16] = 600;
 
 	_distance[15][18] = 3400;
    _distance[15][20] = 4000;
    _distance[15][21] = 5000;
	
	_distance[16][21] = 4000;
    _distance[16][23] = 1400;
    _distance[17][25] = 3000;
    _distance[17][18] = 500;
    
    _distance[18][26] = 3000;
    _distance[18][19] = 1000;
    _distance[19][20] = 1500;
    _distance[20][21] = 1000;

    _distance[20][22] = 4000;
    _distance[20][27] = 500;
    _distance[20][28] = 5000;
    _distance[21][22] = 4000;
 
 	_distance[22][29] =8000;
    _distance[22][30] = 5000;
    _distance[22][24] = 5000;
    _distance[23][24] = 500;
    
    _distance[24][30] = 400;
    _distance[25][26] = 800;
    _distance[26][27] = 800;
    _distance[28][29] = 800;


    _distance[29][31] = 7000;
    _distance[29][30] = 8000;
    _distance[30][31] = 11000;
}
void AdjacencyList::ShortestPath_Floyd(GraphAdjList *G, int P[32][32], int D[32][32])
{
	//初始化d与p
	for(int v = 0; v < G->numVertexes; ++v)
    {
        for (int w = 0; w < G->numVertexes; ++w)
        {
        	 if(_distance[v][w]==0&&v!=w)
			 {
              _distance[v][w] = 10000;
             }
             D[v][w] = _distance[v][w];
            P[v][w] = w;
		}
	}
	for (int k = 0; k < G->numVertexes; ++k)
	{
		for (int v = 0; v < G->numVertexes; ++v)
		{
		 for (int w = 0; w < G->numVertexes; ++w)
		 {
		 	 if (D[v][w] > D[v][k] + D[k][w])
		 	 {
		 	 	D[v][w] = D[v][k] + D[k][w];
                P[v][w] = P[v][k];
			}
		  }
		}
	}
}
void AdjacencyList::ShowShortestResult(int originPos,int endPos) 
{
	int temp;
	double temp1=0,temp2=0;
	cout<<"地点"<<_mapName[originPos]<<"到地点"<<_mapName[endPos]<< "最短距离为" << ShortestPathvalue[originPos][endPos]<<"m"<<endl;
	temp = ShortestPathmatrix[originPos][endPos];
	temp1=ShortestPathvalue[originPos][endPos]/160;
	temp2=ShortestPathvalue[originPos][endPos]/45;
	cout<<"自行车时间"<<temp1<<"min"<<endl;
	cout<<"步行"<<temp2<<"min"<<endl ;
	cout<<"具体路径为："<<_mapName[originPos]<<"——>";	
    while (temp!=endPos){
        cout<<_mapName[temp]<<"——>";
        temp = ShortestPathmatrix[temp][endPos];
    }
    cout<<_mapName[endPos]<<endl;
}
int main()
{
	AdjacencyList adjacencyList;
    int originPos,endPos;
    GraphAdjList *GA = new GraphAdjList;
    adjacencyList.Test();
    adjacencyList.InitMap(GA);
    adjacencyList.CreateALGraph(GA);
    adjacencyList.ShortestPath_Floyd(GA,ShortestPathmatrix,ShortestPathvalue);
    cout<<"欢迎使用铭源导航系统"<<endl;
    cout<<"地图所有数据已经初始化完成,地图图像已显示"<<endl;
    while(1){
        cout<<"请按照图片选择你想去的地方，输入起始点和目的地的序号，以空格间隔。"<<endl;
        cout<<"标准格式 ：0 1关闭图片，回车"<<endl;
        cout<<"若输入已完成，请关闭图片。再按下回车键，即可显示路径。"<<endl;
        system("mspaint 123.png");
        cin>>originPos>>endPos;
        adjacencyList.ShowShortestResult(originPos,endPos);
 	} 
 	system("pause");
 	return 0;
}
