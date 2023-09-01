#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> s;
        queue<pair<int, int>> qe;
        qe.push({n, 0});
        s.insert(n);
        while(!qe.empty())
        {
            pair<int, int> front = qe.front(); qe.pop();
            if(front.first == 1) 
            {
                cout << front.second << endl;
                break;
            }
            front.second++;
            int x = front.first;
            if(s.find(x - 1) == s.end())
            {
                s.insert(x - 1);
                qe.push({x - 1, front.second});
            }
            for(int i = 2; i * i <= x; i++)
            {
                if(x % i == 0)
                {
                    if(s.find(x/i) == s.end())
                    {
                        s.insert(x/i);
                        qe.push({x/i, front.second});
                    }
                }
            }
        }
    }
}