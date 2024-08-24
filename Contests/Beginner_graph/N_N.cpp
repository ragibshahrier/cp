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


vector<vi>adjf(2005);
vector<vi>adje(2005);
vi visited(2005);

ll cnt;
bool b;

void preprocessing(){

}

void dfs(int node, int par, int ii){
    if(visited[node]==ii){
        return;
    }
    visited[node]=ii;
    cnt++;
    for(auto el:adjf[node]){
        if(el!=par){
            dfs(el,node,ii);
        }
    }
    for(auto el:adje[node]){
        if(visited[el]==ii){
            b=1;
        }
    }
}

void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    rep(i,0,k){
        int x,y;
        cin>>x>>y;
        adjf[x].push_back(y);
        adjf[y].push_back(x);
    }
    int m;
    cin>>m;
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        adje[x].push_back(y);
        adje[y].push_back(x);
        
    }
    ll ans=0;
    rep(i,1,n+1){
        if(visited[i]==0){
            b=0;
            cnt=0;
            dfs(i,0,i);
            debug(i)
            debug(cnt)
            debug(b)
            if(!b){
                ans = max(ans,cnt);
            }
        }
    }
    cout<<ans<<endl;


}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
