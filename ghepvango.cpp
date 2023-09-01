#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int res = 0;
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() and a[i] <= a[st.top()])
            {
                int top = st.top(); st.pop();
                int l = st.empty() ? -1 : st.top();
                res = (i - l - 1) >= a[top] ? max(res, a[top]) : res;
            }
            st.push(i);
        }
        cout << res << endl;
    }
}