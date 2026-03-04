#include <bits/stdc++.h>
using namespace std;

pair<int,int> p[200005];

vector<int> dp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>p[i].first>>p[i].second;
    }
    sort(p+1, p+1+n);

    for(int i=1; i<=n; i++){
        int y = p[i].second;
        auto it = upper_bound(dp.begin(), dp.end(), y);
        
        if(it == dp.end()) dp.push_back(y);
        else *it = y;
    }

    cout<<dp.size()<<'\n';

}