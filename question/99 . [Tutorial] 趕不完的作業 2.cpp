#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,l;
    cin>>n>>l;

    int d[n];
    for(int i=0; i<n; i++){
        cin>>d[i];
    }
    sort(d,d+n);

    int curt=0;
    int ans=0;
    for(int i=0; i<n; i++){
        if(curt+l<=d[i]){
            ans++;
            curt+=l;
        }
    }

    cout<<ans<<'\n';
}

/*
5 5
1 2 3 4 5
6 7 8 9 10
*/

