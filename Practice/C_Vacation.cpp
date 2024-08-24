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


int n;
vector<vi> h(1e5, vi (3));
vector<vi> dp(1e5, vi (3, -1));

ll vac(int a, int c){
    vi ch;
    rep(i,0,3){
        if(i!=c)ch.push_back(i);
    }
    if(dp[a][c]>=0)return dp[a][c];
    if(a==n-1)return dp[a][c]=h[a][c];
    ll ans = max(h[a][c]+vac(a+1,ch[0]) , h[a][c]+ vac(a+1, ch[1]));
    return dp[a][c]=ans;
}

void solve(){
    cin>>n;
    h.resize(n+2);
    rep(i, 0, n){
        cin>>h[i][0]>>h[i][1]>>h[i][2];
    }
    ll ans = max({vac(0, 0),vac(0,1),vac(0,2)});
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
