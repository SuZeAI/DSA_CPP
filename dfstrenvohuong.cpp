#include <bits/stdc++.h>
using namespace std;
bool check[1005];
map<int, vector<int>> mp;
int e, v;
vector<int> d;
void dfs(int u,int cnt)
{
    if(cnt == v) return;
    for(auto i : mp[u])
    {
        if(check[i])
        {
            d.push_back(i);
            check[i] = false;
            dfs(i,cnt + 1);
        }
    }
}
void solution()
{
    mp.clear();
    d.clear();
    int v, u, a, b;
    cin >> v >> e >> u;
    for(int i = 1;i <= e; i++)
    {
        cin >> a >> b;
        mp[a].push_back(b);
    }
    for(int i = 1; i <= v; i++)
        {
            check[i] = true;
            sort(mp[i].begin(),mp[i].end());
        }
    check[u] = false;
    d.push_back(u);
    dfs(u, 1);
    for(auto i : d)
        cout << i << " ";
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solution();
    }
}