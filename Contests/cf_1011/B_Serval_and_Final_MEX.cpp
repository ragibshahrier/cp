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
    int n;
    cin>>n;
    vi a(n);
    get_vector(a);
    int f1= 0 ;
    int ii = 0;
    for(; ii<n/2; ii++){
        if(a[ii]==0){
            f1=1;break;
        }
    }
    vpi ansp;
    int f2 = 0;
    debug(ii)
    for(ii = n/2; ii<n;ii++){
        if(a[ii]==0){
            debug(ii)
            debug(a[ii])
            f2=1;break;
        }
    }
    debug(f1)
    debug(f2)

    if(f1==0 && f2==0){
        ansp.push_back({1,n});
    }
    else if(f1==1 && f2==0){
        ansp.push_back({1,n/2});
        ansp.push_back({1,n-n/2+1});
    }else if(f1==0 && f2==1){
        ansp.push_back({n/2+1,n});
        ansp.push_back({1, n/2+1});
    }else{
        ansp.push_back({n/2+1,n});
        ansp.push_back({1,n/2});
        ansp.push_back({1,2});

    }

    cout<<ansp.size()<<endl;
    rep(i,0,ansp.size()){
        cout<<ansp[i].ff<<gp<<ansp[i].ss<<endl;
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
