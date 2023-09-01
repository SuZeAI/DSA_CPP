#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, m;
        cin >> n >> k >> m;
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        vector<vector<vector<int>>> v(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1, 0)));
        for(int i = 1;i <= n; i++)
            for(int j = 1; j <= k; j++)
                for(int h = 1; h <= m; h++)
                {
                    if(s1[i - 1] == s2[j - 1] and s1[i - 1] == s3[h - 1])
                    {
                        v[i][j][h] = v[i - 1][j - 1][h - 1] + 1;
                    }
                    else{
                        v[i][j][h] = max({v[i - 1][j][h], v[i][j - 1][h], v[i][j][h - 1]});
                    }
                }
        cout << v[n][k][m] << endl;
    }
}