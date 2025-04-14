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

vvll adj;
vll leaf;
vll leafpar;
vll leafsib;
vll leafsibun;
vll leafsibup;
ll ans = 0;

int leafcnt = 0;

void preprocessing(){

}

void leaffind(int nd, int par){
    if(adj[nd].size()==1 && leaf[nd]!=1){
        leaf[nd]=1;
        leafcnt++;
    }

    for(auto el:adj[nd]){
        // if(leaf[nd]){
        //     leafpar[el] = 1;
        // }
        if(el!=par){
            leaffind(el,nd);
            if(leaf[el]){
                leafpar[nd]=1;
            }
        }
    }

}

void leafsibfind(int nd, int par){
    for(auto el:adj[nd]){
        if(el!=par){
            if(leafpar[nd]){
                if(leaf[el]!=1){
                    leafsib[el]=1;
                }
            } 
            leafsibfind(el,nd);
        }
    }
}


void dfs(int nd, int par, int up){
    leafsibup[nd] = up;
    if(leafpar[nd] && par!=0){
        up++;
    }
    
    for(auto el:adj[nd]){
        if(el!=par){
            dfs(el,nd,up);
            if(leafsib[el]){
                leafsibun[nd]+=leafsibun[el]+1;
            }else{
                leafsibun[nd]+=leafsibun[el];
            }
        }
    }
}

void dfs2(int nd,int par){
    if(!leaf[nd] && !leafpar[nd] && !leaf[par]){
        debug(nd)
        ans+= (leafsibup[nd]+leafsibun[nd]);
    }
    for(auto el:adj[nd]){
        if(el!=par){
            dfs2(el,nd);
        }
    }
}
void dfs3(int nd, int par){
    if(par!=0){
        leafsibup[nd] = leafsibup[par] + leafsibun[par]-leafsibun[nd];
        if(leafsib[nd]){
            leafsibup[nd]--;
        }
        if(leafpar[nd] && !leaf[par]){
            leafsibup[nd]++;

        }
    }
    for(auto el:adj[nd]){
        if(el!=par){
            dfs3(el,nd);
        }
    }

}


void solve(int testcases){
    int n;
    cin>>n;

    adj.clear();
    leafsib.clear();
    leaf.clear();
    leafpar.clear();
    leafsibun.clear();
    leafsibup.clear();
    
    adj.resize(n+1);
    leafsib.resize(n+1);
    leaf.resize(n+1);
    leafpar.resize(n+1);
    leafsibun.resize(n+1);
    leafsibup.resize(n+1);

    leafcnt = 0;

    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
    
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    leaffind(1, 0);
    if(leaf[1]){
        for(auto el:adj[adj[1][0]]){
            if(!leaf[el]){
                leafsib[el]=1;
            }
        }
    }
    debugc(leaf)
    // debugc(leafsib)
    leafsibfind(1,0);
    debugc(leafpar)
    debugc(leafsib)

    ans = (n-leafcnt)*leafcnt;
    debug(ans)


    dfs(1,0,0);
    dfs3(1,0);
    dfs2(1,0);
    debugc(leafsibun)
    debugc(leafsibup)
    
    
    
    cout<<ans<<endl;





}

int32_t main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1)solve(i);
    return 0;
}
