#include<bits/stdc++.h>
using namespace std;
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
const ll N = 3e5 + 7;


//==============================CODE STARTS HERE==============================//


vvi adj(N);
vi visited(N);
int tot;
int t1;

void preprocessing(){

}
bool nd=0;

void dfs(int node, int par,int col){
    if(visited[node]){
        if(visited[node]!=col){
            nd=1;return;
        }return;
    }
    visited[node]=col;
    if(col==1)t1++;
    tot++;
    for(auto el:adj[node]){
        if(el!=par){
            dfs(el,node,3-col);
        }
    }
}

void solve(){
    int n, m;
    cin>>n>>m;
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll ans = 0;

    rep(i,1,n+1){
        if(visited[i]==0){
            tot=0;t1=0;
            nd=0;
            dfs(i,0,1);
            if(nd){
                cout<<-1;return;
            }
            ans+=min(t1,tot-t1);
        }
    }
    cout<<ans;
    


}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
