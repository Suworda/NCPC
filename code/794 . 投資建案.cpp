#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int INF = 2e18;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<array<int,2>> dp(n+5, {-INF,-INF});
        int ans = -INF;
        for(int i=1; i<=n; i++){
            int x;
            cin>>x;
            dp[i][0] = max({x, dp[i-1][0], dp[i-1][0]+x});
            dp[i][1] = max(dp[i][1], dp[i-1][1] + x);
            if(i-2 > 0) dp[i][1] = max(dp[i][1], dp[i-2][0] + x);

            if(i-2 > 0) ans = max(ans, dp[i][1]);
        }
        cout << ans << '\n';
    }

}