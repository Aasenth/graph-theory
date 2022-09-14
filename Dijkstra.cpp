#include<iostream>
#include<cstring>
#include<algorithm>
const int N=510;
int g[N][N];   //稠密图用邻接矩阵存储
int dist[N];   //存储最短路径 
bool st[N];    //，集合，判断某一个点是否以及确认是最小值
int n,m;

using namespace std;

int dijkstra()
{
    memset(dist,0x3f,sizeof dist); //第一步，初始化为正无穷
    dist[1]=0;                      //初始只有第一个点最短路确定
    for(int i=0;i<n;i++)            
    {
        int t=-1;           //dijkstra没有负权边，用负数判断是否找到下一个最近的点
       for(int j=1;j<=n;j++)
           if(!st[j] && (t==-1 || dist[t]>dist[j])) //从false的点中找出最近的点
                t=j;
       for(int j=1;j<=n;j++)
           dist[j]=min(dist[j],dist[t]+g[t][j]);  //用找到的点更新最短距离
       st[t]=true;                              //将点并入集合
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    else return dist[n];
}
int main()
{
  scanf("%d%d",&n,&m);
  memset(g,0x3f,sizeof g);
  while(m--)
  {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      g[a][b]=min(g[a][b],c);
  }
  cout<<dijkstra()<<endl;
  return 0;
}
