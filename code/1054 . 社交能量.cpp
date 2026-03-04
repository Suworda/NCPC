#include <bits/stdc++.h>
using namespace std;

int n;
int d[1000005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        int l,r;
        cin>>l>>r;
        d[l]++;
        d[r]--;
    }

    long long cur=0;
    long long ans=0;
    for(int i=1; i<=1000000; i++){
        cur += d[i];
        ans += (cur)*(cur-1)/2;
    }

    cout<<ans<<'\n';


}