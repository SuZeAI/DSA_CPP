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
        vector<int> v, v1(n + 1);
        int i = 1;
        while(i * i <= n)
        {
            v.push_back(i * i);
            i++;
        }
        for(int i = 1; i <= n;i++)
        {
            for(auto j : v)
            {
                if (i >= j)
                {
                    if(v1[i] == 0)
                    {
                        v1[i] = v1[i - j] + 1;
                    }
                    else
                    {
                        v1[i]= min({v1[i - j] + 1, v1[i]});
                    }

                }
            }
        }
        cout << v1[n] << endl;
    }
}