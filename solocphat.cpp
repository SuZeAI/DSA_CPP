#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        queue<string> qe;
        int n;
        cin >> n;
        vector<string> v;
        qe.push("6");
        qe.push("8");
        while(!qe.empty())
        {
            string x = qe.front();qe.pop();
            v.push_back(x);
            if(x.length() > n)
            {
                v.pop_back();
                break;
            }
            qe.push(x + "6");
            qe.push(x + "8");
        }
        cout << v.size() << endl;
        for(int i = v.size() - 1; ~i ; i--)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}