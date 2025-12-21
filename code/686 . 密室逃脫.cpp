#include <bits/stdc++.h>
using namespace std;

int main(){
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

    for(int i=0; i<n; i++){
        for(int j=i+1, l=j+1, r=n-1; j<n; j++){
            long long targ = m - a[i] - a[j];
            
        }
    }

    cout<<ans<<'\n';

}