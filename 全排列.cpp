#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 7;
string a;
bool st[N];
string res;
void dfs(string a, int cnt)
{
    if(cnt == a.size()){ cout << res << endl;return;}
    for(int i = 0; i < a.size(); i ++ )
    {
        if(!st[i])
        {
            st[i] = true;
            res += a[i];
            dfs(a,cnt + 1 );//递归
            st[i] = false;//回溯
            res.pop_back();
        }
    }
}
int main()
{
    cin >> a;
    dfs(a,0);
    return 0;
}
