#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
 
typedef long long ll;
 
#define int long long
 
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

#define DEBG

#define debug(n)
#define debugc(a)
#define debugcc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<'{'<<gp<<el.ff<<','<<el.ss<<gp<<'}'<<gp;}cout<<']'<<endl;
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
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//

vi a;
// vll kk;
int n,k;

ll ans  = INF;

void preprocessing(){

}

bool check(ll mid){
    vi kk(n);
    int lim = 0;
    int anss = 0;
    int i = 0;
    ll tempans = 0;
    while(i<n){
        debug(mid)
        debug(i)
        if(tempans + kk[a[i]]>mid){
            debug("if")
            kk.clear();
            kk.resize(n);
            lim++;
            anss += tempans;
            tempans = 0;
        }
        else{
            debug("else")
            tempans += kk[a[i]];
            kk[a[i]]++;  
            i++;
        }
        debug(tempans)
        if(lim>k){
            return 0;
        }
    }
    anss += tempans;
    if(lim<k){
        ans = min(ans,anss);
    }
    return 1;
}


void solve(int testcases){
    
    cin>>n>>k;
    a.resize(n);
    get_vector(a);
    
    ll hi = 1e15;
    ll lo = 0;

    // while(hi-lo>1){
    //     ll mid = lo + (hi-lo)/2;

    //     if(check(mid)){
    //         hi = mid;
    //     }else{
    //         lo = mid+1;
    //     }
    //     debug("hello")
    // }
    // check(lo);
    // check(hi);

    check(1);

    cout<<ans<<endl;



}

int32_t main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    rep(i,1,t+1)solve(i);
    return 0;
}
