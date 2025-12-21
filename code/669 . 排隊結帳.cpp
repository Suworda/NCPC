#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    list<int> lst[n+1];
    int x,i,j;
    while(m--){
        string s;
        cin>>s;
        if(s == "ADD"){
            cin>>i>>x;
            lst[i].push_back(x);

        }else if(s == "LEAVE"){
            cin>>i;
            if(lst[i].empty()){
                cout<<"queue "<< i <<" is empty!"<<'\n';
            }else{
                lst[i].erase(lst[i].begin());
            }

        }else{
            cin>>i>>j;
            lst[j].splice(lst[j].end(), lst[i]);

        }
    }

    for(int i=1; i<=n; i++){
        cout<<"queue "<< i;
        if(lst[i].empty()) cout<<": empty"<<'\n';
        else{
            cout<<":";
            for(int &v: lst[i]) cout<<' '<<v;
            cout<<'\n';
        }
    }

}