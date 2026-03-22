#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
int a[300005];

bool valid(int k){
    int last = 0;
    for(int i=0; i<n; i++){
        int x = a[i];
        if(x + k >= m){
            if((x+k)%m < last) last = max(last,x);
            
        }else{
            if(x + k < last) return false;
            if(x > last) last = x;
        }
    }

    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int l = 0, r = m;
    int ans = -1;
    while(l <= r){
        int mid = (l+r)/2;
        if(valid(mid)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }

    cout<<ans<<'\n';

}