// #include <bits/stdc++.h>
// using namespace std;
// #define faster() \
//         ios_base::sync_with_stdio(0); \
//         cin.tie(0); \
//         cout.tie(0)
// int main()
// {
//     faster();
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n;
//         cin >> n;
//         vector<int> v(n + 1), vec(n + 1);
//         for(int i = 1; i <= n; i++)
//         {
//             cin >> v[i];
//         }
//         vec[1] = v[1];
//         for(int i = 1; i <= n; i++)
//         {
//             vec[i] = v[i];
//             for(int j = 1; j < i; j++ )
//             {
//                 if(v[i] > v[j] and vec[i] < vec[j] + v[i])
//                 {
//                     vec[i] = vec[j] + v[i];
//                 }
//             }
//         }

//         cout << *max_element(vec.begin(), vec.end()) << endl;

//     }
// }