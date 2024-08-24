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

//#define DEBG

#define debug(n)
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#endif

#define fastcin() ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;


//----------------------CODE STARTS HERE-------------------




void preprocessing(){

}

ll operation_count(vi& a, vi& b, ll x){
    int n = a.size();
    ll opc = 0;
    rep(i,0,n){
        
    }
}

void solve(){
    int n,k;
    cin>>n>>k;
    vi a(n), b(n);
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        cin>>b[i];
    }
    int x = 0;
    for(int i = n/2; i>0; i/=2){
        while(operation_count(a,b,x+i)>k)x+=i;
    }



}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
