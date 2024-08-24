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

const int W = 100007;
const int N = 107;

vi w(W), v(N);
int n, mw;
ll dp[N][W];


ll func(int i, int wgt){
    if(wgt<=0)return 0;
    if(i>=n)return 0;
    if(dp[i][wgt]!=-1)return dp[i][wgt];
    ll ans = func(i+1, wgt);
    if(wgt>=w[i]) ans = max(func(i+1,wgt-w[i])+v[i], ans);
    return dp[i][wgt] = ans;
}


void solve(){
    rep(i, 0, N){
        rep(j, 0, W){
            dp[i][j]=-1;
        }
    }
    cin>>n>>mw;
    rep(i,0,n){
        cin>>w[i];
        cin>>v[i];
    }
    ll ans= func(0,mw); 
    cout<<ans<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}
