#include <bits/stdc++.h>
using namespace std;

int f(int t){
    if(t==1 || t==3) return 1;
    else if(t<0) return 0;
    return f(t-5) + f(t-3);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int t;
    cin>>t;
    cout<< f(t) <<'\n';
}
