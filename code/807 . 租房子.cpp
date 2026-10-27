#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Seg{
    int l, r, p, ori_id;
};

int n;
Seg a[1005];
int dp[100005];
vector<int> from[10005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin >> a[i].l >> a[i].r >> a[i].p;
        a[i].ori_id = i+1;
    } 

    sort(a, a+n, [](Seg x, Seg y){
        return x.r < y.r;
    });

    // for(int i=0; i<n; i++) cout << a[i].l << ' ' << a[i].r << ' ' << a[i].p << '\n';

    int id = 0;
    for(int i=1; i<=10000; i++){
        dp[i] = dp[i-1];
        from[i] = from[i-1];

        while(id < n && a[id].r == i){
            auto [l, r, p, ori_id] = a[id];
            if(dp[l-1] + p > dp[i]){
                dp[i] = dp[l-1] + p;
                from[i] = from[l-1];
                from[i].push_back(ori_id);
            }
            id++;
        }
    }

    cout << dp[10000] << ' ' << from[10000].size() << '\n';
    for(int x: from[10000]) cout << x << ' ' ;
}