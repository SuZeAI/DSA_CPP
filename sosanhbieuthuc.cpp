#include <bits/stdc++.h>
using namespace std;
string solution(string s, int n)
{
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(s[i] == '(')
        {
            st.push(i);
        }
        else if(s[i] == ')')
        {
            int top = st.top(); st.pop();
            if(top > 0)
            {
                if(s[top - 1] == '-')
                {
                    for(int j = top; j < i; j++){
                        if(s[j] == '+') s[j] = '-';
                        else if(s[j] == '-') s[j] = '+';
                    }
                }
            }
        }
    }
    string tmp;
    for(auto i : s)
    {
        if(i != '(' and i != ')')
        {
            tmp += i;
        }
    }
    return tmp;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        if(solution(s1, s1.length()) == solution(s2, s2.length())) cout << "YES\n";
        else cout << "NO\n";
    }

}