#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-3; i>=0; i--){
        if(a[i]+a[i+1]>a[i+2]){
            cout<<a[i]<<' '<<a[i+1]<<' '<<a[i+2]<<'\n';
            return 0;
        }
    }
    cout<<-1<<'\n';
}

