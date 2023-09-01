#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        queue<long long> qe;
        qe.push(1);
        while(!qe.empty())
        {
            long long x = qe.front(); qe.pop();
            if(x % n == 0)
            {
                cout << x << endl;
                break;
            }
            qe.push(x * 10);
            qe.push(x* 10 + 1);
        }
    }
}