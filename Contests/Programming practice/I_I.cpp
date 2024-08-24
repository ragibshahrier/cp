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

//#define DEBG

#define debug(n)
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#endif

#define fastcin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'


#define All(a) a.begin(),a.end()
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}


const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;


//==============================CODE STARTS HERE==============================//



ll n,s;
vll a;

void preprocessing(){

}

bool check(ll mid){
    ll sum = 0;
    rep(i,0,n){
        sum+=min(mid,a[i]);
    }
    if(sum<=s)return 1;
    return 0;

}

void solve(){
    cin>>n>>s;
    a.resize(n);
    get_vector(a);
    ll sum = 0;
    rep(i,0,n){
        sum+=a[i];
    }
    if(sum<=s){
        cout<<"infinite";return;
    }
    ll lo = 0;
    ll hi = s;
    ll mid=(hi+lo)/2;
    while(hi-lo>1){
        mid = (hi+lo)/2;
        if(check(mid)){
            lo = mid;
        }else{
            hi = mid-1;
        }
    }
    if(check(hi)){
        cout<<hi;
    }else{
        cout<<lo;
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
