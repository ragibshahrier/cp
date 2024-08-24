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


//==============================CODE STARTS HERE==============================//


vector<vi>adj(102);
vi visited(102);

void preprocessing(){

}
ll cnt = 0;

void dfs(int node, int par){
    debug(node)
    if(visited[node]==1){
        debug(node)
        cnt++;
        return;
    }
    visited[node]=1;
    for(auto el:adj[node]){
        if(el!=par){
            dfs(el,node);
        }
    }

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
    dfs(1,0);
    debug(cnt)
    if(cnt==2){
        rep(i,1,n+1){
            if(visited[i]==0){
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"FHTAGN!"<<endl;
    }else{
        cout<<"NO"<<endl;
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
