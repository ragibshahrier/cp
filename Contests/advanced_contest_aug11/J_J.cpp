#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vvi vector<vi>
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

#define DEBG

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




void preprocessing(){

}

void solve(){
    int n,x,y,s;
    cin>>n>>x>>y>>s;
    vector<vector<vector<pll>>> adj(n+1, vector<vector<pll>(2));
    vll visited(n+1, inf);
    vll proc(n+1);
    rep(i,0,x){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a][0].push_back({b,c});
        adj[b][0].push_back({a,c});
    }
    rep(i,0,y){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a][1].push_back({b,c});
    }

    priority_queue<pair<ll,ll>> pq;
    priority_queue<pair<ll,ll>> pq2;
    // visited[s]=0;
    pq.push({0,s});
    
    // while(!pq.empty()){
    //     pair<pll,ll> el = pq.top();
    //     pq.pop();
    //     debug(el.ss)
    //     debug(el.ff.ff)
    //     debug(visited[el.ff.ss])
    //     if((proc[el.ff.ss] && el.ss>=0)||visited[el.ff.ss]<=-el.ff.ss)continue;
    //     debug(el.ss)
    //     proc[el.ff.ss]=1;
    //     visited[el.ff.ss]=-el.ff.ff;
    //     for(auto ell:adj[el.ff.ss]){
    //         if(visited[ell.ff]>visited[el.ff.ss]+ell.ss)pq.push({{-visited[el.ff.ss]-ell.ss, ell.ff}, ell.ss});

    //     }
    // }
    // while(!pq.empty()){
    //     pll el = pq.top();
    //     pq.pop();
    //     debug(el.ss)
    //     debug(el.ff)
    //     debug(visited[el.ss])
    //     if(-el.ff>=visited[el.ss])continue;
    //     debug(el.ss)
    //     proc[el.ss]=1;
    //     visited[el.ss]=-el.ff;
    //     for(auto ell:adj[el.ss]){
    //         pq.push({-visited[el.ss]-ell.ss, ell.ff});

    //     }
    // }

    while(!pq.empty()){
        pll nd = pq.top();
        pq.pop();
        if(proc[nd.ss])continue;
        proc[nd.ss]=1;
        pq2.push({-nd.ff,nd.ss});

        visited[nd.ss]= -nd.ff;
        for(auto el:adj[0][nd.ss]){
            if(visited[el.ff]>visited[nd.ss]+el.ss){
                pq.push({-visited[nd.ss]-el.ss, el.ff});
            }
        }
    }
    while(!pq2.empty()){
        
    }



    rep(i,1,n+1){
        if(visited[i]==inf)cout<<"NO PATH"<<endl;
        else cout<<visited[i]<<endl;
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
