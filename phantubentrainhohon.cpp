#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], ans[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        stack<int> st;
        for(int i = n - 1; ~i; i--){
            while(!st.empty() and a[i] <= a[st.top()])
            {
                st.pop();
            }
            if(st.empty()) ans[i] = -1;
            else{
                int top = st.top();
                ans[i] = a[top];
            }
            st.push(i);
        }
        stack<int> st1;
        int ans1[n];
        for(int i = n - 1; ~i; i--){
            while(!st1.empty() and a[i] >= a[st1.top()]){
                st1.pop();
            }
            if(st1.empty())
            {
                ans1[i] = -1;
            }
            else{
                int top = st1.top();
                if(ans[top] == -1) ans1[i] = -1;
                else{
                    ans1[i] = ans[top];
                }
            
            }
            st1.push(i);
        }
        for(int i = 0; i < n; i++){
            cout << ans1[i] << " ";
        }
        cout << endl;
    }
}