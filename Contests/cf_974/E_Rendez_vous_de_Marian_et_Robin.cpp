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

#define DEBG

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




void preprocessing(){

}

void solve(){
    int n, m, h;
    cin>>n>>m>>h;
    vi horsehsh(n+1);
    rep(i,0,h){
        int x;cin>>x;
        horsehsh[x]=1;
    }
    vector<vector<pll>> adj(n+2);
    rep(i,0,m){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});


    }
    vll vsm(n+2,inf), vsr(n+2,inf);
    vll onhorse(n+2);
    vsr[1]=0;
    vll processed(n+2);
    priority_queue<pair<int,pi>>q;
    if(horsehsh[1])q.push({0,{1,1}});
    else q.push({0,{1,0}});
    while(!q.empty()){
        int a=q.top().second.ff;
        ll time = -q.top().first;
        bool h = q.top().second.ss;
        if(h)onhorse[a]=1;
        q.pop();
        if(processed[a])continue;
        processed[a]=1;
        for(auto u:adj[a]){
            int b=u.first,w=u.second;
            debug(b)
            debug(h)
            if(h){
                if(time+w/2<vsr[b] || !onhorse[b]){
                    onhorse[b]=1;
                    vsr[b]=min(vsr[b],time+w/2);
                    debug(vsr[b])
                    q.push({-time-w/2,{b,1}});
                        
                }

            }else{
                if(vsr[a]+w<vsr[b]){
                    vsr[b]=vsr[a]+w;
                    q.push({-vsr[b],{b,0}});
                        
                }
            }
            debugc(vsr)
        }
    }
    
    vsm[n]=0;

    if(horsehsh[1])q.push({0,{n,1}});
    else q.push({0,{n,0}});
    for(auto& el:processed)el = 0;

    while(!q.empty()){
        int a=q.top().second.ff;
        bool h = q.top().second.ss;
        q.pop();
        if(processed[a])continue;
        processed[a]=1;
        for(auto u:adj[a]){
            int b=u.first,w=u.second;
            debug(b)
            debug(h)
            if(h){
                if(vsm[a]+w/2<vsm[b]){
                    vsm[b]=vsm[a]+w/2;
                    q.push({-vsm[b],{b,1}});
                        
                }

            }else{
                debug(vsm[a])
                debug(vsm[b])
                if(vsm[a]+w<vsm[b]){
                    vsm[b]=vsm[a]+w;
                    debug(vsm[b])
                    q.push({-vsm[b],{b,0}});
                        
                }
            }
            debugc(vsm)
        }
    }
    debugc(vsm)
    debugc(vsr)
    ll ans = inf;

    rep(i,1,n+1){
        ans = min(ans, max(vsr[i],vsm[i]));
    }
    if(ans!=inf)cout<<ans<<endl;
    else cout<<-1<<endl;



}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
