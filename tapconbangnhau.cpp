#include <bits/stdc++.h>
using namespace std;
long long ls[10001];
bool check = false;
void backtrack(long long i, long long n, long long k)
{
    for(long long j = i; j < n; j++)
    {
        if(k == ls[j])
        {
            check = true;
            return;
        }
        else if(k > ls[j]){
            backtrack(j + 1, n, k - ls[j]);
        }
    }

}
int main()
{
    long long t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        long long sum = 0;
        check = false;
        for(long long i = 0; i < n; i++)
        {
            cin >> ls[i];
            sum += ls[i];
        }
        sort(ls, ls + n);
        if(sum % 2 == 0)
        {
            long long k = sum /2;
            backtrack(0, n, k);
            if(check)
            {
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else{
            cout << "NO\n";
        }
    }
}