#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; ii<n; ii++)
#define gp " "

//bit_manupulation
#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define resetbit(x,n) (x=(x&(~(1LL<<n))))

// #define DEBG

#define debug(n)
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#endif

#define fastcin() ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}



void solve(){
    ll n,k;
    cin>>n>>k;
    ll hi = 2*(1e9+7);
    ll lo =0;
    ll mid = (hi+lo)/2;
    while(hi-lo>1){
        mid = (hi+lo)/2;
        if(mid%n ==0)mid++;
        ll x = mid - mid/n;
        if(x==k){
            cout<<mid<<endl;
            return;
        }else if(x>k){
            hi=mid-1;
        }else if(x<k){
            lo=mid+1;
        }


        debug(hi)
        debug(lo)
        debug(mid)
    }
    ll x = lo - lo/n;
    if(x == k)cout<<lo<<endl;
    else cout<<hi<<endl;

    // cout<<ans<<"\n";

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
