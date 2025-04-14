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
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//


set<int>s;
vvll adj(N);

void preprocessing(){

}

void solve(int testcases){
    int n;
    cin>>n;
    adj.clear();
    adj.resize(N);
    s.clear();

    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    rep(i,1,n+1){
        s.insert(i*2);
    }
    queue<pi>q;
    q.push({1,2});
    s.erase(2);
    vll visited(n+1);
    vi anss(n);
    while(!q.empty()){
        pi tp = q.front();
        visited[tp.ff]++;
        anss[tp.ff-1] = tp.ss;
        q.pop();
        auto it = s.begin();
        for(auto el:adj[tp.ff]){
            if(visited[el]){
                continue;
            }
            debug(el)
            debug(tp.ss)
            debug(*it)
            debugc(s)
            while(it!=s.end()&& (*it==tp.ss+2 || *it==tp.ss-2)){
                it++;
                
            }
            if(it==s.end()){
                cout<<-1<<endl;return;
            }
            debug(el)
            debug(tp.ss)
            debug(*it)
            q.push({el, *it});
            s.erase(it);
            it = s.begin();
        }
    }
    put_vector(anss);

}

int32_t main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1)solve(i);
    return 0;
}
