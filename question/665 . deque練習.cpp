#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    deque<int> dq;
    int n;
    cin>>n;
    while(n--){
        int ty;
        cin>>ty;
        if(ty==1){
            int x;
            cin>>x;
            dq.push_back(x);

        }else if(ty==2){
            int x;
            cin>>x;
            dq.push_front(x);

        }else if(ty==3){
            if(dq.empty()) cout<<"error\n";
            else cout<<dq.back()<<'\n';

        }else if(ty==4){
            if(dq.empty()) cout<<"error\n";
            else cout<<dq.front()<<'\n';

        }else if(ty==5){
            if(dq.empty()) cout<<"error\n";
            else dq.pop_back();

        }else if(ty==6){
            if(dq.empty()) cout<<"error\n";
            else dq.pop_front();

        }else if(ty==7){
            cout<<dq.size()<<'\n';
        }
    }

}