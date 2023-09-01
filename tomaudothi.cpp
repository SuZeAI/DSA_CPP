#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

const int mxN = 20;
int V, E, M;

int color[mxN];
map<int, vector<int>> mp;
bool check(int u, int clr){
	for(auto i : mp[u])
        if(color[i] == clr) return false;
    return true;
}
bool Try(int u = 1){
	
	if(u == V + 1) return true;	
	for(int clr = 1; clr <= M; ++clr){
		if(check(u, clr)){
			color[u] = clr;
			if(Try(u + 1)) return true;	
		}

	}
	return false;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	
	while(t--){
		cin >> V >> E >> M;
		memset(color, 0, sizeof(color));
        mp.clear();
		for(int i = 0; i < E; ++i){
			int u, v;
			cin >> u >> v;
			mp[u].push_back(v);
            mp[v].push_back(u);
		}		
		cout << (Try() ? "YES" : "NO") << '\n';	
	}
	return 0;
}