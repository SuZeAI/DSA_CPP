#include <bits/stdc++.h>
using namespace std;
struct Point{
    int x, y, s;
};
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<bool>> check(n + 1, vector<bool>(m + 1, 1));        
        int a[n + 1][m + 1];
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        queue<Point> qe;
        int ans = 1e9;
        Point st, k;
        st.x = 1;
        st.y = 1;
        st.s = 0;
        qe.push(st);
        while(!qe.empty())
        {
            k = qe.front();qe.pop();
            if(k.x == n and k.y == m)
            {
                ans = min(ans, k.s);
            }
            k.s++;
            if(k.x + a[k.x][k.y] <= n and check[k.x + a[k.x][k.y]][k.y])
            {
                check[k.x + a[k.x][k.y]][k.y] = false;
                int tmp = k.x;
                k.x += a[k.x][k.y];
                qe.push(k);
                k.x -= a[tmp][k.y];
                
            }
            if(k.y + a[k.x][k.y] <= m && check[k.x][k.y + a[k.x][k.y]])
            {
                check[k.x][k.y + a[k.x][k.y]] = false;
                int tmp = k.y;
                k.y += a[k.x][k.y];
                qe.push(k);
                k.y -= a[k.x][tmp];
            }
        }
        if( ans == int(1e9))
        {
            cout << "-1\n";
        }
        else
        {
            cout << ans << endl;
        }

    }
}