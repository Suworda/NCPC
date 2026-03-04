#include <bits/stdc++.h>
using namespace std;

int n;
char a[2005][2005];
int sum[2005][2005];
int cnt_0[2005][2005];
int ans = 0;

bool valid(int r, int c, int m){
    return cnt_0[r][c] - cnt_0[r-m][c] - cnt_0[r][c-m] + cnt_0[r-m][c-m] == 0; 
}

void try_(int R, int C){
    int rst = -1;
    int l = 0;
    int r = min(R,C);
    while(l <= r){
        int m = (l+r)/2;
        if(valid(R, C, m)){
            rst = m;
            l = m+1;
        }else{
            r = m-1;
        }
    }

    ans = max(ans, sum[R][C] - sum[R][C-rst] - sum[R-rst][C] + sum[R-rst][C-rst]);
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j]-'0';
            cnt_0[i][j] = cnt_0[i-1][j] + cnt_0[i][j-1] - cnt_0[i-1][j-1] + (a[i][j] == '0');
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            try_(i,j);
        }
    }
    
    cout<<ans<<'\n';

}