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

vvll adj;



void preprocessing(){

}

vll leafinlvl;
vll edge;
vvll level;
ll maxlvl=0;

ll dfs(int node, int par, ll lvl){
    level[lvl].push_back(node);
    maxlvl = max(lvl,maxlvl);
    ll child = 0;
    ll edges = 0;
    debugc(adj[node])
    for(auto el:adj[node]){
        if(el!= par){
            child++;
            edges += dfs(el, node, lvl+1)+1;
        }
    }
    if(node!=1 && child==0){
        debug(lvl)
        debug(node)
        debug(par)
        leafinlvl[lvl]++;
    }
    edge[node] = edges;

    return edges;
}



void solve(){
    ll n;
    cin>>n;

    adj.clear();
    leafinlvl.clear();
    edge.clear();
    level.clear();
    maxlvl = 0;


    adj.resize(n+5);
    leafinlvl.resize(n+5);
    edge.resize(n+5);
    level.resize(n+5);
    rep(i,0,n-1){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0, 0);
    ll ans = 0;
    rep(i,1, maxlvl+1){
        ll sum = 0;
        for(auto el: level[i]){
            sum+=edge[el];
        }
        debug(i)
        debug(sum)
        debug(leafinlvl[i])
        if(leafinlvl[i]>=sum){
            ans+=sum;
            break;
        }else{
            ans += leafinlvl[i];
        }
        debug(ans)
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
