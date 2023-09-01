#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    vector<long long> v;
    set<long long> s;
    s.insert(1);
    while(true)
    {
        for(auto i : s)
        {
            if(i > 1e18)
            {
                break;
            }
            else{
                v.push_back(i * 2);
                v.push_back(i * 3);
                v.push_back(i * 5);
            }
        }
        for(auto i : v)
        {
            s.insert(i);
        }
        v.clear();
        if(s.size() > 1e4)
        {
            break;
        }

    }
    for(auto i : s)
    {
        v.push_back(i);
    }
    while(t--)
    {
        int n;
        cin >> n;
        cout << v[n - 1] << endl;
    }
}