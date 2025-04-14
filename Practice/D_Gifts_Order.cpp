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

int absi(int a){
    return (a>=0)?a:(-a);

}

void solve(int testcases){
    int n,q;
    cin>>n>>q;
    vi a(n);
    get_vector(a);
    
    multiset<int>ms;

    rep(i,0,n){
        ms.insert(a[i]+i);
    }
    debugc(ms)
    // if(n==1)cout<<0<<endl;
    cout<<max(*(ms.begin()--ms.end()))<<endl;

    while(q--){
        int p,x;
        cin>>p>>x;
        ll ans = 0;
        if(n==1)ans = 0;
        else if(p==1){
            ms.erase(ms.find(absi(a[p-1]-a[p])));
            a[p-1] = x;
            ms.insert(absi(a[p-1]-a[p]));
            ans = max(*(--ms.end())-1,0LL);
        }
        else if(p==n){
            ms.erase(ms.find(absi(a[p-1]-a[p-2])));
            a[p-1] = x;
            ms.insert(absi(a[p-1]-a[p-2]));
            ans = max(*(--ms.end())-1,0LL);
        }
        else{
            ms.erase(ms.find(absi(a[p-1]-a[p-2])));
            ms.erase(ms.find(absi(a[p-1]-a[p])));
            a[p-1] = x;
            ms.insert(absi(a[p-1]-a[p-2]));
            ms.insert(absi(a[p-1]-a[p]));
            ans = max(*(--ms.end())-1,0LL);

        }
        cout<<ans<<endl;
    }

}

int32_t main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
