#include <bits/stdc++.h>
using namespace std;
long long BIT[20000005];
int n;
void up(int i, int u)
{
    for(;i < 2 * n + 10; i += i & -i) BIT[i] += u;
}

long long qr(int u)
{
    long long sum = 0;
    for(int i = u; i > 0; i -= i & -i)
    {
        sum += BIT[i];
    }
    return sum;
}
void reset()
{
    memset(BIT, 0, sizeof(BIT));
}

void solution()
{
    reset();
    cin >> n;
    int a[n + 1], b[n + 1];
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    map<long long, long long> mp;
    for(int i = 1; i <= n; i++)
    {
        mp[b[i]] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        a[i] = mp[a[i]];
    }
    long long ans =0;
    for(int i = n; i > 0; i--)
    {
        ans += qr(a[i] - 1);
        up(a[i], 1);
    }
    cout << ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solution();
        cout << endl;
    }
}