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
        int a[n + 1],b[n + 1];
        a[0] = 1;
        a[1] = 1;
        b[0] = 0;
        b[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            a[i] = a[i - 1] + a[i - 2];
            b[i] = b[i - 1] + b[i - 2];
        }
        int sum = 0;
        while (1)
        {
            if(n == 0)
            {
                break;
            }
            else if (n == 1)
            {
                sum += 1;
                break;
            }
            if(k > a[n - 1])
            {
                sum += b[n - 1];
                k -= a[n - 1];
                n -= 2;
            }
            else{
                n -= 1;
            }
        }
        cout << sum << endl;
    }
}