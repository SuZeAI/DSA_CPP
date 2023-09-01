#include <bits/stdc++.h>
using namespace std;

struct job{
    int id;
    int deadline;
    int profit;
};

bool cmp(job a, job b){
    return a.profit > b.profit;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<job> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i].id >> a[i].deadline >> a[i].profit;
        }
        sort(a.begin(), a.end(), cmp);
        vector<bool> used(n, false);
        int mark[n];
        int res = 0, sum = 0;
        for(int i = 0; i <= n - 1; i++){
            for(int j = a[i].deadline - 1; j >= 0; j--){
                if(!used[j]){
                    used[j] = true;
                    mark[j] = i; // Viec i duoc thuc hien o thoi gian j
                    sum += a[i].profit;
                    break;
                }
            }
        }
        for(int i = 0; i <= n - 1; i++){
            if(used[i]) res++;
        }
        cout << res << " " << sum << endl;
    }
    return 0;
}