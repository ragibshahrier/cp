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
const ll M = 1e9 + 7;
const ll N = 2e5 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

int order(int a, int q){
    int r = 1e6 +124;
    int aa = a;
    for(int i = 0; i<r; i++){
        if(a%q==1){
            return i+1;
        }
        a*=aa;
        a%=q;
    }

    return r;
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

long long power(long long a, long long b, long long mod)
{
    long long result = 1;
    while (b) {
        if (b & 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

void solve(int testcases){
    int n,m,a,q;
    cin>>n>>m>>a>>q;
    int sz = max(m+1, n);
    vi bin(sz);
    bin[0] = 1;
    int k = 1;
    int nn = m;
    int orr = order(a,q);
    debug(1)
    debug(orr)
    rep(i,1,m+1){
        bin[i]=bin[i-1];
        debug(nn)
        debug(k)
        
        bin[i] *= (nn%orr);
        bin[i]%=orr;
        
        int kin = modInverse(k,orr);
        bin[i] *= kin;
        bin[i]%=orr;
        nn--;
        k++;
    }
    // debug(order(2,7))

    debugc(bin)

    vi ansv(n);

    ansv[0] = 1;
    rep(i,1,n){
        ansv[i]=ansv[i-1]+bin[i];
        ansv[i]%=orr;
        
    }
    debugc(ansv)

    rep(i,0,n){
        ansv[i] = power(a, ansv[i], q);
    }

    reverse(All(ansv));

    debugc(ansv)
    put_vector(ansv);



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
