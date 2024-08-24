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
const ll N = 1e5 + 7;


//==============================CODE STARTS HERE==============================//


int n,l,k;
vi d;
vi a;

void preprocessing(){

}
int dpp[505][505];

ll func(int ind, int k){
    // debug(ind)
    // debug(k)
    if(k<0)return inf;
    if(ind==n){
        return 0;
    }
    if(dpp[ind][k]!=-1)return dpp[ind][k];
    if(ind==n-1){
        return dpp[ind][k]=a[ind]*(d[ind+1]-d[ind]);
    }
    ll ans = inf;
    // debug(a[ind]*(d[ind+1]-d[ind]))
    rep(i,1,n-ind+1){
        ans = min(ans, (a[ind]*1LL*(d[ind+i]-d[ind]))+1LL*func(ind+i, k-i+1));
        debug(ind)
        debug(ind+i)
        debug(k)
        debug(k-i+1)
        debug(ans)

    }
    // ans = min(ans, (a[ind]*1LL*(d[ind+1]-d[ind]))+1LL*func(ind+1, k));
    // // ll temp = a[ind];
    // // a[ind] = a[ind-1];
    // ans = min(ans, (a[ind]*1LL*(d[ind+2]-d[ind]))+1LL*func(ind+2, k-1));
    // a[ind] = temp;
    debug(ind)
    debug(k)
    debug(ans)
    return dpp[ind][k] = ans;



}

void solve(){
    memset(dpp,-1,sizeof(dpp));
    cin>>n>>l>>k;
    d.resize(n);
    a.resize(n);
    get_vector(d);
    get_vector(a);
    d.push_back(l);
    cout<<func(0, k)<<endl;


}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
