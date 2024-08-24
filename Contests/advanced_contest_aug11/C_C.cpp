#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
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

#ifndef ONLINE_JUDGE
#define DEBG
#endif

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




void preprocessing(){

}

bool check(ll mid, vll& a, ll mm){
    int n = a.size();
    vll d(n+1);
    ll m=0;
    debug(mid)
    rep(i,0,n){
        debug(i)
        if(mid<=d[i] && i==n-1){
            debugc(d)
            break;
        }
        d[i]+=a[i];
        m++;
        debug(d[i])
        debug(m)
        ll x = 0;
        if(mid>d[i])x=(mid-d[i])/a[i] + ((mid-d[i])%a[i]!=0);
        // if(x>0){
        //     m+=x*2;
        //     d[i+1]+=x*a[i+1];

        // }
        m+=x*2;
        if(i<n-1)d[i+1]+=x*a[i+1];
        debugc(d)
        debug(m)
        if(m>mm)return 0;


    }
    debugc(d)
    if(m<=mm)return 1;
    return 0;

}


void solve(){
    ll n,m;
    cin>>n>>m;
    vll a(n);
    get_vector(a);
    if(m<n){
        cout<<0<<endl;return;
    }
    if(m==n){
        cout<<*(min_element(All(a)))<<endl;return;
    }
    ll hi = 1e17;
    ll lo = 0;
    ll mid = (hi+lo)/2;

    // check(6,a,m);
    while(hi-lo>1){
        mid = (hi+lo)/2;
        if(check(mid,a,m)){
            lo=mid;
        }else{
            hi=mid-1;
        }
        
    }
    ll ans = 0;
    if(check(hi,a,m)){
        ans = hi;
    }else{
        ans = lo;
    }
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
