#include <bits/stdc++.h>
using namespace std;
string right(string s, int id)
{
    if(id == 1)
    {
        char c = s[0];
        s[0] = s[3];
        s[3] = s[4];
        s[4] = s[1];
        s[1] = c;
        return s;
    }
    else
    {
        char c = s[1];
        s[1] = s[4];
        s[4] = s[5];
        s[5] = s[2];
        s[2] = c;
        return s;
    }
}
void init(string &s1)
{
    string s;
    for(int i = 0; i < 6; i++)
    {
        cin >> s;
        s1 += s;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--)
    {
        string s1, s2;
        init(s1), init(s2);
        queue<pair<string, int>> qe;
        qe.push({s1, 0});
        int ans = 1e9;
        while(!qe.empty())
        {
            pair<string, int> x = qe.front(); qe.pop();
            if(x.first == s2)
            {
                ans = min(ans, x.second);
            }
            x.second++;
            qe.push({right(x.first, 1),x.second});
            qe.push({right(x.first, 2),x.second});
            if(x.second == 14) break;
        }
        cout << ans << endl;
    }
}