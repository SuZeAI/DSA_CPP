#include <bits/stdc++.h>
using namespace std;
string remove(string s, int a, int b)
{
    string tmp="";
    for(int i = 0; i < s.length(); i++)
    {
        if(i != a and i != b)
        {
            tmp += s[i];
        }
    }
    return tmp;
}
map<string, int> mp;
void solution(set<string> &v, queue<string> &qe, string s)
{
    stack<int> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(')
        {
            st.push(i);
        }
        else if(s[i] == ')'){
            int top = st.top(); st.pop(); 
            string tmp = remove(s, top, i);
            if(mp[tmp] == 0)
            {
                mp[tmp] = 1;
                v.insert(tmp);
                qe.push(tmp);
            }
        }
    }
}
int main(){
    string s;
    cin >> s;
    queue<string> qe;
    set<string> v;
    solution(v, qe, s);
    while(!qe.empty())
    {
        string tmp = qe.front(); qe.pop();
        solution(v, qe, tmp);
    }
    for(auto i : v)
    {
        cout << i << endl;
    }
}