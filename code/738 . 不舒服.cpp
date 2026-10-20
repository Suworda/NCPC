#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

void merge_sort(vector<int> &a, int L, int R, int &ans){
    if(L == R) return;

    int m = (L+R)/2;
    merge_sort(a, L, m, ans);
    merge_sort(a, m+1, R, ans);

    int left_sum = 0;
    for(int i=L; i<=m; i++) left_sum += a[i];

    vector<int> tmp;
    int l = L, r = m+1;
    while(l <= m && r <= R){
        if(a[l] <= a[r]){
            left_sum -= a[l];
            tmp.push_back(a[l++]);
        }
        else{
            ans += left_sum + (m-l+1) * a[r];
            tmp.push_back(a[r++]);
        }
    }

    while(l <= m) tmp.push_back(a[l++]);
    while(r <= R) tmp.push_back(a[r++]);
    for(int i=0; i<tmp.size(); i++) a[L+i] = tmp[i];
}


int get_ans(vector<int> &a){
    int n = a.size();
    
    int ans = 0;
    merge_sort(a, 0, n-1, ans);

    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int ans = get_ans(a);
    
    cout << ans << '\n';
}