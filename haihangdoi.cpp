#include <bits/stdc++.h>
using namespace std;
void PUSHFRONT(deque<int> &dq, int x)
{
    dq.push_front(x);
}
void PRINTFRONT(deque<int> dq)
{
    if(!dq.empty())
    {
        cout << dq.front() << endl;
    }
    else
    {
        cout << "NONE\n"; 
    }
}
void POPFRONT(deque<int> &dq)
{
    if(!dq.empty())
    {
        dq.pop_front();
    }
}
void PUSHBACK(deque<int> &dq, int x)
{
    dq.push_back(x);
}
void PRINTBACK(deque<int> dq)
{
    if(!dq.empty())
    {
        cout << dq.back() << endl;
    }
    else
    {
        cout << "NONE\n"; 
    }
}
void POPBACK(deque<int> &dq)
{
    if(!dq.empty())
    {
        dq.pop_back();
    }
}
int main()
{
    int q;
    cin >> q;
    deque<int> dq;
    while(q--)
    {
        string s;
        cin  >> s;
        if(s == "PUSHFRONT"){
            int n;
            cin >> n;
            PUSHFRONT(dq, n);
        } 
        if(s == "PRINTFRONT") PRINTFRONT(dq);
        if(s == "POPFRONT") POPFRONT(dq);
        if(s == "PUSHBACK") {
            int n;
            cin >> n;
            PUSHBACK(dq,n);
        }
        if(s == "PRINTBACK") PRINTBACK(dq);
        if(s == "POPBACK") POPBACK(dq);
    }   
}