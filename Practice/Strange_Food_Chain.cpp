#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
 
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

int mod3(int n){
    if(n<0){
        return ((n%3)+3)%3;
    }
    return n%3;
}

struct DSU{
    
    vector<pi>parwithweight;
    vi size;
    int nn;
     
    void init(int n){
        nn = n;
        parwithweight.resize(n+1);
        rep(i,1,n+1){
            parwithweight[i] = {i,0};
        }
        size.assign(n+1, 1);

    }
    pi find(int n){
        if(parwithweight[n].ff == n){
            return parwithweight[n];
        }
        pi fnd = find(parwithweight[n].ff);
        return parwithweight[n] = {fnd.ff, fnd.ss+parwithweight[n].ss};
    }
    int unity(int n1, int n2, int wgt){
        if(n1>nn || n2>nn){
            return 0;
        }
        pi fn1 = find(n1);
        pi fn2 = find(n2);
        if(fn1.ff==fn2.ff){
            if(mod3(fn1.ss-fn2.ss) != mod3(wgt)){
                return 0;
            }
            return 1;
        }
        if(size[fn1.ff] < size[fn2.ff]){
            parwithweight[fn2.ff] = {fn1.ff, fn1.ss-fn2.ss-wgt};
        }else{
            parwithweight[fn1.ff] = {fn2.ff, fn2.ss+wgt- fn1.ss};

        }
        return 1;

        
    }
    
};

void solve(){
    int n, q;
    cin>>n>>q;
    DSU dsu;
    dsu.init(n);
    ll ans = 0;
    int i = 1;
    while(q--){
        int o,x,y;
        cin>>o>>x>>y;
        if(o==1){
            if(!dsu.unity(x,y,0)){
                ans++;
                debug(i)
            }
        }else{
            if(!dsu.unity(x,y,1)){
                ans++;
                debug(i)
            }
        }
        i++;
        
    }
    cout<<ans<<endl;

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
