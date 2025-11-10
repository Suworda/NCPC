#include <bits/stdc++.h>>
using namespace std;

#define int long long

struct Item{
    int v,w;

    bool operator> (const Item &b) const{
        return v*b.w > w*b.v;
    }
};

signed main(){
    long long ans=0;
    int n,m;
    cin>>n>>m;
    int v,w;
    vector<Item> a;
    for(int i=0; i<n; i++){
        cin>>v>>w;
        a.push_back({v,w});
    }
    //cout<<a[0].v<<'\n';
    sort(a.begin(), a.end(),greater<Item>());

    for(int i=0; i<n; i++){
        //cout<<a[i].w<<'\n';
        if(m>=a[i].w){
            ans+=(m / a[i].w)*(a[i].v);
            m%=a[i].w;
        }
    }
    cout<<ans<<'\n';
}

/*
3
7 1 3
8 6 4 4 4 1 7
*/
