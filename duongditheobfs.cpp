#include <bits/stdc++.h>
using namespace std;
class Graph{
    private:
        int v;
        list<int> *adj;
        bool *check;
        bool stop;
    public:
        Graph(int v);
        void addEdge(int v, int w);
        void DFS(int mp1, int mp2);
};
Graph::Graph(int v)
{
    stop = true;
    this->v = v;
    adj = new list<int>[v];
    check = new bool[v];
    for(int i =0; i< v; i++)
        check[i] = true;
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::DFS(int u, int v)
{
    int x;
    string s;
    queue<pair<int, string>> st;
    st.push({u, to_string(u) + " "});
    check[u] = false;
    while (st.size())
    {
        x = st.front().first;
        s = st.front().second;
        if (x == v)
        {
            stop = false;
            cout << s;
            break;
        }
        st.pop();
        list<int>::iterator idx;
        for (idx = adj[x].begin(); idx != adj[x].end(); idx++)
        {
            if (check[*idx])
            {
                check[*idx] = false;
                st.push({*idx, s + to_string(*idx) + " "});
            }
        }
    }
    if (stop)
        cout << -1;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, mp1, mp2;
        cin >> n >> m >> mp1 >> mp2;
        int tmp1, tmp2;
        Graph gp(n + 1);
        for(int i = 0; i < m; i++)
        {
            cin >> tmp1 >> tmp2;
            gp.addEdge(tmp1, tmp2);
        }
        gp.DFS(mp1, mp2);
        cout << endl;
    }
}