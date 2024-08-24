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



const int N=1e5;
vi h(N);
vll dp(N, -1);
int n;


ll frog(int a){
    if(dp[a]>=0){
        return dp[a];
    }
    if(a==n-1)return dp[a]=0;
    if(a==n-2)return dp[a]= abs(h[a]-h[a+1]);
    ll ans = min(abs(h[a]-h[a+1])+frog(a+1), abs(h[a]-h[a+2])+frog(a+2));
    return dp[a]=ans;
}

void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>h[i];
    }
    ll ans = frog(0);
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
