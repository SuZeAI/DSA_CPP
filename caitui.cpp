#include <bits/stdc++.h>
using namespace std;
void init(int a[], int n)
{
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}
void out(vector<vector<int>> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, v;
        cin >> n >> v;
        int a[n + 1], c[n + 1];
        init(a, n), init(c, n);
        vector<vector<int>> vec(n + 1, vector<int>(v + 1, 0)) ;
        for(int i = 1; i <= n; i++ )
        {
            for(int j = 1;j <= v ;j++)
            {
                if(a[i] <= j )
                {
                    vec[i][j] = max(vec[i - 1][j - a[i]] + c[i], vec[i - 1][j]);
                }
                else{
                    vec[i][j] = vec[i - 1][j];
                }
            }
        }
        // out(vec);
        cout << vec[n][v]  <<endl;
    }


}