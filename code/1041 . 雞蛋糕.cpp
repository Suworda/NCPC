#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int n;
char A[15][15];
int ans = 0;

bool in(int r, int c){
    return r >= 1 && c >= 1 && r <= n && c <= n;
}

void check(int mask){
    char a[15][15] = {};
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            a[i][j] = A[i][j];
        }
    }

    bitset<25> rev;
    for(int i=0; i<2*n; i++){
        rev[i+1] = ((mask >> i) & 1);
    }

    for(int i=1; i<=n; i++){
        if(rev[i]){
            int r = i;
            for(int c=1; c<=n; c++){
                a[r][c] = ('H' + '.') - a[r][c];
            }
        }
    }
    
    for(int i=n+1; i<=2*n; i++){
        if(rev[i]){
            int c = i-n;
            for(int r=1; r<=n; r++){
                a[r][c] = ('H' + '.') - a[r][c];
            }
        }
    }

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << a[i][j];
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    bool vis[15][15] = {};
    auto dfs = [&](auto &&dfs, int r, int c){
        if(vis[r][c] || !in(r, c) || a[r][c] == 'H') return;

        if(r == n && c == n){
            cout << "Yes\n";
            exit(0);
        }

        vis[r][c] = 1;
        for(int dir=0; dir<4; dir++){
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            dfs(dfs, nr, nc);
        }

    };

    dfs(dfs, 1, 1);

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> A[i][j];
        }
    }

    for(int i=0; i<(1<<(2*n)); i++){
        check(i);
    }
    
    cout << "No\n";

}