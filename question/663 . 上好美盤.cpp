#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    while(m--){
        stack<int> stk1,stk2,tmp,targ;
        stk1.push(-1); stk2.push(-1);
        
        for(int i=n; i>=1; i--){
            stk1.push(i);
        }
        
        int x;
        for(int i=0; i<n; i++){
            cin>>x;
            tmp.push(x);
        }
        for(int i=0; i<n; i++){
            targ.push(tmp.top());
            tmp.pop();
        }
        
        bool ans = true;
        while(!targ.empty()){
            x = targ.top();
            if(stk1.top() != x && stk2.top() != x){
                if(stk1.top() == -1){
                    ans = false;
                    break;
                }
                stk2.push(stk1.top());
                stk1.pop();

            }else if(stk1.top() == x){
                targ.pop();
                stk1.pop();

            }else{
                targ.pop();
                stk2.pop();

            }
        }
        //cout<<m<<":";
        cout<<(ans ? "Y" : "N")<<'\n';
    }

}