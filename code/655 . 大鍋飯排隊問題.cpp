#include <bits/stdc++.h>
using namespace std;

int k[1000005];
list<int>::iterator ptr[100005];

void sol(){
    int n,q;
    cin>>n>>q;
    unordered_multiset<int> mst;

    for(int i=0; i<n; i++){
        int c;
        cin>>c;
        for(int j=0; j<c; j++){
            int x;
            cin>>x;
            k[x] = i;
        }
    }

    list<int> lst;
    
    while(q--){
        int ty;
        cin>>ty;
        if(ty == 1){
            int x;
            cin>>x;
            if(mst.find(k[x]) != mst.end()){
                ptr[k[x]] = lst.insert(next(ptr[k[x]]), x);

            }else{
                lst.push_back(x);
                ptr[k[x]] = prev(lst.end());
            }
            mst.insert(k[x]);

        }
        else{
            if(lst.empty()) cout<<-1<<'\n';
            else{
                cout<<*lst.begin()<<'\n';
                mst.erase(mst.find(k[*lst.begin()]));
                lst.erase(lst.begin());
            }
        }
    }

    return;

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

}