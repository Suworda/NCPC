#include <bits/stdc++.h>
using namespace std;

vector<list<int>::iterator> ptr(100005);
bool apr[100005]={};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    list<int> A;
    
    int m;
    cin>>m;
    while(m--){
        int ty,n,a;
        cin>>ty;
        if(ty==1){
            cin>>n;
            A.push_front(n);
            ptr[n] = A.begin();
            apr[n] = true;

        }else if(ty==2){
            cin>>n;
            A.push_back(n);
            ptr[n] = prev(A.end());
            apr[n] = true;

        }else if(ty==3){
            cin>>n>>a;
            if(!apr[a]){
                cout<<"peko\n";
                continue;
            }

            ptr[n] = A.insert(ptr[a], n);
            apr[n] = true;
            
        }else if(ty==4){
            cin>>n>>a;
            if(!apr[a]){
                cout<<"peko\n";
                continue;
            }
            ptr[n] = A.insert(next(ptr[a]), n);
            apr[n] = true;

        }else if(ty==5){
            cin>>a;
            if(!apr[a]){
                cout<<"peko\n";
                continue;
            }

            if(ptr[a] == A.begin()){
                cout<<"NULL\n";
            }else{
                cout << *prev(ptr[a]) << '\n';
            }
            
        }else if(ty==6){
            cin>>a;
            if(!apr[a]){
                cout<<"peko\n";
                continue;
            }

            if(ptr[a] == prev(A.end())){
                cout<<"NULL\n";
            }else{
                cout << *next(ptr[a]) << '\n';
            }
            
        }else if(ty==7){
            cin>>a;
            if(!apr[a]){
                cout<<"peko\n";
            }else{
                A.erase(ptr[a]);
                apr[a]=false;
            }
            
        }

        // for(int &x: A) cout<<x<<' ';
        // cout<<'\n';
    }

}