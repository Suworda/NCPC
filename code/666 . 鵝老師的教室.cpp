#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int , vector<int> , greater<int>> pq;
    
    int n,m;
    cin>>n>>m;
    int x;
    while(n--){
        cin>>x;
        pq.push(x);
    }

    while(m--){
        int ty;
        cin>>ty;

        if(ty == 0){
            cout << pq.top() << '\n';

        }else if(ty == 1){
            int v = pq.top();
            pq.pop();
            cout<<pq.top()<<'\n';
            pq.push(v);
            
        }else if(ty == 2){
            pq.pop();

        }else{
            int a;
            cin>>a;
            pq.push(a);

        }
    }

}