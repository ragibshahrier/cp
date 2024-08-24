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
const ll N = 1e5 + 7;


//==============================CODE STARTS HERE==============================//



vector<vi>adj(N);
vi visited(N, -1);

void preprocessing(){

}

int n;

queue<int>q;

bool bfs(int node){
    q.push(node);
    visited[node] = 0;
    int nd;
    while(!q.empty()){
        nd= q.front();
    debug(nd)
        if(nd == n)break;
        
        q.pop();
        for(auto el:adj[nd]){
            if(visited[el]==-1){
                visited[el]=nd;
                q.push(el);
            }
        }
    }
    debug(nd)
    debug(n)
    if(nd==n){
        return 1;
    }
    return 0;
}

void solve(){
    int m;
    cin>>n>>m;

    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

        
    }
    bool x = bfs(1);
    if(!x){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    vi rt;
    int i= n;
    while(i!=1){
        rt.push_back(i);
        i = visited[i];
    }
    rt.push_back(1);
    reverse(All(rt));
    cout<<rt.size()<<endl;
    put_vector(rt);

    
    

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
