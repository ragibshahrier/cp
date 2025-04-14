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

//#define DEBG

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
const ll N = 2e5 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

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

void solve(int testcases){
    int n,q;
    cin>>n>>q;

    vi a(n);
    vi b(n);
    get_vector(a);
    get_vector(b);
    
    vi as = a;
    vi bs = b;

    sort(All(as));
    sort(All(bs));

    ll ans = 1;

    rep(i,0,n){
        ans *= min(as[i],bs[i]);
        ans %= M;
    }
    cout<<ans<<" ";

    while(q--){
        int o,x;
        cin>>o>>x;
        if(o==1){
            auto it = --upper_bound(All(as), a[x-1]);
            int ind = it-as.begin();
            ans *= modInverse(min(as[ind], bs[ind]), M);
            ans %= M;
            as[ind]++;
            a[x-1]++;
            ans *= min(as[ind],bs[ind]);
            ans %= M;
        }else{
            auto it = --upper_bound(All(bs), b[x-1]);
            int ind = it-bs.begin();
            ans *= modInverse(min(as[ind], bs[ind]), M);
            ans %= M;
            bs[ind]++;
            b[x-1]++;
            ans *= min(as[ind],bs[ind]);
            ans %= M;

        }
        cout<<ans<<" ";
    }
    cout<<endl;





}

int32_t main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1)solve(i);
    return 0;
}
