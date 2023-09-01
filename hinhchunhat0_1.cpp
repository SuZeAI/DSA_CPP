#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >>  m;
        int a[n][m];
        for(int i = 0; i < n; i++)
        {
            for(int j =0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++)
            {
                if(a[i][j])
                {
                    a[i][j] += a[i - 1][j];
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            stack<int> st;
            for(int j = 0; j < m; j++)
            {
                while(!st.empty() and a[i][j] <= a[i][st.top()])
                {
                    int top = st.top(); st.pop();
                    int l = st.empty() ? -1 : st.top();
                    res = max((j - l - 1) * a[i][top] , res);
                }
                st.push(j);
            }
        }
        cout << res << endl;
    }
}
