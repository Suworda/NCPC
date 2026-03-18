#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int h[200005], p[200005], s[200005];
pair<int,int> stk[200005];
int top = 0;
ll ans=0;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++) cin>>h[i];
    for(int i=1; i<=n; i++) cin>>p[i];
    for(int i=1; i<=n; i++) s[i] = h[i] + p[i];

    for(int i=1; i<=n; i++){
        auto it = lower_bound(stk+1, stk+top+1, make_pair(s[i],i), greater<>());
        ans += i - (*prev(it)).second-1;

        while(top && h[i] >= stk[top].first) top--;
        
        stk[++top] = {h[i], i};
    }

    cout<<ans<<'\n';

}