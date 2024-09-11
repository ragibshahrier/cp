#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
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
#define pow2(i) (1LL<<i)

// #define DEBG

#define debug(n)
#define debugc(a)
#define debugcc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<'{'<<gp<<el.ff<<','<<el.ff<<gp<<'}'<<gp;}cout<<']'<<endl;
#endif

#define fastcin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'


#define All(a) a.begin(),a.end()
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}


const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;
const ll N = 2e5 + 7;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(){
    ll n,k;
    cin>>n>>k;
    ll lo  = 1;
    ll hi = n;
    ll mid = (hi+lo)/2;
    while(hi-lo>1){
        mid = (hi+lo)/2;
        ll ns = (k+k+mid-1)*mid/2 - (k+mid+k+n-1)*(n-mid)/2;
        debug(ns)
        if(ns<0){
            lo = mid+1;
        }else{
            hi=mid;
        }
        
    }
    ll ans1,ans2;
    if((k+k+lo-1)*lo/2 - (k+lo+k+n-1)*(n-lo)/2 >=0){
        ans1 = lo;
    }else{
        ans1 = hi;
    }
    debug(ans1)
    lo  = 1;
    hi = n;
    mid = (hi+lo)/2;
    while(hi-lo>1){
        mid = (hi+lo)/2;
        ll ns = -(k+k+mid-1)*mid/2 + (k+mid+k+n-1)*(n-mid)/2;
        if(ns<0){
            hi = mid-1;
        }else{
            lo=mid;
        }
        
    }
    // ll ans1,ans2;
    if(-(k+k+hi-1)*hi/2 + (k+hi+k+n-1)*(n-hi)/2 >=0){
        ans2 = hi;
    }else{
        ans2 = lo;
    }
    debug(ans2)
    ans1 = (k+k+ans1-1)*ans1/2 - (k+ans1+k+n-1)*(n-ans1)/2;
    ans2 = -(k+k+ans2-1)*ans2/2 + (k+ans2+k+n-1)*(n-ans2)/2;

    cout<<min(ans1,ans2)<<endl;



}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
