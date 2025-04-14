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
// const ll N = 10;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//

int n;
vvi adj(N);
vi val(N);
vi dissum(N);
vi sum(N);
int startleaf  = 0;
ll tot = 0;

void preprocessing(){

}

void findleaf(int node, int par){
    debug(node)
    if(startleaf)return;
    int cnt=0;
    for(auto el:adj[node]){
        if(el!=par){
            cnt++;
            findleaf(el,node);
        }
    }
    if(startleaf)return;

    if(cnt==0)startleaf=node;
}

// ll sum = 0;

// void countsum(int node, int par, int len){
//     sum+=val[node]*len;
//     for(auto el:adj[node]){
//         if(el!=par){
            
//             countsum(el,node,len+1);
//         }
//     }
// }

void dfs1(int node, int par){
    for(auto el:adj[node]){
        if(el!=par){
            dfs1(el,node);
        }
    }
    for(auto el:adj[node]){
        sum[node] += sum[el];
        dissum[node] += dissum[el];
    }
    dissum[node]+=sum[node];
    sum[node]+=val[node];
}

void dfs2(int node, int par){
    if(par!=0){
        dissum[node] += dissum[par] - (dissum[node]+sum[node]) + (tot-sum[node]);
    }
    for(auto el:adj[node]){
        if(el!=par){
            dfs2(el, node);
        }
    }
}

void solve(int testcases){
    cin>>n;
    ll sum1 = 0;
    rep(i,1,n+1){
        int x;
        cin>>x;
        val[i] = x;
        tot+=val[i];
    }
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    findleaf(1, 0);
    // cout<<startleaf<<endl;
    

    sum1 -= val[startleaf];
    // startleaf = 7;

    dfs1(startleaf, 0);
    debugc(dissum)

    dfs2(startleaf, 0);

    debugc(dissum)

    ll maxi = -1;
    rep(i,1,n+1){
        maxi = max(dissum[i],maxi);
    }
    cout<<maxi<<endl;



}

int32_t main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    rep(i,1,t+1)solve(i);
    return 0;
}
