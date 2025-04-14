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
const ll M = 1e9 + 7;
const ll N = 50;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//

int n;
vector<vector<char>> grid(N, vector<char>(N, '#'));
vector<vector<int>> visited(N, vector<int>(N, 0));

int ans = 0;

void preprocessing(){

}

void dfs(int i,int j){
    if(i>n || i<1 || j>n || j<1)return;
    if(visited[i][j])return;
    visited[i][j] = 1;

    vector<pi> li = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    for(auto el:li){
        if(grid[i+el.ff][j+el.ss]=='#')ans++;
        else dfs(i+el.ff, j+el.ss);
    }

}

void solve(int testcases){
    cin>>n;
    rep(i,1,n+1){
        string s;
        cin>>s;
        rep(j, 1, n+1){
            grid[i][j] = s[j-1];
        }
    }
    dfs(1,1);
    dfs(n,n);
    ans = (ans-4)*9;
    cout<<ans<<endl;


}

int32_t main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    rep(i,1,t+1)solve(i);
    return 0;
}
