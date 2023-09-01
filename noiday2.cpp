#include <bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> v;
        ll tmp;

        for(int i = 0; i < n; i++)
        {
            cin >> tmp;
            v.push(tmp);
        }
        ll sum = 0;
        while(v.size() > 1)
        {
            ll tmp1 = v.top();
            v.pop();
            tmp1 += v.top();
            v.pop();
            v.push(tmp1);
            sum += tmp1;
            sum %= mod;
        }
        cout << sum << endl;
    }
}