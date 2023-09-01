#include <bits/stdc++.h>
using namespace std;
vector<int> k[1005];
bool visited[1005];
int V, E;
void dfs(int u){
    visited[u] = true;
    for(auto v : k[u] )
    {
        if(!visited[v])
        {
            dfs(v);
        }
    }
}
void reset(){
    for(int i = 0; i < 1005; i++){
        k[i].clear();
        visited[i] = false;
    }
}
string solution(){
    cin >> V >> E;
    int a, b;

    for(int i = 0; i < E; i++){
        cin >> a >> b;
        k[a].push_back(b);
    }
    for(int j = 1; j <= V; j++){
        memset(visited, 0, sizeof(visited));
        dfs(j);
        for(int i = 1; i <= V; i++){
            if(visited[i] == 0) return "NO\n";
        }
    }
    return "YES\n";

}
int main(){
    int t;
    cin >> t;
    while(t--){
        reset();
        cout << solution();
    }
}