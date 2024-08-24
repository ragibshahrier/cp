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
// #define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

const int V = 100007;
const int N = 107;

vi w(N), v(N);
int n, mw;
ll dp[N][V];


ll func(int i, int val){
    if(val==0)return 0;
    if(i>=n)return 1e15;
    if(dp[i][val]!=-1)return dp[i][val];
    ll ans = func(i+1, val);
    if(val>=v[i]) ans = min(func(i+1,val-v[i])+w[i], ans);
    return dp[i][val] = ans;
}


void solve(){
    rep(i, 0, N){
        rep(j, 0, V){
            dp[i][j]=-1;
        }
    }
    cin>>n>>mw;
    rep(i,0,n){
        cin>>w[i];
        cin>>v[i];
    }
    ll ans = 0;
    for(int i=100000; i>=0; i--){
        ll temans = func(0,i);
        debug(i)
        debug(temans);
        if(temans<=mw){
            ans=i;
            break;
        }



    } 
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
