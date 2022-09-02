#include<iostream>

using namespace std;

const int N=10;
int path[N];   //保存序列
int n;
bool state[N]; // state[]数组判断数字是否用过，1表示用过

void dfs(int u)
{
    if(u==n)    //队列满了，输出
    {
        for(int i=0;i<n;i++) printf("%d ",path[i]);
        puts("");
        return ;
    }
    for(int i=1;i<=n;i++)   // 重要点，回溯是回溯到for循环里面，for循环结束代表函数结束
    {
        if(!state[i])    //数字没被用过
        {
            path[u]=i;    //填入数字
            state[i]=1;   
            dfs(u+1);
            state[i]=0;    //递归结束后恢复序列（回溯）
        }
    }
}
int main()
{
    cin>>n;

    dfs(0);

    return 0;
}
