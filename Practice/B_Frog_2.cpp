#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; ii<n; ii++)
#define gp " "
//#define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------


int n, k;
vi h;
vll dp;

ll frog(int a){
    if(dp[a]>=0)return dp[a];
    if(a==n) return dp[a]=0;
    ll ans=1e10;
    rep(i, 1, min(k, n-a)+1){
        ans=min(ans, abs(h[a+i]-h[a]) + frog(a+i));
    }
    return dp[a]=ans;
}


void solve(){
    cin>>n>>k;
    dp.resize(n+5,-1);
    h.resize(n+5);
    rep(i, 1, n+1){
        cin>>h[i];
    }
    ll ans=frog(1);
    // rep(i,1,n+1){
    //     cout<<dp[i]<<gp;
    // }
    cout<<ans<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
