#include <bits/stdc++.h>
using namespace std;
const long long MODULO = 1000000007;
long long luythua(long long a,long long b)
{
    if (b == 0)
        return 1;
    long long x = luythua(a, b/2);
    if (b % 2 == 0)
    {
        return ((x % MODULO) * (x % MODULO)) % MODULO;
    }
    else{
        return ((((x % MODULO) * (x % MODULO)) % MODULO) * a) % MODULO;     
    }

}
int main()
{
    long long a, b;
    while(true)
    {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        cout << luythua(a, b) << endl;
    }
}