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
        int a[n], ans[n], mx = -1e9;
        for(int i = 0 ; i < n; i++)
        {
            cin >> a[i];
            ans[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(a[i] >= a[j] and ans[i] < ans[j] + 1)
                {
                    ans[i] = ans[j] + 1;
                }
            }
            mx = max(mx, ans[i]);
        }
        cout << n - mx << endl;
    }
}