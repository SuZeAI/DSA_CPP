#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;

    while(t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        vector<vector<int>> v(s2.length() + 1, vector<int>(s1.length()+ 1, 0));
        for(int i = 1; i <= s2.length(); i++)
        {
            for(int j = 1; j <= s1.length(); j++)
            {
                if (s2[i - 1] == s1[j - 1])
                {
                    v[i][j] = v[i - 1][j - 1] + 1;
                }
                else{
                    v[i][j] = max(v[i - 1][j], v[i][j - 1]);
                }
            }
        }
        cout << v[s2.length()][s1.length()] << endl;
    }
}