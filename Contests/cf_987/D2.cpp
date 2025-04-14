#include<bits/stdc++.h>

using namespace std;

#define int long long

typedef long long ll;

#define DBUG
#define debug(a) 
#define debugc(a) 

#ifdef DBUG
#define debug(a) cout<<__LINE__<<" "<<#a<<" "<<a<<"\n";
#define debugc(a) cout<<__LINE__<<" "<< #a<<" "<<"[ ";for(auto el:a){cout<<el<<" ";}cout<<']'<<endl;

#endif 

int mx = 0;
const int N = 5e5+10;
vector<int>dp(N,-1);
int rec(int n, vector<int>&a, vector<int>&vis, int i){
    if(dp[i] != -1) return dp[i];
    if(vis[i] == 1) return mx;
    vis[i] = 1;
    mx = max(mx, a[i]);
    for(int j = i+1; j<n; j++){
        if(a[j] < a[i]){
            mx = max(rec(n, a, vis, j), mx);
        }
    }
    for(int j = i-1; j>=0; j--){
        if(a[j] > a[i]){
            mx = max(rec(n, a, vis, j), mx);
        }
    }
    dp[i] = mx;
    return dp[i];
}

void solve(){
    mx = 0;
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<n+10; i++){
        dp[i] = -1;
    }
    for(int i = 0; i<n; i++){
        vector<int>vis(n);
        int ans = rec(n, a, vis, i);
        cout<<ans<<" ";
    }
    cout<<"\n";
}

int32_t main(){
    freopen("in.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}