#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
int N;
bitset<17> slash; 
bitset<17> bslash; 
bitset<17> col; 
int t2_slash[17]; 
int t2_bslash[17]; 
int ans = 0;

void dfs(int id, int rn, int rm){
    if(id > N){
        ans++;
        return;
    }

    for(int i=1; i<=N; i++){
        if(!slash[id+i] && !bslash[id-i+N] && !col[i] && !t2_slash[id+i] && !t2_bslash[id-i+N] && rn){
            slash[id+i] = 1;
            bslash[id-i+N] = 1;
            col[i] = 1;
            dfs(id+1, rn-1, rm);
            slash[id+i] = 0;
            bslash[id-i+N] = 0;
            col[i] = 0;
        }
        if(!slash[id+i] && !bslash[id-i+N] && !col[i] && rm){
            t2_slash[id+i] ++;
            t2_bslash[id-i+N] ++;
            col[i] = 1;
            dfs(id+1, rn, rm-1);
            t2_slash[id+i]--;
            t2_bslash[id-i+N]--;
            col[i] = 0;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    N = n+m;

    dfs(1, n, m);

    cout<<ans<<'\n';

}