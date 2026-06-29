#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int M = 1e9+7;
int n;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    int cur = 1, last = 1;
    for(int i=2; i<=n; i++){
        tie(cur, last) = make_pair((cur+last)%M, cur);
    }

    cout<<cur<<'\n';

}