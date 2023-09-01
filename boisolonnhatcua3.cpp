#include <bits/stdc++.h>
using namespace std;
bool key(char a, char b)
{
    return a > b;
}
int main(){
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       string s, tmp;
       int sum = 0;
       for(int i = 0; i < n; i++){
            cin >> tmp;
            s += tmp;
            sum += stoi(tmp);
        }
        sort(s.begin(), s.end(), key);
        map<string, int> mp;
        queue<pair<string, int>> qe;
        qe.push({s, sum});
        mp[s] = 1; 
        while(!qe.empty()){
            pair<string , int> front = qe.front(); qe.pop();
            if(front.second % 3 == 0) {
                if(front.first != "")
                    cout << front.first << endl;
                else cout << -1 << endl;
                break;
            }
            for(int i = front.first.length()- 1; ~i; i--)
            {
                string tmp = front.first;
                tmp.erase(tmp.begin() + i);
                if(mp[tmp] == 0){
                    mp[tmp] = 1;
                    qe.push({tmp, front.second - stoi(string(1,front.first[i]))});
                }
            }
        }

    }
}