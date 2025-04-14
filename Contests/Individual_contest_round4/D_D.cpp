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

int absi(int x){
    if(x<0)return -x;
    return x;
}

pi slope(pi x, pi y){
    pi sl;
    // debug(x.ff)
    // debug(x.ss)
    // debug(y.ff)
    // debug(y.ss)
    sl.ss = y.ff-x.ff;
    sl.ff = y.ss-x.ss;

    if(sl.ss==0){
        return {1,0};
    }
    int f;
    if(sl.ff>0 && sl.ss>0 || sl.ff<0 && sl.ss<0){
        f=0;
    }else{
        f=1;
    }
    // debug(sl.ff)
    // debug(sl.ss)
    sl.ff = absi(sl.ff);
    sl.ss = absi(sl.ss);

    int gg = __gcd(sl.ff, sl.ss);

    // debug(gg)
    sl.ff/=gg;
    sl.ss/=gg;

    if(f){
        sl.ff = -sl.ff;
    }
    return sl;
}

pi C(int yq_px, int q){
    pi sl;
    // debug(x.ff)
    // debug(x.ss)
    // debug(y.ff)
    // debug(y.ss)
    // debug(yq_px)
    // debug(q)
    sl.ss = q;
    sl.ff = yq_px;
    if(q==0){
        return {yq_px,0};
    }
    int f;
    if(sl.ff>0 && sl.ss>0 || sl.ff<0 && sl.ss<0){
        f=0;
    }else{
        f=1;
    }
    // debug(sl.ff)
    // debug(sl.ss)
    sl.ff = absi(sl.ff);
    sl.ss = absi(sl.ss);

    int gg = __gcd(sl.ff, sl.ss);

    // debug(gg)
    sl.ff/=gg;
    sl.ss/=gg;

    if(f){
        sl.ff = -sl.ff;
    }
    return sl;
}

void solve(int testcases){
    int n;
    cin>>n;

    vpi nodes(n);

    map<pi,int>mp;
    rep(i,0,n){
        cin>>nodes[i].ff>>nodes[i].ss;

    }

    set<pair<pi,pi>>st;
    rep(i,0,n){
        rep(j,i+1,n){
            pi sl = slope(nodes[i], nodes[j]);
            debug(i)
            debug(j)
            debug(sl.ff)
            debug(sl.ss)
            int y = nodes[i].ss;
            int x = nodes[i].ff;
            
            int q = sl.ss;
            int p = sl.ff;
            
            pi c = C(y*q-p*x, q);
            debug(c.ff)
            debug(c.ss)


            st.insert({sl,c});


            // mp[sl]++;
            
        }
    }

    for(auto el:st){
        mp[el.ff]++;
    }
    debug(st.size())

    int totl = st.size();
    int ans = 0;
    for(auto el:st){
        // debug(el.ff.ff)
        // debug(el.ff.ss)
        // debug(el.ss)
        ans += totl - mp[el.ff];
    }
    ans = ans/2;
    cout<<ans<<endl;

    debug(1)

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
