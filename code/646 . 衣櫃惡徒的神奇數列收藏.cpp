#include <bits/stdc++.h>
using namespace std;

bitset<1000005> apr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    pair<int,int> ans;
    int ma=0;
    for(int l=0, r=-1; l<n; l++){
        while(r+1 < n && !apr[a[r+1]]){
            r++;
            apr[a[r]] = true;
        }
        if(r-l+1 > ma){
            ma = r-l+1;
            ans = {l,r};
        }
        apr[a[l]] = false;
    }

    for(int i=ans.first; i<=ans.second; i++){
        cout << a[i] << (i == ans.second ? '\n' : ' ');
    }

}