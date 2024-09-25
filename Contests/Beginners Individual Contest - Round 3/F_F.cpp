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
// const ll N = 20;


//==============================CODE STARTS HERE==============================//

ll n;
vvll adj;
vll lvl(N, inf);
vll visited(N,-1);

void preprocessing(){

}

void dfs(ll nd, ll par, ll lvll){
    if(visited[nd]!=-1){
        return;
    }
    visited[nd]=1;
    lvl[nd]=lvll;
    for(auto el:adj[nd]){
        if(el!=par)dfs(el, nd, lvll+1);
    }
}

void solve(){

    cin>>n;
    adj.resize(n+5);
    rep(i,0,n-1){
        ll x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0, 1);
    vll a(n);
    get_vector(a);
    bool f = 0;
    // rep(i,0,n+2){
    //     cout<<lvl[i]<<endl;
    // }
    // debugc(lvl)
    if(a[0]!=1){
        cout<<"No";return;
    }
    rep(i,1,n){
        debug(lvl[a[i-1]])
        debug(lvl[a[i]])
        debug("")
        
        if(lvl[a[i]]-lvl[a[i-1]]!=0 && lvl[a[i]]-lvl[a[i-1]]!=1){
            cout<<"No";return;
        }
        
    }
    cout<<"Yes";

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
