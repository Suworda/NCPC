#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};
int n,m;
bool vis[55][55];
char a[55][55];
vector<pair<int,int>> path;
pair<int,int> S;

bool valid(int r, int c){
    return r>=0 && r<n && c>=0 && c<m && !vis[r][c] && a[r][c] != '1';
}

void dfs(int r, int c){
    if(!valid(r,c)) return;
    vis[r][c] = 1;
    path.push_back({r,c});

    if(a[r][c] == '3'){
        cout<<path.size()<<'\n';
        for(auto &[r,c]: path) cout<<r<<' '<<c<<'\n';
        exit(0);
    }

    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        dfs(nr,nc);
    }
    vis[r][c] = 0;
    path.erase(path.end());


}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            if(a[i][j] == '2') S = {i,j};
        }
    }

    dfs(S.first, S.second);
    
    cout<<0<<'\n';

}