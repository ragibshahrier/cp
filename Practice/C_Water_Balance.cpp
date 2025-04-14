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




void preprocessing(){

}

double calcavg(int lo, int hi, vi&pref){
    int sum = pref[hi+1]-pref[lo];
    double avg = (1.0 *sum)/(hi-lo+1);
    return avg;
}

void solve(int testcases){
    int n;
    cin>>n;
    vi a(n);
    get_vector(a);

    vi pref(n+1);
    rep(i,1,n+1){
        pref[i] = pref[i-1]+a[i-1];
    }
    debugc(pref)
    int i = 0;
    vector<double>ans(n);
    while(i<n){
        int lo = i;
        int hi = n-1;
        while(hi-lo>1){
            int mid = (hi+lo)/2;
            if(calcavg(i,mid, pref)<calcavg(mid+1,hi,pref)){
                hi = mid;
            }else{
                lo = mid+1;
            }
        }
        int end;
        if(calcavg(i,lo,pref)<calcavg(i,hi,pref)){
            ans[i] = calcavg(i,lo,pref);
            end = lo;
        }else{
            ans[i] = calcavg(i,hi,pref);
            end = hi;
        }
        rep(j,i,end+1){
            ans[j] = ans[i];
        }
        i = end+1;

    }
    rep(i,0,n){
        cout<<setprecision(10)<<fixed<<ans[i]<<endl;
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
