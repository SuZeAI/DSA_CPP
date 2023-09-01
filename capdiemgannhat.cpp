#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define fi first
#define se second
double dis(pair<double, double> a, pair<double, double> b)
{
    return sqrt((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}
void solution()
{
    int n;
    cin >> n;
    vector<pair<double, double>> a(n),b(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].fi >> a[i].se;
        b[i].se = a[i].fi;
        b[i].fi = a[i].se;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    double ans = 1e9;
    for(int i = 1; i < n; i++)
    {
        ans = min(ans, dis(a[i], a[i - 1]));
        ans = min(ans, dis(b[i], b[i - 1]));
    }
    cout << fixed << setprecision(6) << ans;    

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