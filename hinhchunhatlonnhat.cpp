#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n + 1];
        for(int i = 0 ; i < n; i++){
            cin >> a[i];
        }
        a[n] = 0;
        long long res = 0;
        stack<int> st;
        for(int i = 0; i < n + 1; i++)
        {
            while(!st.empty() and a[i] <= a[st.top()])
            {
                int top = st.top(); st.pop();
                int l = st.empty() ? -1 : st.top();
                res = max(res, (long long)(i - l - 1) * a[top]);
            }
            st.push(i);
        }
        cout << res << endl;
    }

}