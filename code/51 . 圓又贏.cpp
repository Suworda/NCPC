#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Point{
    int x, y;
    
    bool operator== (const Point &b){
        return x == b.x && y == b.y;
    }
};

void sol(){
    int x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    vector<Point> v;
    v.push_back({x1,y1});
    v.push_back({x2,y2});
    v.push_back({x3,y3});

    int dx1 = x2-x1;
    int dy1 = y2-y1;
    int dx2 = x2-x3;
    int dy2 = y2-y3;

    if(dx1 * dy2 != dx2 * dy1 || v[0] == v[1] || v[1] == v[2] || v[0] == v[2]) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

}