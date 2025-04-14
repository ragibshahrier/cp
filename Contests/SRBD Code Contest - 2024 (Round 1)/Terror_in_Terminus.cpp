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
const ll N = 1e5 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//


vvll adj;
vll par;
vll lvl;


void preprocessing(){

}
void dfs(int node, int parr, int level){
    
    lvl[node] = level;
    for(auto el:adj[node]){
        if(el!=parr){
            par[el] = node;
            dfs(el,node,level+1);
        }
    }
}

void solve(){

    int n;
    cin>>n;
    adj.clear();
    par.clear();
    lvl.clear();
    adj.resize(n+1);
    par.resize(n+1);
    lvl.resize(n+1);
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    dfs(1,0,0);
    debug(n)
    int q;cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        vi aa;
        debug(q)
        if(x==y){
            cout<<x<<endl;continue;
        }
        int cse = 0;
        debugc(par)
        debugc(lvl)
        if(lvl[x]>lvl[y]){
            while(lvl[x]>lvl[y]){
                aa.push_back(x);
                x = par[x];
                debug(x)
            }
        }
        if(lvl[x]<lvl[y]){
            cse = 1;
            while(lvl[y]!=lvl[x]){
                aa.push_back(y);
                y = par[y];
            }
        }
        debugc(aa)
        if(x==y){
            if(aa.size()%2==0 || cse==0){cout<<aa[aa.size()/2]<<endl;continue;}
            else{
                cout<<par[aa[aa.size()/2]]<<endl;
            }
            continue;
        }
        while(x!=y){
            x = par[x];
            y = par[y];
        }
        cout<<x<<endl;

    }

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
