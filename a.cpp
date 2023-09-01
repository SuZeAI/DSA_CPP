#include <bits/stdc++.h>
using namespace std;
double dis(pair<double, double> a, pair<double, double> b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
int main()
{
    vector<pair<double, double>> v = {{-5, 1}, {-3, 4},{-4, 12}, {-3.5, -11}};
    double ans = 1e9;
    for(int i = 0; i < 3; i++)
    {
        for(int j = i + 1; j < 4; j++)
        {
            ans = min(ans, dis(v[i], v[j]));
            cout << "v[i]:" << v[i].first << " " << v[i].second << "; v[j]: " << v[j].first <<" " << v[j].second << "; dis:" << dis(v[i], v[j]) << endl;
        }
    }
}