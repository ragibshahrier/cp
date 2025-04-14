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

void solve(int cse){
    ll n,q;
    cin>>n>>q;
    ll nn = n;
    vll primes; 
    ll xx = sqrt(n)+1;
    rep(i,2,xx){
        if(nn%i==0){
            primes.push_back(i);
            while(nn%i==0){
                nn/=i;
            }
        }
    }

    if(nn!=1){
        primes.push_back(nn);
    }
    // debugc(primes)
    vll ans;
    while(q--){
        ll x;
        cin>>x;
        if(n%x!=0){
            ans.push_back(0);
            continue;
        }
        ll xxx = n/x;
        for(auto prime:primes){
            if(xxx%prime==0){
                xxx/=prime;
                xxx*=(prime-1);
            }
        }
        ans.push_back(xxx);

    }
    cout<<"Case "<<cse+1<<": ";
    put_vector(ans);

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,0,t)solve(i);
    return 0;
}
