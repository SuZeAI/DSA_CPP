#include <bits/stdc++.h>
using namespace std;
vector<int> k[10005];
bool check[10005];
int ans[10005];
void dfs(int u = 1){
    for(auto i : k[u])
    {
        if(!check[i])
        {
            check[i] = true;
            ans[i] = u;
            dfs(i);
        }
    }
}

void reset(){
    for(int i = 0; i < 100; i++){
        k[i].clear();
        check[i] = false;
    }
}
vector<int> par(int u)
{
    vector<int> v;
    while(u != 1)
    {
        v.push_back(u);
        u = ans[u];
    }
    v.push_back(1);
    reverse(v.begin(), v.end());
    return v;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        reset();
        vector<vector<int>> v;
        for(int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            k[u].push_back(v);
        }
        dfs();
        for(int i = 2; i <= n; i++){
            if(k[i].size() == 0)
            {
                vector<int> tmp = par(i);
                v.push_back(tmp);
            }
        }
        for(auto item : v){
            for(auto k : item){
                cout << k << " ";
            }
            cout << endl;
        }
        
    }
}
    // sinh, back track, divide
    // tham lm quy hojach
    // ngawn xep
    // do thi
    // tat car