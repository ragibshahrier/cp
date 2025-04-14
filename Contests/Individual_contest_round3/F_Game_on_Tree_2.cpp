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



int n;
vi a;

vvi adj;
vi med;

void preprocessing(){

}

void func(int nd, int par, multiset<int>&ms, multiset<int>::iterator mit){
    int mv = 0;
    multiset<int>::iterator inserted;

    debug(nd)
    debugc(ms)
    if(nd==1){
        inserted = ms.insert(a[nd]);
        mit--;
        mv--;
        med[nd] = *mit;
    }else{
        inserted = ms.insert(a[nd]);
        if(ms.size()%2==0){
            if(a[nd]<*mit){
                mit--;
                mv--;
            }
            
            med[nd] = *mit;
            med[nd] += *(++mit);
            mit--;
            med[nd]/=2;
            
        }else{
            if(a[nd]>=*mit){
                mit++;
                mv++;
            }
            med[nd] = *mit;
        }


    }

    for(auto el:adj[nd]){
        if(el!=par){
            func(el,nd,ms,mit);
        }
    }

    if(mv==-1){
        mit++;
    }else if(mv==1){
        mit--;
    }

    ms.erase(inserted);




}


void func2(int nd, int par, int mv){
    ll ans;
    for(auto el:adj[nd]){
        if(el!=par){
            func2(el,nd, 1-mv);
        }
    }
    if(mv==0){
        ans = 0;
        for(auto el:adj[nd]){
            if(el!=par){
                ans = max(ans,med[el]);
            }
        }
        if(ans>0){
            med[nd] = ans;
        }
        
    }else{
        ans = inf;
        for(auto el:adj[nd]){
            if(el!=par){
                ans = min(ans,med[el]);
            }
        }
        if(ans<inf){
            med[nd] = ans;
        }

    }
}

void solve(int testcases){
    cin>>n;
    a.resize(n+1);
    adj.resize(n+1);
    med.resize(n+1);

    rep(i,1,n+1){
        cin>>a[i];
    }
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    multiset<int>ms;
    func(1, 0, ms, ms.end());
    func2(1,0,0);
    ll ans = med[1];
    cout<<ans<<endl;

    // ms.insert(2);
    // auto it = ms.begin();
    // ms.insert(2);
    // ms.insert(1);
    // ms.insert(2);
    // debug((it==(++ms.begin())))


    debugc(med)



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
