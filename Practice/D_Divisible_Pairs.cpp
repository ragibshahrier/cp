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

// #define DEBG

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
    int n,x,y;
    cin>>n>>x>>y;
    vi a(n);
    map<pi,int> xx,yy;
    rep(i,0,n){
        cin>>a[i];
        xx[{a[i]%x, a[i]%y}]++;
    }
    ll ans=0;
    // for(auto el:xx){
    //     cout<<el.ff.ff<<gp<<el.ff.ss<<gp<<gp<<el.ss<<endl;
    // }
    rep(i,0,n){
        ans+=xx[{(x-(a[i]%x))%x, a[i]%y}];
        debug(i)
        if((2*(a[i]%x))%x == 0){
            ans--;
        }
        debug(ans)

    }
    ans/=2;
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
