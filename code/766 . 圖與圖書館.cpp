#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

const int MAXN = 100005;
vector<int> nxt[MAXN];
bitset<MAXN> vis;

pii dfs(int v){
    vis[v] = 1;
    int a=0, b=0; 
    for(int u: nxt[v]){
        if(!vis[u]){
            vis[u] = 1;
            pii p = dfs(u);
            a += p.first;
            b += p.second+1;
        }
    }

    return {a+1,b};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    int x,y;
    for(int i=1; i<=m; i++){
        cin>>x>>y;
        nxt[x].push_back(y);
        nxt[y].push_back(x);
    }

    int ans = m;

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            pii p = dfs(i);
            ans -= min(p.first, p.second);
        }
    }

    cout<<ans<<'\n';
}