#include <bits/stdc++.h>
using namespace std;
int v, e;
map<int, set<int>> mp;
bool check[1005];
vector<int> out;
void addedge(int a, int b)
{
    mp[a].insert(b);
    mp[b].insert(a);
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
    int odd = 0;
    check[1] = false;
    out.push_back(1);
    dfs(1);
    if(out.size() == v)
    {
        bool ok = false;
        for(auto i : mp)
        {
            if(i.second.size() % 2 != 0 )
            {
                odd++;
            }
            if(i.second.size() <= 0)
            {
                break;
                ok = true;
            }
        }
        if(!ok)
        {
            if(odd == 2) ans = 1;
            else if(odd == 0) ans = 2;
        } 

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
// void dfs(int u)
// {
//     stack<int> st;
//     st.push(u);
//     while(!st.empty())
//     {
//         int top = st.top();
//         if(mp[top].size() != 0)
//         {
//             for(auto i : mp[top])
//             { 
//                 st.push(i);
//                 mp[top].erase(i);
//                 mp[i].erase(top);
//                 break;
//             }
//         }
//         else{
//             out.push_back(top);
//             st.pop();
//         }
//     }
// }