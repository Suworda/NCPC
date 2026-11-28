#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;
const ll INF = 4e18;

struct Graph{
    int n;
    vector<vector<pii>> nxt;

    Graph(int _n): n(_n), nxt(n+1) {}

    void add_edge(int a, int b, int c){
        nxt[a].push_back({b, c});
    }

    int get_dis(int s, int t){
        vector<array<int,2>> dis(n+1, {INF, INF});
        vector<array<bool,2>> vis(n+1, {0, 0});

        priority_queue<tiii, vector<tiii>, greater<>> pq;
        pq.push({0, s, 0});

        while(pq.size()){
            auto [cur, u, used] = pq.top(); pq.pop();
            if(vis[u][used]) continue;

            dis[u][used] = cur;
            vis[u][used] = 1;

            for(auto [v, w]: nxt[u]){
                pq.push({cur+w, v, used});
                if(!used) pq.push({cur, v, 1});
            }
            
        }

        int rst = min(dis[t][0], dis[t][1]);
        return rst < INF ? rst : -1;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    Graph g(n);

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        g.add_edge(a, b, c);
    }

    int ans = g.get_dis(s, t);

    cout << ans << '\n';

}