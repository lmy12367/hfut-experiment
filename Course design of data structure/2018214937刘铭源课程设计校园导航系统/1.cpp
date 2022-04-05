#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int ShortestPathvalue[32][32]={0};//�洢���·��ֵ
int ShortestPathmatrix[32][32]={0};//�洢����·��
char _mapName[32][50]={"�ƽ�¥","����㳡","1��¥","3��¥",
"5��¥","7��¥","9��¥","11¥","���ٳ�","��������ѧԺ","ͼ���",
"1��","3��","5��","7��","9��","11��","����","����","����ٳ�",
"������","���ٳ�","�������ʵ����","��һʳ��","ע������",
"УҽԺ","��������","������","С����","����","�����","ʳƷ�빤��ѧԺ"};
int _distance[32][32]={0};//������Ϣ��distance[0][1]
//����Ϣ
typedef struct EdgeNode
{
	//�����±�
	int adjvex;
	//Ȩֵ
	int weight;
	//ָ����һ���ڽӵ�
	struct EdgeNode *next; 
 } edgenode;
 //�������
 typedef struct VertexNode
 {
 	//��������
	 char data[50];
	 //�߱�ͷָ��
	 EdgeNode *firstedge; 
  } VertexNode, AdjList[100];
 //���� 
 typedef struct
 {
 	AdjList adjList;
 	int numVertexes,numEdges;//����ͱ��� 
 }GraphAdjList;
 class AdjacencyList
 {
 	public:
 		void ShowALGraph(GraphAdjList *G);
 		void Test();
    //��ʼ����ͼ
    	void InitMap(GraphAdjList *G);
    //������ͼ
   		void CreateALGraph(GraphAdjList *G);
   		//�����������֮�����·��
   		void ShortestPath_Floyd(GraphAdjList *G, int P[32][32], int D[32][32]);
   		//���·�����Ⱥ;���·��
    	void ShowShortestResult(int originPos,int endPos);
  } ;
void AdjacencyList::CreateALGraph(GraphAdjList *G) 
{
	EdgeNode *e;
	//���붥����Ϣ�����������
	 for (int i = 0; i < G->numVertexes; i++)
	 {
	  //���붥����Ϣ
        strcpy(G->adjList[i].data, _mapName[i]);
        //���߱���Ϊ�ձ�
        G->adjList[i].firstedge = NULL;
	}
	//�����߱�ͷ�巨��
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
	cout<<"��ӭʹ�ñ�ϵͳ"<<endl; 
}
void AdjacencyList::ShowALGraph(GraphAdjList *G) {
    for (int i = 0; i < G->numVertexes; i++)
    {
    	cout << "����" << i << ": " << G->adjList[i].data << "--firstedge--";
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
//��ʼ����ͼ��������
void AdjacencyList::InitMap(GraphAdjList *G) {
	//���붥�����ͱ���
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
	//��ʼ��d��p
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
	cout<<"�ص�"<<_mapName[originPos]<<"���ص�"<<_mapName[endPos]<< "��̾���Ϊ" << ShortestPathvalue[originPos][endPos]<<"m"<<endl;
	temp = ShortestPathmatrix[originPos][endPos];
	temp1=ShortestPathvalue[originPos][endPos]/160;
	temp2=ShortestPathvalue[originPos][endPos]/45;
	cout<<"���г�ʱ��"<<temp1<<"min"<<endl;
	cout<<"����"<<temp2<<"min"<<endl ;
	cout<<"����·��Ϊ��"<<_mapName[originPos]<<"����>";	
    while (temp!=endPos){
        cout<<_mapName[temp]<<"����>";
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
    cout<<"��ӭʹ����Դ����ϵͳ"<<endl;
    cout<<"��ͼ���������Ѿ���ʼ�����,��ͼͼ������ʾ"<<endl;
    while(1){
        cout<<"�밴��ͼƬѡ������ȥ�ĵط���������ʼ���Ŀ�ĵص���ţ��Կո�����"<<endl;
        cout<<"��׼��ʽ ��0 1�ر�ͼƬ���س�"<<endl;
        cout<<"����������ɣ���ر�ͼƬ���ٰ��»س�����������ʾ·����"<<endl;
        system("mspaint 123.png");
        cin>>originPos>>endPos;
        adjacencyList.ShowShortestResult(originPos,endPos);
 	} 
 	system("pause");
 	return 0;
}
