#include <bits/stdc++.h>
using namespace std;
int snt[100005] = {0};
void init()
{
    snt[1] = 1;
    snt[0] = 1;
    for(int i = 2; i * i < 100005; i++)
    {
        if(!snt[i])
        {
            for(int j = i * i; j < 100005; j+= i)
            {
                snt[j] = 1;
            }
        }
    }    
}
int main(){
    init();
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >>  s1 >> s2;
        set<string> s;
        queue<pair<string, int>> qe;
        qe.push({s1, 0});
        s.insert(s1);
        while(!qe.empty())
        {
            pair<string, int> front = qe.front(); qe.pop();
            if(front.first == s2)
            {
                cout << front.second << endl;
                break;
            }
            front.second++;
            for(int i = 3; ~i; i--)
            {
                for(int j = 0; j < 10; j++)
                {
                    if(i == 0 and j == 0) continue;
                    string tmp = front.first; 
                    if(j != tmp[i] - '0')  
                    {
                        tmp[i] = char(j + 48);
                        if(!snt[stoi(tmp)] and s.find(tmp) == s.end()){
                            s.insert(tmp);
                            qe.push({tmp, front.second});
                        }
                    }
                }
            }
        }
    }

}