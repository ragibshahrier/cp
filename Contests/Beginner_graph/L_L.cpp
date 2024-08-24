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


//==============================CODE STARTS HERE==============================//


vector<vector<vi>>adj(103, vector<vi>(103));
vector<vi>grps(103, vi(103));
vi visited(103);

void preprocessing(){

}

void dfs(int node, int par, int col, int grp){
    if(visited[node]==col){
        return;
    }
    visited[node]=col;
    grps[node][col]=grp;
    for(auto el:adj[col][node]){
        dfs(el,node,col,grp);
    }
}


void solve(){
    int n,m;
    cin>>n>>m;
    // vi col
    rep(i,0,m){
        int x,y,c;
        cin>>x>>y>>c;
        adj[c][x].push_back(y);
        adj[c][y].push_back(x);
    }
    rep(i,1,m+1){
        rep(j,1,n+1){
            if(visited[j]!=i){
                dfs(j,0,i,j);
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=0;
        rep(i,1,m+1){
            if(grps[x][i]==grps[y][i]){
                ans++;
            }
        }
        cout<<ans<<endl;
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
