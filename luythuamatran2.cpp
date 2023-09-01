#include <bits/stdc++.h>
#define ll long long
#define MODULO 1000000007
using namespace std;
vector<vector<ll>> mulmatrix(vector<vector<ll>> mt1, vector<vector<ll>> mt2, ll n)
{
    vector<vector<ll>> mt(n, vector<ll>(n, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)  
        {
            for(int k = 0; k < n; k++)
            {
                mt[i][j] += (mt1[i][k] * mt2[k][j]) % MODULO;
                mt[i][j] %= MODULO;
            }
        }
    }
    return mt;
}
vector<vector<ll>> fibon(vector<vector<ll>> mt, ll n, ll k)
{
    if(k == 1)
    {
        return mt;
    }
    vector<vector<ll>> mtr = fibon(mt, n, k/2);

    if(k % 2 == 0)
    {
        return mulmatrix(mtr, mtr, n);
    }
    else{
        return mulmatrix(mulmatrix(mtr, mtr, n), mt, n);
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<vector<ll>> mp(n, vector<ll>(n, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> mp[i][j];
            }
        }
        vector<vector<ll>> v = fibon(mp, n, k);
        ll sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += v[i][n - 1];
        }
        cout << sum % MODULO << endl;

    }
}