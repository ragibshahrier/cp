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
#define bitcnt(x) ((sizeof(x) <= sizeof(int)) ? (32 - __builtin_clz(x)) : (64 - __builtin_clzll(x)))

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
int n,k,x;

int dpp[207][207][207];


void preprocessing(){

}

ll func(int i, int lasttaken, int totaltaken){
    lasttaken--;
    if(totaltaken>=x){
        if(n-i<k)return 0;
        else return -2;
    }
    if(i>=n && totaltaken<x){
        return -2;
    }
    if(i-lasttaken>k){
        return -2;
    }

    if(dpp[i][lasttaken+1][totaltaken]!=-1){
        return dpp[i][lasttaken+1][totaltaken];
    }

    int x1 = func(i+1,i+1, totaltaken+1);
    int x2 = func(i+1,lasttaken+1, totaltaken);
    
    ll ans = -2;
    if(x2!=-2)ans = x2;
    if(x1!=-2){
        ans = max(ans,x1+a[i]);
    }

    return dpp[i][lasttaken+1][totaltaken] = ans;

    // ll ans = 0;
    // rep(i,0,k){

    // }
}

void solve(int testcases){
    cin>>n>>k>>x;
    a.resize(n);

    get_vector(a);
    memset(dpp,-1, sizeof(dpp));

    ll ans = func(0, 0, 0);
    if(ans!=-2)cout<<ans<<endl;
    else cout<<-1<<endl;

}

int32_t main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
