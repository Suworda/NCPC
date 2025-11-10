#include <iostream>
#include <algorithm>
using namespace std;

long long ans=0;
string s;

void check(int l, int r){
    while(l>=0 && r<s.size() && s[l]==s[r]){
        ans++;
        l--; r++;
    }
    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>s;
    for(int i=0; i<s.size(); i++){
        check(i,i+1);
        check(i,i+2);
    }

    cout<<ans<<'\n';
}
