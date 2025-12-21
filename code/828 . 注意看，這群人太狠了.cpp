#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 100005;
vector<pair<int,int>> nxt[MAXN];
bitset<MAXN> vis;
int disv[MAXN], disu[MAXN], dis[MAXN];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++){
        int a,b,w;
        cin>>a>>b>>w;
        nxt[a].push_back({b,w});
        nxt[b].push_back({a,w});
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    pair<int,int> ma;

    while(q.size()){
        int v = q.front();
        q.pop();

        for(auto[u,w]: nxt[v]){
            if(!vis[u]){
                dis[u] = dis[v]+w;
                vis[u] = 1;
                ma = max(ma, {dis[u],u});
                q.push(u);
            }
        }
    }

    vis.reset();
    int st = ma.second;
    ma = {};

    q.push(st);
    vis[st] = 1;

    while(q.size()){
        int v = q.front();
        q.pop();

        for(auto[u,w]: nxt[v]){
            if(!vis[u]){
                disv[u] = disv[v]+w;
                vis[u] = 1;
                ma = max(ma, {disv[u],u});
                q.push(u);
            }
        }
    }

    vis.reset();
    st = ma.second;
    ma = {};

    q.push(st);
    vis[st] = 1;

    while(q.size()){
        int v = q.front();
        q.pop();

        for(auto[u,w]: nxt[v]){
            if(!vis[u]){
                disu[u] = disu[v]+w;
                vis[u] = 1;
                q.push(u);
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout<<max(disv[i], disu[i])<<' ';
    }
    cout<<'\n';

}