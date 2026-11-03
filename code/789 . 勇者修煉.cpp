#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int INF = 1e18;

int n,m;
int a[55][10005];
int dp[55][10005];
int dp1[55][10005];
int dp2[55][10005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }

    for(int j=1; j<=m; j++) dp1[1][j] = max(dp1[1][j-1], 0LL) + a[1][j];
    for(int j=m; j>=1; j--) dp2[1][j] = max(dp2[1][j+1], 0LL) + a[1][j];
    for(int j=1; j<=m; j++) dp[1][j] = max(dp1[1][j], dp2[1][j]);

    for(int i=2; i<=n; i++){
        for(int j=1; j<=m; j++) dp[i][j] = dp[i-1][j] + a[i][j];
        
        dp1[i][1] = dp[i-1][1] + a[i][1];
        for(int j=2; j<=m; j++) dp1[i][j] = max(dp[i][j], dp1[i][j-1] + a[i][j]);

        dp2[i][m] = dp[i-1][m] + a[i][m];
        for(int j=m-1; j>=1; j--) dp2[i][j] = max(dp[i][j], dp2[i][j+1] + a[i][j]);

        for(int j=1; j<=m; j++) dp[i][j] = max(dp1[i][j], dp2[i][j]);
    }

    int ans = -INF;
    for(int j=1; j<=m; j++) ans = max(ans, dp[n][j]);
    cout << ans << '\n';

}