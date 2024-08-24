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

#define DEBG

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

void solve(){
    ll n,l;
    cin>>n>>l;
    vector<ll>lantern(n);
    for(int i = 0; i<n; i++){
        cin>>lantern[i];
    }
    sort(lantern.begin(), lantern.end(), greater<int>());
    // debugc(lantern)
    ll dif = 0;
    ll mx;
    for(int i = 0; i<n-1; i++){
        ll temp = lantern[i] - lantern[i+1];
        dif = max(dif,temp);
    }
    // debug(lantern[n-1] - 0)
    double dif2 = max((l - lantern[0]), (lantern[n-1] - 0));
    double ans = max(dif2, dif/2.0);
    cout<<fixed<<setprecision(10)<<ans;  

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
