#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a, a+n);

    long long ans=0;

    for(int i=0; i<n-2; i++){
        int l=n-1, r=n-1;
        for(int j=i+1; j<n-1; j++){
            long long tg = m - a[i] - a[j];
            
            while(l-1 > j && a[l-1] >= tg){
                l--;
            }

            while(a[r] != tg && r-1 >= l && a[r-1] >= tg){
                r--;
            }

            l = max(l, j+1);

            if(a[l] == tg && a[r] == tg){
                //cout<<i+1<<' '<<j+1<<' '<<l+1<<' '<<r+1<<'\n';
                ans += (r-l+1);
            }
        }

    }

    cout<<ans<<'\n';

}