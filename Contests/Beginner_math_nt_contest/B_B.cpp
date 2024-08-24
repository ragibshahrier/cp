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



const ll M = 1e9+7;

ll binexp(ll a,ll b, ll m){
    ll ans = 1;
    ll aa=a;
    while(b!=0){
        debug(b)
        debug(aa)
        if((b&1) == 1){
            ans=(ans*aa)%m;
            
        }
        aa=(aa*aa)%m;
        b=b>>1;
    }
    return ans;
}

void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    ll bc = binexp(b,c,M-1);
    ll ans = binexp(a,bc,M);
    cout<<ans<<endl;



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
