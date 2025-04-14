#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
 
typedef long long ll;
 
#define int long long
 
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
#define bitcnt(x) ((sizeof(x) <= sizeof(int)) ? (32 - __builtin_clz(x)) : (64 - __builtin_clzll(x)))

// #define DEBG

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
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//

vvi adj(402,vi(402));

int n,m;

void preprocessing(){

}

void solve(int testcases){
    cin>>n>>m;
    vpi edge(m);
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        edge[i] = {x,y};
        adj[x][y]=1;
        // adj[y][x]=1;
    }

    vi par(n+1);
    vi dist(n+1,inf);

    queue<int>q;

    q.push(1);
    dist[1] = 0;

    while(!q.empty()){
        int nd = q.front();
        q.pop();

        rep(i,1,n+1){
            if(adj[nd][i]==1){
                if(i!=nd && dist[i]>dist[nd]+1){

                    q.push(i);
                    par[i] = nd;
                    dist[i] = dist[nd]+1;
                }
            }
        }
    }
    debugc(par)
    int ii = n;
    int path = 0;
    set<pi> shpath;
    while(par[ii]!=0){
        path++;
        shpath.insert({par[ii],ii});
        ii = par[ii];
    }

    // rep(i,1,n+1){
    //     rep(j,1,n+1){
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    debugcc(shpath)

    rep(i,0,m){
        if(shpath.find({edge[i].ff,edge[i].ss})==shpath.end()){
            if(path>0){
                cout<<path<<endl;
            }else{
                cout<<-1<<endl;
            }
            continue;
        }
        

        adj[edge[i].ff][edge[i].ss] = 0;
        // adj[edge[i].ss][edge[i].ff] = 0;

        // rep(i,1,n+1){
        //     rep(j,1,n+1){
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        // vi par2(n+1);
        vi dist2(n+1,inf);
        
        queue<int>q2;
        
        q2.push(1);
        dist2[1] = 0;
        
        while(!q2.empty()){
            int nd = q2.front();
            q2.pop();
            
            rep(i,1,n+1){
                if(adj[nd][i]==1){
                    if(i!=nd && dist2[i]>dist2[nd]+1){
    
                        q2.push(i);
                        // par2[i] = nd;
                        dist2[i] = dist2[nd]+1;
                    }
                }
            }
        }

        debugc(dist2)
        // int ii2 = n;
        // int path2 = 0;
        // while(par2[ii]!=0){
        //     path2++;
        //     ii2 = par2[ii];
        // }
        
        adj[edge[i].ff][edge[i].ss] = 1;
        // adj[edge[i].ss][edge[i].ff] = 1;

        if(dist2[n]<inf){
            cout<<dist2[n]<<endl;
        }else{
            cout<<-1<<endl;
        }


    }
    



}

int32_t main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
