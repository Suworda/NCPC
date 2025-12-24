#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k;
    cin>>n>>k;
    pair<int,int> a[n+1];
    for(int i=1; i<=n; i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+n+1);

    int ans=2e9;
    priority_queue<int> pq;

    for(int i=1; i<=n; i++){
        auto [x,y] = a[i];

        if(i < k){
            pq.push(y);

        }else if(i > k && y < pq.top()){
            pq.pop();
            pq.push(y);
            ans = min(ans, x + pq.top());
            
        }else if(i == k){
            pq.push(y);
            ans = min(ans, x + pq.top());

        }
    }

    cout<<ans<<'\n';

}