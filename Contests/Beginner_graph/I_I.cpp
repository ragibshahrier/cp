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

// #define DEBG

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
const int N = 5e5+7;


//==============================CODE STARTS HERE==============================//


vector<set<int>>adj(N);
vi visited(N);
int cnt=0;

void preprocessing(){

}

void dfs(int node, int par, vi& comp){
    if(visited[node]!=0){
        return;
    }
    visited[node]=1;
    cnt++;
    comp.push_back(node);
    for(auto el:adj[node]){
        if(el!=par){
            dfs(el,node,comp);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    debug(n)
    rep(i,0,m){
        int x;
        cin>>x;
        vi v(x);
        rep(j,0,x){
        
            cin>>v[j];
        }
        rep(j,1,x){
            adj[v[j]].insert(v[j-1]);
            adj[v[j-1]].insert(v[j]);
        }
        debugc(v)
    }
    // rep(i,1,10){
    //     debugc(adj[i])
    // }
    vi ans(n+1);
    rep(i,1,n+1){
        cnt=0;
        vi comp;
        if(visited[i]==0){
            dfs(i, 0, comp);
        }
        for(auto el:comp){
            ans[el]=cnt;
        }


    }
    rep(i,1,n+1){
        cout<<ans[i]<<gp;
    }

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
