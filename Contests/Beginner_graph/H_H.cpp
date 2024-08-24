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
const int N = 1e5 + 7;


//==============================CODE STARTS HERE==============================//


vector<vector<pll>>adj(N);
vll visited(N,inf);

void preprocessing(){

}



void solve(){
    int n,m;
    cin>>n>>m;
    rep(i,0,m){
        int x,y,c;
        cin>>x>>y>>c;
        adj[x].push_back({c,y});

    }
    priority_queue<pll>q;
    q.push({0,1});
    // visited[1]=0;
    while(!q.empty()){
        pll curp = q.top();
        ll curr = q.top().ss;
        debug(curr)
        q.pop();
        if(visited[curr]!=inf)continue;
        visited[curr]=-curp.ff;
        debug(visited[curr])
        for(auto el: adj[curr]){
            debug(el.ss)
            q.push({-(el.ff+visited[curr]), el.ss});
        }
    }
    rep(i,1,n+1){
        cout<<visited[i]<<gp;
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
