#include <bits/stdc++.h>
using namespace std;
bool cmp(string s, string s1)
{
    return s.length() < s1.length() || (s.length() == s1.length() && s <= s1);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        queue<string> qe;
        string n; 
        int ans = 1;
        cin >> n;
        qe.push("1");
        while(!qe.empty())
        {
            string x = qe.front(); qe.pop();
            if(cmp(x + "0", n))
            {
                qe.push(x + "0");
                ans++;
            }
            if(cmp(x + "1", n))
            {
                qe.push(x  + "1");
                ans++;
            }
        }
        cout << ans << endl;
    }
}