#include <bits/stdc++.h>
using namespace std;
int main(){
    queue<pair<set<int>, int>> qe;
    vector<int> v(100009,0);
    map<int, int> mp;
    for(int i = 1; i <= 5; i++)
    {
        qe.push({{i}, i});
    }
    while(!qe.empty())
    {
        pair<set<int>, int> fr = qe.front(); qe.pop();
        mp[fr.second] = 1;
        for(int i = 0; i <= 5; i++)
        {
            if(fr.first.find(i) == fr.first.end()) 
            {
                set<int> tmp = fr.first;
                tmp.insert(i);
                qe.push({tmp, fr.second * 10 + i});
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= 1000; i++)
    {
        if(mp[i] == 1)
        {
            ans++;
        }
        v[i] = ans;
    }

    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >>l >> r;
            cout << v[r] - v[l - 1]<< endl;

    }
}