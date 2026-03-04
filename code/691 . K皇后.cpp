#include <bits/stdc++.h>
using namespace std;

int n;
bitset<35> ok1, ok2, ok3;
int ans=0;
char c[15][15];

void print(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<c[i][j];
        }
        cout<<'\n';
    }
    cout<<'\n';
}

void place(int r){

    // cout<<r<<' '<<c<<'\n';

    if(r == n) print();

    r++;
    for(int i=1; i<=n; i++){
        if(ok1[r+i] && ok2[r-i+n] && ok3[i]){
            ok1[r+i] = 0;
            ok2[r-i+n] = 0;
            ok3[i] = 0;
            c[r][i] = 'Q';

            place(r);

            c[r][i] = '*';
            ok1[r+i] = 1;
            ok2[r-i+n] = 1;
            ok3[i] = 1;
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    ok1.set(); ok2.set(); ok3.set();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            c[i][j] = '*';
        }
    }
    for(int i=1; i<=n; i++){
        ok1[1+i] = 0;
        ok2[1-i+n] = 0;
        ok3[i] = 0;
        c[1][i] = 'Q';

        place(1);

        c[1][i] = '*';
        ok1[1+i] = 1;
        ok2[1-i+n] = 1;
        ok3[i] = 1;
    }

}