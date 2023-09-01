#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll number_of_money(vector<ll> v, ll money)
{
    ll cnt = 0;
    for(int i = v.size() - 1; i >= 0; i--){
        if(money >= v[i]){
            ll tmp = money/v[i];
            cnt += tmp;
            money -= tmp * v[i];
        }
    }
    if(money) return 0;
    return cnt;
}
void Types_of_banknotes(vector<ll> &v, ll money, ll c){
    ll i = 0;
    while(i <= c){
        ll tmp = 1000 * pow(10, i);
        v.push_back(tmp);
        tmp = 2000 * pow(10, i);
        v.push_back(tmp);
        tmp = 3000 * pow(10, i);
        v.push_back(tmp);
        tmp = 5000 * pow(10, i);
        v.push_back(tmp);     
        i++;                   
    }
}
void solution(){
    map<int, int> mp = {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 2}, {5, 1}, {6, 2},{7, 1}, {8, 1}, {9, 3}};
    ll money, c;
    cin >> money >> c;
    vector<ll> v;
    Types_of_banknotes(v, money, c);
    if(money % 1000 == 0)
    {
        ll numsBanknotes = number_of_money(v, money);
        cout << numsBanknotes << " ";
        ll ans = 1;
        for(int i = 0; i < 3 + c; i++)
        {
            int tmp = money % 10;
            ans *= mp[tmp];
            money /= 10;
        }
        if(mp[money] != 0) ans *= mp[money];
        else{
            if(money % 5 == 1)
            {
                ans *= 2;
            }
            else if(money % 5 == 4){
                ans *= 3;
            }

        }
            cout << ans;
    }
    else{
        cout << 0;
    }
    
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solution();
        cout << endl;
    }
}