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
const ll N = 1e6 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}
int n,m,d;

vvi adj;
vector<string>grid;
int dpp[N][52][2];
vi visited;


ll dfs(int nd, int da, int vis){
    if(dpp[nd][da][vis]!=-1){
        return dpp[nd][da][vis];
    }
    int temp=0;
    if(grid[nd][da]=='1' && vis==0)temp++;
    ll ans = temp;
    visited[nd] = 1;
    for(auto el:adj[nd]){
        ans = max(ans, dfs(el,(da+1)%d, visited[el])+temp);
    }
    if(!vis){
        visited[nd]=0;
    }

    return dpp[nd][da][vis] = ans;


}

void solve(int testcases){
    cin>>n>>m>>d;

    adj.resize(n+1);
    memset(dpp,-1,sizeof(dpp));
    visited.resize(n+1);

    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    grid.resize(n+1);

    rep(i,0,n){
        string s;
        cin>>s;

        grid[i+1] = s;
    }

    int ans = dfs(1,0,0);
    cout<<ans<<endl;



    



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
