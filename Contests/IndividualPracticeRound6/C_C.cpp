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


struct node{
    int diff;
    int time;
    bool operator<(node other){
        return time<other.time;
    }
};

void preprocessing(){

}

void solve(int testcases){
    int n,t,a,b;

    cin>>n>>t>>a>>b;

    vi df(n);
    vi tm(n);

    get_vector(df);
    get_vector(tm);

    debugc(tm)
    set<int>s(All(tm));
    debug(n)
    vector<node>vn(n);
    rep(i,0,n){
        vn[i].diff = (df[i])?b:a;
        vn[i].time = tm[i];
    }

    sort(All(vn));
    sort(All(tm));
    rep(i,0,n){
        debug(vn[i].diff)
        debug(vn[i].time)
    }

    vi pref(n+1);

    rep(i,1,n+1){
        pref[i] = pref[i-1]+vn[i-1].diff;
    } 

    debugc(tm)
    debugc(pref)


    ll ans= 0;
    rep(i,0,n){
        int x = vn[i].time;
        auto it = upper_bound(All(tm), x);
        int req = (--upper_bound(All(tm), x))-tm.begin()+1;
        debug(req)
        if(pref[req]<*it && pref[req]<=t){
            ans = max(ans,req);
        }
    }

    for(auto el:s){
        
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
