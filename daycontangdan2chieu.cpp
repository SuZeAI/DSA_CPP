#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(pair<int, int>(x, y));
    }
    // for(auto l : v)
    // {
    //     cout << l.first << l.second << endl;
    // }
    vector<int> ans(n, 1);
    for(int i = 1; i < n; i++)
    {
        for(int j = 0;j < i; j++)
        {
            if(v[i].first > v[j].first and v[i].second > v[j].second)
            {
                ans[i] = max({ans[i], ans[j] + 1});
            }
        }
    }
    cout << *max_element(ans.begin(), ans.end()) << endl;
}