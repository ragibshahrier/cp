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
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<'{'<<gp<<el.ff<<','<<el.ff<<gp<<'}'<<gp;}cout<<']'<<endl;
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

ll func(ll x, ll y){
    debug(x)
    debug(y)
    debug(__gcd(x,y))
    if(y==0)return 0;
    return 1+func(x,y-__gcd(x,y));
    return 0;
}

void solve2(){
    ll x,y;
    cin>>x>>y;
    cout<<func(x,y);
}

void solve(){
    ll x,y;
    cin>>x>>y;
    ll ans = 0;
    vll divs;
    for(ll i = 1; i*i<=x; i++){
        if(x%i == 0){
            divs.push_back(i);
            if(x/i!=i){
                divs.push_back(x/i);
            }
        }
    }
    sort(All(divs));
    debug(divs.size())
    ll g = __gcd(x,y);
    ll i = lower_bound(All(divs), g)-divs.begin();
    while(y>0){
        if(y%x==0){
            ans+=y/x;
            break;
        }
        // debugc(divs)
        g = __gcd(x,y);
        i = lower_bound(All(divs), g)-divs.begin();
        ll j;
            debug(y)
            debug(divs[i])
        for(j=i+1;j<divs.size();j++){

            if(divs[j]%divs[i]==0){
                
                debug(divs[j])
                break;

            }
            
        }
        // debug(divs[j]);
        ans+=(y - y/divs[j]*divs[j])/divs[i];
        debug(ans)
        y = y/divs[j]*divs[j];
        i=j;
        // debug(y)
        

    }
    cout<<ans;

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
