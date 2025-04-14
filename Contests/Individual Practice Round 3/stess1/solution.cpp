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




void preprocessing(){

}

void solve(int testcases){
    int n,m;
    cin>>n>>m;
    vi pcan;
    vi can;
    vi canop;
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        switch (x)
        {
        case 0:
            pcan.push_back(y);
            break;
        case 1:
            can.push_back(y);
            break;
        case 2:
            canop.push_back(y);
            break;
        
        default:
            break;
        }
    }
    int v1 = pcan.size();
    int v2 = can.size();
    int v3 = canop.size();
    sort(All(canop),greater<int>());
    rep(i,1,v3){
        canop[i]+=canop[i-1];
    }
    ll ans = 0;

    sort(All(pcan), greater<int>());
    sort(All(can), greater<int>());

    debugc(pcan)
    debugc(can)
    debugc(canop)

    int happy = 0;
    rep(i,0,min(m,v1)){
        happy+=pcan[i];
    }
    int p1 = min(m,v1);
    int p2 = 0;
    int gotop = 0;
    if(p1+p2+gotop<=m && p1+p2+v3>=m)ans=max(ans,happy);

    debug(p1+p2+gotop)

    rep(i,0,m+1){
        if(p2==v2){
            break;
        }

        gotop = lower_bound(All(canop), p2+1)-canop.begin() +1;
        if(gotop>v3){
            break;
        }
        happy+=can[p2];
        p2++;

        while(p1+p2+gotop>m && p1>0){
            happy-=pcan[p1-1];
            p1--;
        }

        debug(gotop)
        debug(p1)
        debug(p2)
        if(p1+p2+gotop<=m && p1+p2+v3>=m)ans=max(ans,happy);

        // if(p1+p2<m-gotop){
            
        // }
    }
    cout<<ans<<endl;

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
