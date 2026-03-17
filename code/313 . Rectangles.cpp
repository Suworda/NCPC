#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long

int n;
char a[5005][5005];
int p[5005][5005];
ll ans=0;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
        }
    }

    for(int j=1; j<=n; j++){
        int x=n;
        for(int i=1; i<=n; i++){
            if(a[i][j] == '#') x = n-i;
            p[i][j] = x;
        }
    }

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout<<p[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    // cout<<'\n';

    for(int i=1; i<=n; i++){
        ll dp[5005]={};
        int stk[5005]={};
        int top = 0;
        stk[++top] = 0;


        for(int j=1; j<=n; j++){
            if(a[i][j] == '.'){
                while(top && p[i][j] < p[i][stk[top]]){
                    top--;
                }
                ans += max(p[i][j] - (n-i), 0LL) * (j - stk[top]) + dp[stk[top]];
                dp[j] = max(p[i][j] - (n-i), 0LL) * (j - stk[top]) + dp[stk[top]];
            }
            stk[++top] = j;
            // cout<<ans<<' ';
        }
        // cout<<'\n';
    }

    cout<<ans<<'\n';

}