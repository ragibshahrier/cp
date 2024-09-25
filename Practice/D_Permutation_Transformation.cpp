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
const ll N = 2e5 + 7;


//==============================CODE STARTS HERE==============================//

vector<int>dept(101);
vector<bool>vis(101);

void dfs(int strt, int en, int depth, vector<int>&a){
    int root = max_element(a.begin()+strt, a.begin()+en) - a.begin();
    // if(vis[root]) return;
    
    dept[root] = depth;
    vis[root] = true;
    if(root != strt){
        dfs(strt, root, depth+1, a);
    }
    if(root != en-1){
        dfs(root+1, en, depth+1, a);
    }
}

void preprocessing(){

}

void solve(){
    // cout<<1;
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        dept[i] = 0;
        vis[i] = false;
    }
    vector<int>a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    dfs(0, n, 0, a);

    for(int i = 0; i<n; i++){
        cout<<dept[i]<<" ";
    }
    cout<<endl;
}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--){
        solve();
    }
    return 0;
}
