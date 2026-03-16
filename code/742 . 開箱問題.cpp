#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int a[100005];
ll ans=0;
vector<int> stk(100005), l(100005), r(100005);
int mi = 2e9;
int p;

void dfs(int u, int x, int y){
    ans += a[u]*(u-x)*(y-u);
    // cout<<u<<' '<<l[u]<<' '<<r[u]<<' '<<ans<<'\n';
    if(l[u]) dfs(l[u],x,u);
    if(r[u]) dfs(r[u],u,y);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(a[i] < mi){
            mi = a[i];
            p = i;
        }
    }
    
//set
    // int id[n+5];
    // iota(id, id+n+1, 0);
    // sort(id, id+n+1, [](int x, int y){
    //     return a[x] < a[y];
    // });
    
    // set<int> st{0,n+1};
    // for(int i=1; i<=n; i++){
    //     auto it1 = st.lower_bound(id[i]); it1--;
    //     auto it2 = st.upper_bound(id[i]);
    //     ll x = *it1, y = *it2;
    //     ans += (id[i]-x)*(y-id[i])*a[id[i]];
    //     // cout<<x<<' '<<y<<' '<<ans<<'\n';
    //     st.insert(id[i]);
    // }

//笛卡爾樹
    int top = -1;
    for(int i=1; i<=n; i++){
        int last = 0;
        while(top != -1 && a[i] < a[stk[top]]){
            last = stk[top];
            top--;
        }

        if(last) l[i] = last;
        if(top != -1) r[stk[top]] = i;

        stk[++top] = i;
    }

    dfs(p,0,n+1);


    cout<<ans<<'\n';
}