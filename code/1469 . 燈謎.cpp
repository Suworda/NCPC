#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n, m;
bool ans = 1;
char a[5005][5005];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

void check1(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] == '*'){
                for(int l = j-1; l>=1; l--){
                    if(a[i][l] != '.'){
                        if(a[i][l] == '*') ans = 0;
                        break;
                    }
                }
                for(int r = j+1; j<=m; r++){
                    if(a[i][r] != '.'){
                        if(a[i][r] == '*') ans = 0;
                        break;
                    }
                }

                for(int u=i-1; u>=1; u--){
                    if(a[u][j] != '.'){
                        if(a[u][j] == '*') ans = 0;
                        break;
                    }
                }
                for(int d=i+1; d<=n; d++){
                    if(a[d][j] != '.'){
                        if(a[d][j] == '*') ans = 0;
                        break;
                    }
                }
            }
        }
    }
}

void check2(){
    int need = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] == '.') need++;
        }
    }

    vector<vector<bool>> vis(n+1, vector<bool>(m+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){            
            if(a[i][j] == '*'){
                for(int l = j-1; l>=1; l--){
                    if(a[i][l] != '.') break;
                    vis[i][l] = 1;
                }
                for(int r = j+1; j<=m; r++){
                    if(a[i][r] != '.') break;
                    vis[i][r] = 1;
                }

                for(int u=i-1; u>=1; u--){
                    if(a[u][j] != '.') break;
                    vis[u][j] = 1;
                }
                for(int d=i+1; d<=n; d++){
                    if(a[d][j] != '.') break;
                    vis[d][j] = 1;
                }
            }
        }
    }

    int cnt = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cnt += (vis[i][j]);
        }
    }

    if(cnt != need) ans = 0;
}

void check3(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(isdigit(a[i][j])){
                int cnt = 0;
                for(int dir=0; dir<4; dir++){
                    int nr = i + dr[dir];
                    int nc = j + dc[dir];
                    cnt += (a[nr][nc] == '*');
                }
                if(cnt != (a[i][j] - '0')) ans = 0;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }

    check1();
    check2();
    check3();

    if(ans) cout << "!!\n";
    else cout << "??\n";
}