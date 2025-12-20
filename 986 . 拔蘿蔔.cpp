#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 100005;
ll a[MAXN];
ll w[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    ll k;
    cin>>n>>k;
    priority_queue<pair<ll,int>> pq;
    ll ans = 0;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>w[i];
        ans += a[i]*w[i];
        pq.push({(a[i]+1)/2 * w[i],i});
        a[i]/=2;
    }

    while(ans && k--){
        auto [v,id] = pq.top();
        pq.pop();
        //cout<<id<<' '<<v<<'\n';

        ans -= v;
        pq.push({(a[id]+1)/2 * w[id] , id});
        a[id]/=2;
    }

    cout<<ans<<'\n';

}