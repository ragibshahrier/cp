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



vi dpp(200,-1);

ll func(ll n, vi& c){
    debug(n)
    if(n==0){
        return 0;

    }
    if(n<0){
        return inf;
    }
    if(dpp[n]!=-1)return dpp[n];
    ll ans = inf;
    for(auto cc:c){
        ans = min(ans,func(n-cc, c)+1);
    }
    debug(n)
    debug(ans)
    return dpp[n]=ans;
}

void preprocessing(){

}


void solve(){
    vi c = {1,3,6,10,15};
    ll n;
    cin>>n;
    ll ans = 0;
    if(n>50){
        ans+=(n-50)/15;
        ll nn = (n-50)%15 + 50;
        cout<<ans+func(nn,c)<<endl;
        return;

    }
    cout<<func(n,c)<<endl;

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
