#include <bits/stdc++.h>
using namespace std;
bool check[1005];
map<int, set<int>> mp;
int e, v;
void dfs(int u)
{
    for(auto i : mp[u])
    {
        if(check[i])
        {
            check[i] = false;
            dfs(i);
        }
    }
}
void reset()
{
    for(int i = 1;i <= v; i++)
    {
        check[i] = true;
    }
}
int lienthong()
{
    reset();
    int v_cnt = 0;
    for(int i = 1;i <= v; i++)
    {
        if(check[i])
        {
            v_cnt++;
            dfs(i);
        }
    }
    return v_cnt;
}
void solution()
{
    int a, b;
    cin >> v >> e;
    vector<pair<int,int>> vec;
    set<pair<int, int>> ans;
    for(int i = 1; i <= e; i++)
    {
        cin >>a >> b;
        vec.push_back(pair<int,int>(a, b));
        mp[a].insert(b);
        mp[b].insert(a);
    }
    int slt = lienthong();
    map<int, set<int>> mp1 = mp;
    for(auto i : vec)
    {
        mp = mp1;
        mp[i.first].erase(i.second);
        mp[i.second].erase(i.first);
        int slt1 = lienthong();
        if(slt1 > slt) ans.insert(i);
    }
    for(auto i : ans)
    {
        cout << i.first << " " << i.second << " ";
    }
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