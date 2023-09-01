#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;
const ll mod = 1e9 + 7;
const int mxN = 1001;
vector<int> adj[mxN];
bool visited[mxN];
int V, E, S, T;
int par[mxN];

void bfs(int u = S){
    queue<int> q;
    q.push(u);
	visited[u] = true;
	while(!q.empty())
    {
        int fr = q.front(); q.pop();
        for(auto i : adj[fr])
        {
            if(!visited[i])
            {
                visited[i] = true;
                par[i] = fr;
                q.push(i);
            }

        }
    }
}
void dfs(int u)
{
    visited[u] = true;
    for(auto v : adj[u])
    {
        if(!visited[v])
        {
            par[v] = u;
            dfs(v);
        }
    }
}
void solve(){
	memset(par, 0, sizeof(par));
    int cnt = 0;
	for(int i = 1;i <= V; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << endl;
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		memset(adj, {}, sizeof(adj));
		memset(visited, false, sizeof(visited));
		cin >> V >> E ;
		for(int i = 0; i < E; ++i){
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		solve();
	}	
	return 0;
}
