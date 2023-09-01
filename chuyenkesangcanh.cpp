#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int u, v;
    vector<set<int>> vec(n + 1);
    for(int i = 0; i < n; i++)
    {
        cin >> u >> v;
        vec[min(u, v)].insert(max(u, v));
    }
    for(int i = 1; i < n; i++)
    {
        if (vec[i].size() != 0)
        {
            for(auto j : vec[i])
            {
                cout << i << " "<< j << endl;
            }
        }

    }

}