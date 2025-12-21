#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);

    do{
        for(int i=0; i<n; i++){
            cout << a[i] << (i==n-1 ? '\n' : ' ');
        }
    }while(next_permutation(a,a+n));
}
