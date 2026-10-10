#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<int> dp(n+5);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        if(i <= 2) dp[i] = dp[1] + x;
        else dp[i] = max(dp[i-1], dp[i-2]) + x;
    }

    cout << dp[n] << '\n';

}