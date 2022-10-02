#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;
const int N=100010,M=N*2;

int n;
int ans=N;
int h[N],e[M],ne[M],idx;
bool st[N];

void add(int a,int b)
{
    e[idx]=b;  ne[idx]=h[a];h[a] = idx ++ ;
}

//返回的是以u为根的子树中点的个数
int dfs(int u)
{
    st[u]=true;
    int sum=0,size=0;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!st[j])
        {
            int s=dfs(j);
            size=max(size,s);   //size是子树中，点数最多的子树的点数
            sum+=s;             //sum是计算 以u为根的子树中点的个数
        }

    }
     size = max(size, n - sum - 1);
     ans = min(ans, size);

    return sum + 1;
}
int main()
{
    scanf("%d",&n);
    memset(h,-1,sizeof h);

    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);add(b,a);
    }

    dfs(1);

    printf("%d",ans);
    return 0;
}
