#include <bits/stdc++.h>
using namespace std;

#define ll long long

string s;
const int M = 998244353;

ll calc(){
    cin>>s;
    if(s == "f") return (2*calc() -3)%M;
    else if(s == "g") return (2*calc() + calc() -7)%M;
    else if(s == "h") return (3*calc() - 2*calc() + calc())%M;

    return stoi(s);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int n;
    cin>>n;

    cout << (calc()+M)%M <<'\n';
}
