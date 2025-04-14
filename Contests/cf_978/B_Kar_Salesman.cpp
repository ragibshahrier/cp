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


int n,x;
vi a;


void preprocessing(){

}

struct DS{
    vll aa;
    int nn;
    ll x = 1;
    void init(int n){
        nn = n;
        // aa.resize(nn+1);
    }
    //inclusive range[i,j] update
    void update(int i, int j){
        if(i<=j){
            // aa[i]++;
            // aa[j+1]--;
        }
        else{
            // aa[i]++;
            // aa[nn]--;
            // aa[0]++;
            // aa[j+1]--;
            x++;
        }
    }
    ll retrieve(){
        return x;
    }
};

ll check(ll mid){
    ll i = n-1;
    vi aa =a;
    DS ds;
    // ds.init(mid);
    ll xx = 1;
    ll midrem = mid;
    ll j = 0;
    bool b = 0;
    while(i>=0){
        if(aa[i]>mid){
            return 0;
            
        }else{
            // ds.update(j, (j+a[i]-1)%mid);
           j+=a[i];
            
        }
        i--;
        debug(j)
        debug(xx)
        // debug(ds.retrieve())
    }
    // vll aaa = ds.retrieve();
    // xx = ds.retrieve();
    xx = j/mid + (j%mid!=0);
    if(xx<=x){
        return 1;
    }
    return 0;
}

void solve(){
    cin>>n>>x;
    a.clear();
    a.resize(n);
    get_vector(a);
    
    ll hi = 1e15;
    ll lo = 0;
    ll mid = (hi+lo)/2;
    ll ans = 0;
    while(hi-lo>1){
        mid = (hi+lo)/2;
        if(check(mid)){
            hi = mid;
        }else{
            lo = mid+1;
        }

    }
    if(check(lo)){
        ans = lo;
    }else{
        ans = hi;
    }
    // cout<<check(2)<<endl;
    cout<<ans<<endl;



}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
