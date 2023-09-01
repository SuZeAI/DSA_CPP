#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> ls(n + 1, vector<int>(k + 1, 0));
        vector<vector<int>> ls2(n + 1, vector<int>(k + 1, 0));
        vector<vector<int>> ls3(n + 1, vector<int>(k + 1, 0));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= k; j++)
            {
                cin >> ls[i][j];
            }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= k; j++)
            {
                if(ls[i][j] == 1)
                {
                    ls2[i][j] = ls2[i][j - 1] + 1;
                }
            }
        for(int i = 1; i <= k; i++)
            for(int j = 1; j <= n; j++)
            {
                if(ls[j][i] == 1)
                {
                    ls3[j][i] = ls3[j - 1][i] + 1;
                }
            }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= k; j++)
            {
                if(ls[i][j] == 1)
                {
                    if(ls[i - 1][j - 1] >= 1)
                    {
                        if(ls2[i][j - 1] >= ls[i - 1][j - 1] and ls3[i - 1][j] >= ls[i - 1][j - 1])
                        {
                            ls[i][j] = ls[i - 1][j - 1] + 1;
                        }
                    }
                }
                ans = max(ans, ls[i][j]);
            }
        cout << ans << endl; 
    }
}