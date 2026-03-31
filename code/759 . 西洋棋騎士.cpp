#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int dr[]={2,1,-1,-2,2,1,-1,-2};
int dc[]={1,2,2,1,-1,-2,-2,-1};
int n,a,b,C,D,t,x,y;
bool vis[1005][1005];

bool in(int r, int c){
    return r>=1 && r<=n && c>=1 && c<=n;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>a>>b>>C>>D>>t;
    while(t--){
        cin>>x>>y;
        vis[x][y] = 1;
    }

    queue<tuple<int,int,int>> q;
    q.push({a,b,0});
    while(q.size()){
        auto [r,c,cnt] = q.front();
        q.pop();

        if(r == C && c == D){
            cout<<cnt<<'\n';
            return 0;
        }

        for(int i=0; i<8; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(in(nr,nc) && !vis[nr][nc]){
                q.push({nr,nc,cnt+1});
                vis[nr][nc] = 1;
            }
        }
    }

    cout<<-1<<'\n';

}