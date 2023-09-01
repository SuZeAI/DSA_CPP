#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
char a[4][4];
int n, m, k;
pair<int,  int> coor[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1},{1, 0}, {1, 1}};
vector<string> ans;
bool check[4][4];
void Try(int row, int col, string  s){
    if(mp[s] == 1) {
        ans.push_back(s);
    }
    for(int i = 0; i < 8; i++){
        row += coor[i].first;
        col += coor[i].second;
        if(row >= 0 and row < m and col >=0 and col < n and check[row][col])
        {
            check[row][col] = false;
            Try(row, col, s + a[row][col]);
            check[row][col] = true;
        }
        row -= coor[i].first;
        col -= coor[i].second;
    }
}
void init()
{
    mp.clear();
    ans.clear();
}
void init1()
{
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            check[i][j] = true;
        }
    }   
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> k >> m >> n;
        init();
        string tmp;
        for(int i = 0;i < k; i++){
            cin >> tmp;
            mp[tmp] = 1;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >>a[i][j];
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                init1();
                Try(i, j, string(1, a[i][j]));
            }
        }
        if(ans.size())
        {
            for(auto i : ans)
                    cout << i << " ";

        }
        else cout << "-1";
        cout << endl;
    }

}