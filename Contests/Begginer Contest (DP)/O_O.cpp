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



vi a;
vll acc;

void preprocessing(){

}

int n,m,k;
ll dpp[5005][5005];

ll func(int st, int prl){
    //m*prl
    if(st+m>n)return 0;
    if(prl<=0)return 0;
    if(dpp[st][prl]!=-1)return dpp[st][prl];
    ll ans = 0;
    // for(int i = st+m; i <=n-m*(prl-1); i++){

    //     ans = max(ans, func(i, prl-1) + acc[i]-acc[i-m]);
    // }
    ans = max(func(st+m, prl-1) + acc[st+m]-acc[st], func(st+1,prl));
    debug(st)
    debug(prl)
    debug(ans)
    return dpp[st][prl] = ans;

}

void solve(){
    cin>>n>>m>>k;
    memset(dpp,-1, sizeof(dpp));
    a.resize(n);
    get_vector(a);
    acc.resize(n+1);
    rep(i,1,n+1){
        acc[i] = acc[i-1]+a[i-1];
    }
    // for(int st = )

    ll ans = func(0, k);
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
