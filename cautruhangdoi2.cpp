#include <bits/stdc++.h>
using namespace std;
void push(queue<int> &qe, int n)
{
    qe.push(n);
}
string print(queue<int> qe)
{
    if(!qe.empty())
    {
        return to_string(qe.front());
    }
    return "NONE";
}
void pop(queue<int> &qe)
{
    if(!qe.empty())
    {
        qe.pop();
    }
}
int main()
{
    int q;
    cin >> q;
    queue<int> qe;
    while(q--)
    {
        string s;
        cin >> s;
        if(s == "PUSH")
        {
            int n;
            cin >> n;
            push(qe, n);
        }
        else if(s == "PRINTFRONT")
        {
            print(qe);
        }
        else if(s == "POP")
        {
            pop(qe);
        }
    }
}