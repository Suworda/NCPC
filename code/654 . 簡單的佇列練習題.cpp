#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    queue<int> que;
    
    int m;
    cin>>m;
    while(m--){
        int ty;
        cin>>ty;
        if(ty==1){
            int n;
            cin>>n;
            que.push(n);

        }else if(ty==2){
            if(que.empty()) cout<<"QQ\n";
            else que.pop();
            
        }else if(ty==3){
            if(que.empty()) cout<<"QQ\n";
            else cout<<que.front()<<'\n';

        }else if(ty==4){
            cout<<que.size()<<'\n';
        }
    }

}