#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
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

//#define DEBG

#define debug(n)
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#endif

#define fastcin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'


#define All(a) a.begin(),a.end()
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}


const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;
const int N = 2e5 + 7;


//==============================CODE STARTS HERE==============================//

vector<vi>adj(N);
vi visited(N);

void preprocessing(){

}
bool b;

bool dfs(int node, int par){
    if(visited[node]==1){
        return (b);
    }
    visited[node]=1;
    if(adj[node].size()!=2){
        b=0;
    }
    for(auto el:adj[node]){
        if(el!=par){
            dfs(el,node);
        }
    }
    return (b);
}

void solve(){
    int n,m;
    cin>>n>>m;
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll cnt = 0;
    rep(i,1,n+1){
        b=1;
        if(visited[i]==0){
            if(dfs(i,0)){
                cnt++;
            }
        }
    }
    cout<<cnt;

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
