#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    int a;
    cin>>a;
    int tmp;
    cin>>tmp;
    int b = -2e9;

    for(int i=3; i<=n; i++){
        int x;
        cin>>x;
        tie(a, b) = make_pair(max(b, a), a+x);
    }

    cout<<b<<'\n';




}