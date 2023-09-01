#include <bits/stdc++.h>
using namespace std;
int sz[100005];
int pr[100005];
int n, m, a, b, res=0;
int Find(int u){
    if(pr[u]== u) return u;
    else return pr[u] = Find(pr[u]);
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a == b) return ;
    if(sz[a] < sz[b]) swap(a, b);
    pr[b] = a;
    sz[a] += sz[b];
    res = max(res, sz[a]);
}
void reset(){
    res= 0;
    for(int i = 0; i < 100005; i++){
        pr[i] = i;
        sz[i] = 1;
    }
}
int main(){
    vector<int> v;

    int t; 
    cin >> t;
    while(t--){
        cin >> n >> m;
        reset();
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b;
            Union(a, b);
        }
            cout << res << endl;
    }
}
