#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int v, e, a, b;
        cin >> v >> e;
        map<int, set<int>> mp;
        for(int i = 0;i < e; i++)
        {
            cin >> a >> b;
            mp[a].insert(b);
        }
        for(int i = 1;i <= v; i++)
        {
            cout << i << ": ";
            if(mp[i].size() != 0)
                for(auto k : mp[i])
                    cout << k << " ";
            cout << "\n";
        }
    }
}