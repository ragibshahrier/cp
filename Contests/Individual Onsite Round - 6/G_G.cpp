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


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(){
    ll n,k,l;
    cin>>n>>k>>l;
    vll a(n*k);
    rep(i,0,n*k){
        cin>>a[i];
    }
    sort(All(a));
    if(k==1){
        debug(a.back()-a[0])
        if(a.back()-a[0]>l){
            cout<<0;return;
        }
        ll sum = 0;
        rep(i,0,n){
            sum+=a[i];
        }
        cout<<sum;return;
    }
    
    int ind  = upper_bound(All(a),a[0]+l)-1-a.begin();
    int indd = ind;
    int x = (n*k-1-ind)/(k-1);
    debugc(a)
    debug(x)
    debug(ind)
    ll sum = 0;
    rep(i,0,x){
       if(ind<0){
        cout<<0;return;
       }
       sum+=a[ind];
       ind--;
    }
    debug(sum)
    x = (n*k-1-indd) - x*(k-1);
    debug(x)
    while(ind>=0){
        
        if(x==k-1){
            sum+=a[ind];
            ind--;
            x=0;
        }else{
            x++;
            ind--;
        }
    }
    debug(x)
    if(x==0){
        cout<<sum;
    }else{
        cout<<0;
    }



}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
