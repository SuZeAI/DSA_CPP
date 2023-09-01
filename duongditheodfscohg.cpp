#include <bits/stdc++.h>
using namespace std;
int v, e;
bool check[1005], ans;
map<int, set<int>> mp;
int out[10005];
void dfs(int u, int k)
{
    for(auto i : mp[u])
    {
        if(check[i])
        {
            check[i] = false;
            if(i == k)
            {
                ans = true;
            }
            out[i] = u;
            dfs(i, k);
        }
    }
}

void reset()
{
    memset(check, 1,  sizeof(check));
    ans = false;
    memset(out, 0, sizeof(out));
    mp.clear();
}

void solution()
{
    reset();
    int u, k;
    cin >> v >> e >> u >> k;
    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[a].insert(b);
    }
    check[u] = false;
    dfs(u, k);
    if(ans)
    {
        vector<int> kq;
        kq.push_back(k);
        while(k != u)
        {
            k = out[k];
            kq.push_back(k);
        }
        for(int i = kq.size() - 1; ~i; i--)
        {
            cout << kq[i] << " ";
        }
    }
    else cout << "-1";
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