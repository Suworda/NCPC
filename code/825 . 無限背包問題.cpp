#include <bits/stdc++.h>
using namespace std;

// long long dp[1005][205];
long long dp[205];
int v[1005];
int w[1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,W;
    cin>>n>>W;
    for(int i=1; i<=n; i++) cin>>w[i];
    for(int i=1; i<=n; i++) cin>>v[i];

    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<=W; j++){
    //         dp[i][j] = dp[i-1][j];
    //         for(int k=1; k<=W; k++){
    //             if(j-w[i]*k >= 0) dp[i][j] = max(dp[i][j], dp[i][j-w[i]*k] + v[i]);
    //         }
    //     }
    // }
    // cout<<dp[n][W]<<'\n';

    for(int i=1; i<=n; i++){
        for(int j=0; j<=W; j++){
            if(j-w[i] >= 0) dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }

    cout<<dp[W]<<'\n';
}