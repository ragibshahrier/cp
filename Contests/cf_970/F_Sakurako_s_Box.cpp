#include<bits/stdc++.h>
using namespace std;
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

//#define DEBG

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
const ll mm = 1e9 + 7;
const ll N = 2e5 + 7;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

int modInverse(ll A, ll M)

{   
    
    ll m0 = M;
    ll y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1) {
        ll q = A / M;
        ll t = M;

        
        M = A % M, A = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

void solve(){
    ll n;
    cin>>n;
    vll a(n);
    get_vector(a);
    ll sum = 0;
    rep(i,0,n){
        sum+=a[i];

    }
    ll x = 0;
    rep(i,0,n){
        x= (x+((sum%mm-a[i])*a[i])%mm)%mm;
    }
    x%=mm;
    // cout<< 18*modInverse(8,mm)<<endl;
    // cout<< 9*modInverse(4,mm)<<endl;
     
   
    ll ans = x*modInverse(n*(n-1),mm);
    ans%=mm;
    ans+=mm;
    ans%=mm;
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
