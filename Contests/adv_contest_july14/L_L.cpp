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
#define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------


int bitdig(ll n){
    int i;
    for(i = 60; i>=0;){
        if(((1LL<<i) -1)>=n){
            i--;
        }else break;
    }
    return i;
}

void solve(){
    ll n;
    cin>>n;
    int dig = bitdig(1);
    ll ans = 0;
    debug(dig)
    while(n>0){
        dig = bitdig(n);
        ll x = (1LL<<dig)-1;
        debug(x)
        ans += n-x;
        n=x;
    }
    cout<<ans;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
