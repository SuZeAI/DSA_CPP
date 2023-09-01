#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int v, e;
        cin >> v >> e;
        vector<vector<int>> vec(v + 1);
        for(int i = 0; i < e; i++)
        {
            int m, n;
            cin >> m >> n;
            vec[m].push_back(n);
            vec[n].push_back(m);
        }
        for(int i = 1;i <= v; i++)
        {
            cout << i << ": ";
            for(int j = 0; j < vec[i].size(); j++)
            {
                cout << vec[i][j] << " ";
            }
            cout << endl;
        }
    }
}