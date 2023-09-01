#include <bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k = 3;
        cin >> n;
        vector<ll> v(n + 1, 0);
        for(int i = 1; i <= min(k, n); i++)
        {
            v[i] = 1 << (i - 1);
        }
        for(int i = k + 1; i <= n; i++)
        {
            for(int j = 1; j <= k; j++)
            {
                v[i] += v[i - j];
            } 
        }
        cout << v[n] << endl;

    }
}