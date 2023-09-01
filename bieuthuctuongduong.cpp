#include <bits/stdc++.h>
using namespace std;
string tranform(string s, int l, int r)
{
    if(l - 1 >= 0)
    {
        if(s[l - 1] == '-' ){
            for(int i = l; i < r; i++)
            {
                if(s[i] == '+') s[i] = '-';
                else if(s[i] == '-') s[i] = '+';
            }
        }

    }
    return s;
}
int main(){
    int t;
    cin>> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        stack<int> st;
        for(int i = 0;i < n;i++){
            if(s[i] == '(')
            {
                st.push(i);
            }
            else if(s[i] == ')'){
                int top = st.top();
                st.pop();
                s = tranform(s, top, i);
            }
        }
        for(auto i : s)
        {
            if(i != '(' and i != ')')
        {
            cout << i;
        }
        }        
        cout << endl;
    }

}