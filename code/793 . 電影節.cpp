#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    int ans = 0;
    vector<array<int,2>> dp(n+5);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        dp[i][0] = x + max(dp[i-1][0], (i-2 >= 0 ? dp[i-2][1] : 0));
        dp[i][1] = x*2 + max(dp[i-1][0], (i-2 >= 0 ? dp[i-2][1] : 0));
        ans = max({ans, dp[i][0], dp[i][1]});
    }
    
    cout << ans << '\n';
}