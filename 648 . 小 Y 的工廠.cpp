#include <iostream>
#include <algorithm>
using namespace std;

long long base=0, cur=0, ans=0;
int n;
long long a[5005],b[5005];

void check(int l, int r){
    cur=base;
    while(l>=0 && r<n){
        cur += 1LL * (a[l]-a[r]) * (b[r]-b[l]);
        l--;
        r++;
        ans=max(ans,cur);
    }
}

int main(){
//    cin.tie(0);
//    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
        base+=a[i]*b[i];
    }
    ans=base;

    //O(n^3)
//    for(int l=0; l<n; l++){
//        for(int r=0; r<n; r++){
//            reverse(a+l,a+r+1);
//            cur=0;
//            for(int j=0; j<n; j++){
//                cur+=a[j]*b[j];
//            }
//            ans=max(ans,cur);
//            reverse(a+l,a+r+1);
//        }
//    }

    //O(n^2)
    for(int l=0; l<n; l++){
        check(l,l+1);
        check(l,l+2);
    }


    cout<<ans<<'\n';
}

/*
6
1 100 133146 1213 444 4567894
10000000 231234 45644 89779 9999999 121322
*/
