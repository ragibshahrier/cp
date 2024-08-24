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

// #define DEBG

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

bool check(ll n){
    debug(n)
    string x = "";
    while(n!=0){
        x.push_back((n%10)+'0');
        n/=10;
    }
    bool d=1;
    for(int i=0; i<=x.length()/2 ; i++)
    {
        if(x[i]!=x[x.length()-i-1]){
            d=0;
            break;
        }
    }
    if(d)return 1;
    return 0;
}

void solve(){
    ll n;
    cin>>n;
    debug(n);
    int i;
    ll hi = 1e6+7;
    ll lo = 0;
    ll mid = (hi+lo)/2;
    while(hi-lo>1){
        mid = (hi+lo)/2;
        if(mid*mid*mid>n){
            hi=mid-1;
        }else{
            lo = mid;
        }
        
    }
    ll cr;
    if(hi*hi*hi<=n)cr=hi;
    else cr = lo;
    // i--;
    debug(cr)
    for(ll i = cr; i>=1; i--){
        debug(i)
        if(check(i*i*i)){
            cout<<i*i*i;
            return;
        }
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
