#include <bits/stdc++.h>
using namespace std;
string right(string s, int id)
{
    if(id == 1)
    {
        char c = s[0];
        s[0] = s[3];
        s[3] = s[7];
        s[7] = s[8];
        s[8] = s[5];
        s[5] = s[1];
        s[1] = c;
        return s;
    }
    else
    {
        char c = s[1];
        s[1] = s[4];
        s[4] = s[8];
        s[8] = s[9];
        s[9] = s[6];
        s[6] = s[2];
        s[2] = c;
        return s;
    }
}
string left(string s, int id)
{
    if(id == 1)
    {
        char c = s[0];
        s[0] = s[1];
        s[1] = s[5];
        s[5] = s[8];
        s[8] = s[7];
        s[7] = s[3];
        s[3] = c;
        return s;
    }
    else{
        char c = s[1];
        s[1] = s[2];
        s[2] = s[6];
        s[6] = s[9];
        s[9] = s[8];
        s[8] = s[4];
        s[4] = c;
        return s;
    }
}
void init(string &s1)
{
    string s;
    for(int i = 0; i < 10; i++)
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
        init(s1);
        s2 = "1238004765";
        queue<pair<string, int>> qe,qe1;
        map<string, int> f;
        qe.push({s1, 0});
        f[s1] = 0;
        qe1.push({s2, 0});
        int ans = 1e9;
        while(!qe.empty())
        {
            pair<string, int> x = qe.front(); qe.pop();
            x.second++;
            string tmp;

            tmp = right(x.first, 1);
            if(f[tmp] == 0)
                f[tmp] = x.second;
            qe.push({tmp,x.second});

            tmp = right(x.first, 2);
            if(f[tmp] == 0)
                f[tmp] = x.second;
            qe.push({tmp,x.second});

            if(x.second == 14) break;
        }

        while(!qe1.empty())
        {
            pair<string, int> x = qe1.front(); qe1.pop();
            if(f[x.first] > 0)
            {
                ans = min(ans, f[x.first] + x.second);
            }
            x.second++;
            qe1.push({left(x.first, 1),x.second});
            qe1.push({left(x.first, 2),x.second});
            if(x.second == 14) break;
        }
        cout << ans << endl;
    }
}