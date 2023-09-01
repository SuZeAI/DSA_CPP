#include <bits/stdc++.h>
using namespace std;
struct cap{
    int x, y;
};
void stak(stack<cap> &st, string s)
{
    int num = 0;
    vector<int> v;
    for(int i = 0;i < s.length(); i++){
        if(isdigit(s[i]))
        {
            num = num * 10 + s[i] - '0';
        }
        else{

            if(num)
                v.push_back(num);
            num = 0;
        }
    }
    if(s[s.length() - 1] == '0') v.push_back(0);
    for(int i = 0; i < v.size(); i += 2)
    {
        cap tmp;
        tmp.x = v[i];
        tmp.y = v[i + 1];
        st.push(tmp);
    }
}
int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        stack<cap> st1, st2, st;
        stak(st1, s1);
        stak(st2, s2);
        while(!st1.empty() and !st2.empty())
        {
            cap tmp1 = st1.top();
            cap tmp2 = st2.top();
            cap tmp3;
            if(tmp1.y == tmp2.y)
            {
                tmp3.x = tmp1.x + tmp2.x;
                tmp3.y = tmp1.y;
                st1.pop();
                st2.pop();
            }
            else if(tmp1.y > tmp2.y)
            {
                tmp3.y = tmp2.y;
                tmp3.x = tmp2.x;
                st2.pop();
            }
            else if(tmp1.y < tmp2.y)
            {
                tmp3.y = tmp1.y;
                tmp3.x = tmp1.x;    
                st1.pop();            
            }
            st.push(tmp3);
        }
        while(!st1.empty())
        {
            cap tmp = st1.top();st1.pop();
            st.push(tmp);
        }
        while(!st2.empty())
        {
            cap tmp = st2.top();st2.pop();
            st.push(tmp);
        }        
        cap tmp = st.top(); st.pop();
        cout << tmp.x << "*x^" << tmp.y;
        while(!st.empty())
        {
            tmp = st.top(); st.pop();
            cout << " + " << tmp.x << "*x^" << tmp.y ;
        }
        cout << endl;
    }
}