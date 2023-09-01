#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e15 + 7;
struct matrix{
    ll a[5][5] = {};
};

ll mul(ll a, ll b)
{
    if(b == 1)
        return a;
    if(b == 0)
        return 0;
    ll tmp = mul(a, b/2) % mod;
    if(b & 1) return ((tmp * 2) % mod + a % mod) % mod;
    else return (2 * tmp) % mod;
}   
matrix operator *(matrix A, matrix B)
{
    matrix tmp;
    for(int i = 1;i <= 4; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            ll k = 0;
            for(int l = 1; l <= 4; l++)
            {
                k = (k % mod) + mul(A.a[i][l] % mod, B.a[l][j] % mod) % mod;
            }
            k %= mod;
            tmp.a[i][j] = k;
        }
    }
    return tmp;
}
matrix operator ^(matrix A, ll k)
{
    if(k == 1)
        return A;
    matrix X = A ^ (k/2);
    if(k & 1) return (X * X) * A;
    else return X * X;
}


int main()
{
    int t;
    cin >> t;
    while(t--){
        ll k, ans = 0;
        matrix A;
        cin >> k;
        if(k <= 3)
        {
            cout << ((k + 1) * k)/2 << endl;
            continue;
        }
        A.a[1][1] = 1, A.a[1][2] = 1, A.a[1][3] = 0, A.a[1][4] = 0;
        A.a[2][1] = 0, A.a[2][2] = 1, A.a[2][3] = 1, A.a[2][4] = 1;
        A.a[3][1] = 0, A.a[3][2] = 1, A.a[3][3] = 0, A.a[3][4] = 0;
        A.a[4][1] = 0, A.a[4][2] = 0, A.a[4][3] = 1, A.a[4][4] = 0;
        matrix B = (A ^ (k - 2));
        for(int i = 2; i <= 4; i++)
        {
            ans += mul(B.a[1][i], (5 - i));
            ans %= mod;
        }
        ans += mul(B.a[1][1], 3);
        ans %= mod;
        cout << ans << endl;
    }
}