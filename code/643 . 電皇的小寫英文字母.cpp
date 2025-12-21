#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s, t;
    pair<int,int> seg;
    cin>>s;
    int n = s.size();
    int cnt[128]={};
    int cur=0;
    int mi = 2e9;
    for(int l=0, r=-1; l<n; l++){
        while(r < n-1 && cur != 26 && cur + (cnt[s[r+1]] == 0) <= 26){
            //cout<<l<<' '<<r+1<<' '<<t<<'\n';
            if(cnt[s[r+1]] == 0) cur++;
            cnt[s[r+1]]++;
            r++;
            t += s[r];
        }

        if(cur == 26 && r - l +1 < mi){
            mi = r - l +1;
            seg={l,r};
        }

        if(cnt[s[l]] == 1) cur--;
        cnt[s[l]]--;
    }

    if(seg != make_pair(0,0)){
        for(int i=seg.first; i<=seg.second; i++){
            cout<<s[i];
        }
        cout<<'\n';

    }else{
        cout<<"QQ"<<'\n';
    }

}