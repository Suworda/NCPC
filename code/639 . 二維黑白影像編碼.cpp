#include <bits/stdc++.h>
using namespace std;

int ans=0;
int id=0;
string s;

void calc(int n){
    char c = s[id++];
    if(c == '1') ans+=n*n;
    else if(c == '2'){
        for(int i=0; i<4; i++) calc(n/2);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int n;
    cin>>s>>n;
    calc(n);

    cout<<ans<<'\n';
}
