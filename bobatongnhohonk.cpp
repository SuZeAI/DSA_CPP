#include <bits/stdc++.h>
using namespace std;
// bool check(vector<long long> v, int n)
// {
//     for(long long i = 0;i < n - 1; i++)
//     {
//         for(long long j = i + 1; j < n; j++)
//         {
//             long long k = v[i] * v[i] + v[j] * v[j];
//             long long x = sqrt(k);
//             if(x * x == k && binary_search(v.begin() + j + 1, v.begin() + n, x))
//             {
//                 return true;
//             }
//         }

//     }    
//     return false;
// }
int main()
{
    long long t;
    cin >> t;
    while(t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> v(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        string ans = "NO";
        for(long long i = 0;i < n - 1; i++)
        {
            for(long long j = i + 1; j < n; j++)
            {
                long long m = v[i] * v[i] + v[j] * v[j];
                long long x = sqrt(m);
                if(x * x == k && binary_search(v.begin() + j + 1, v.begin() + n, x))
                {
                    ans = "YES";
                    break;
                }
            }
            if (ans == "YES")
                break;

        }  
        cout << ans << endl;
    }   
}