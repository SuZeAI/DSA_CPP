#include <bits/stdc++.h>
using namespace std;
int v, e;
map<int, pair<int, int>> deg;
map<int, set<int>> mp;
bool check[1005];
vector<int> out;
void addedge(int a, int b)
{
    deg[a].first ++;
    deg[b].second ++;
    mp[a].insert(b);
}
void dfs(int u)
{
    for(auto i : mp[u])
    {
        if(check[i])
        {
            out.push_back(i);
            check[i] = false;
            dfs(i);
        }
    }
}
void reset()
{
    memset(check, 1, sizeof(check));
    mp.clear();
    out.clear();
    deg.clear();
}
void solution()
{
    reset();
    int a, b;
    cin >> v >> e;
    for(int i = 0; i < e; i++)
    {
        cin >> a >> b;
        addedge(a, b);
    }
    int ans = 0;
    check[1] = false;
    out.push_back(1);
    dfs(1);
    if(out.size() == v)
    {
        bool ok = true;
        for(auto i: deg)
        {
            if(i.second.first != i.second.second)
            {
                ok = false;
                break;
            } 
        }
        for(auto i : mp)
        {
            if(i.second.size() <= 0)
            {
                ok = false;
                break;
            }
        }
        if(ok) ans = 1;
    }
    cout << ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solution();
        cout << endl;
    }
}