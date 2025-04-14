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

// #define DEBG

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
const ll M = 998244353;
const ll N = 1e6 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//


vi a(26);
int sum = 0;
int evv;
int odd;

int factt[N];


void preprocessing(){
    memset(factt, 0, sizeof(factt));
    factt[0] = 1;
    rep(i,1,N){
        factt[i] = (factt[i-1]*i)%M;
    }
}
long long modInverse(long long A, long long m)
{
    long long m0 = m;
    long long y = 0, x = 1;

    if (m == 1)
        return 0;

    while (A > 1) {
        long long q = A / m;
        long long t = m;

        
        m = A % m, A = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}
vvi dpp;



int func(int nd, int ev){
    if(ev>evv){
        return 0;
    }
    debug(nd)
    debug(ev)
    if(nd==26){
        if(ev==evv){
            ll ans = (factt[evv]*factt[odd])%M;
            return ans;
        }
        return 0;
    }
    if(dpp[nd][ev]!=-1){
        return dpp[nd][ev];
    }
    
    ll ans = func(nd+1, ev);
    ans%=M;
    if(a[nd]>0){
        ans += func(nd+1, ev+a[nd]);
        ans%=M;
    }
    debug(nd)
    debug(ev)
    debug(ans)

    return dpp[nd][ev] = ans;
}

void solve(int testcases){
    sum = 0;
    rep(i,0,26){

        cin>>a[i];
        sum+=a[i];
    }
    evv = sum-sum/2;
    odd = sum/2;
    debug(evv)

    dpp.clear();

    dpp.resize(28,vi(evv+7,-1));

    ll ans = func(0,0);
    ans%=M;
    debug(ans)

    rep(i,0,26){
        if(a[i]==0 || a[i]==1)continue;
        int inv= modInverse(factt[a[i]],M);
        ans*=inv;
        ans%=M;
    }

    cout<<ans<<endl;

}

int32_t main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
