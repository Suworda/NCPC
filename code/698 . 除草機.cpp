#include <iostream>
#include <vector>
using namespace std;

int n;
bool a[21][21];
bool b[21][21];
int ans_num=2e9;
vector<int> ans1, ans2;

void check(int i, int j){
    return;
    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            b[r][c]=a[r][c];
        }
    }

    for(int k=0; k<n; k++){
        if((i >> k) & 1){
            for(int x=0; x<n; x++){
                b[k][x]=false;
            }
        }
    }

    for(int k=0; k<n; k++){
        if((j >> k) & 1){
            for(int x=0; x<n; x++){
                b[x][k]=false;
            }
        }
    }

    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            if(b[r][c]) return;
        }
    }

    if(__builtin_popcount(i) + __builtin_popcount(j) < ans_num){
        ans_num=__builtin_popcount(i) + __builtin_popcount(j);

    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    for(int i=0; i<(1 << n); i++){
        for(int j=0; j<(1 << n); j++){
            cout<<i<<' '<<j<<'\n';
//            check(i,j);
        }
    }

    cout<<ans_num<<'\n';
//    for(int i=0; i<n; i++) cout<<ans1[i]<<(i==n-1 ? '\n' : ' ');
//    for(int i=0; i<n; i++) cout<<ans2[i]<<(i==n-1 ? '\n' : ' ');
}
