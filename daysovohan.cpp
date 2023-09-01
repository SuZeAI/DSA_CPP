#include <bits/stdc++.h>
#define ll long long
#define MODULO 1000000007
using namespace std;
vector<vector<ll>> mulmatrix(vector<vector<ll>> mt1, vector<vector<ll>> mt2)
{
    vector<vector<ll>> mt = {{0, 0}, {0, 0}};
    
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                mt[i][j] += (mt1[i][k] * mt2[k][j]) % MODULO;
            }
        }
    }
    return mt;
}
vector<vector<ll>> fibon(vector<vector<ll>> mt, ll n)
{
    if(n == 1)
    {
        return mt;
    }
    vector<vector<ll>> mtr = fibon(mt, n/2);

    if(n % 2 == 0)
    {
        return mulmatrix(mtr, mtr);
    }
    else{
        return mulmatrix(mulmatrix(mtr, mtr), mt);
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        if(n == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            vector<vector<ll>> v = fibon({{1, 1}, {1, 0}}, n);
            cout << v[1][0] << endl;
            
        }
    }
}