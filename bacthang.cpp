#include <bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
using namespace std;
ll power(int n)
{
    if(n == 0)
    {
        return 1;
    }
    ll x = power(n/2);
    if(n & 1)
    {
        return (x * x * 2) % mod;
    }
    else{
        return (x * x) % mod;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<ll> v(n + 1, 0);
        for(int i = 1; i <= min(k, n); i++)
        {
            v[i] = power(i - 1);
        }
        for(int i = k + 1; i <= n; i++)
        {
            for(int j = 1; j <= k; j++)
            {
                v[i] += v[i - j];
                v[i] %= mod;
            } 
        }
        cout << v[n] << endl;

    }
}