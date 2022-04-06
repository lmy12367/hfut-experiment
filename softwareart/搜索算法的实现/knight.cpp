#include<iostream>
#include<ctime> 
using namespace std;
int board[8][8] = {0};
void travel(int a, int b)
{
    int knight_direction[8]={-2,-2,-1,-1,1,1,2,2};
    int knight_num[8]={1,-1,2,-2,2,-2,1,-1};
    int next_d[8]= {0};
    int next_n[8]= {0};
    int exists[8] = {0};
    int i,j,temple_i,temple_j,mine,temple;
    i = a;
    j = b;
    board[i][j] = 1;

    for(int foot= 2; foot <65; foot++)
    {
        for(int c = 0; c < 8; c++)
            exists[c] = 0;

     int p = 0;
    for(int k = 0; k < 8; k++)
    {
        temple_i = i + knight_direction[k];
        temple_j = j + knight_num[k];
        if(temple_i < 0||temple_j < 0||temple_i> 7||temple_j > 7)
              continue;
        if(board[temple_i][temple_j]==0)
        {
            next_d[p] =temple_i;
            next_n[p] = temple_j;
            p++;
        }

    }
    if(p == 0)
    {
        return ;
    }
    else if(p==1)
    {
        mine = 0;
    }
    else
    {
      for(int q = 0; q < p; q++)
      {
          for(int w = 0; w < 8; w++)
      {
        temple_i = next_d[q] + knight_direction[w];
        temple_j = next_n[q] + knight_num[w];
        if(temple_i < 0||temple_j < 0||temple_i> 7||temple_j > 7)
              continue;
         if(board[temple_i][temple_j]==0)
            exists[q]++;

        }
      }
      temple = exists[0];
      mine  = 0;
      for(int d = 1; d< p;d++)
      {
          if(exists[d] < temple)
          {
              temple = exists[d];
              mine = d;
          }

      }

    }

         i = next_d[mine];
         j = next_n[mine];
         board[i][j] = foot;
    }

  return ;
}

int main()
{
	clock_t start,end;
	start=clock();
    int a,b;
     cout<<"请输入起点的坐标:";
     cin >>a>>b;
     travel(a,b);
     for(int i = 0; i < 8; i++)
     {
        for(int j = 0; j < 8; j++)
          {
              cout <<board[i][j]<<" ";
          }
        cout <<endl;
     }
     end=clock();
	cout<<"time"<<end-start<<"ms"<<endl;
	system("Pause");

    return 0;
}
