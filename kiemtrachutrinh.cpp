#include <bits/stdc++.h>
using namespace std;
vector<int> k[1005];
bool visited[1005];
int V, E;
bool check(int v){
    visited[v] = true;
    for(auto a : k[v]){
        if(!visited[a]){
            if(check(a)) return true;
        }
        else if(visited[a]) return true;
    }
    return false;

}
void reset(){
    for(int i = 0; i < 1005; i++){
        k[i].clear();
        visited[i] = false;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        reset();
        cin >> V >> E;
        int a, b;
        for(int i = 1; i <= E; i++)
        {
            cin >> a >> b;
            k[a].push_back(b);
        }
        bool fl = false;
        for(int i = 1; i <= V; i++)
        {
            memset(visited, 0, sizeof(visited));
            if(check(i)) fl = true;
        }
        cout << (fl ? "YES\n" : "NO\n");
        
    }
}