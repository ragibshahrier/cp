#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
 
typedef long long ll;
 
#define int long long
 
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

// #define DEBG

#define debug(n)
#define debugc(a)
#define debugcc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<'{'<<gp<<el.ff<<','<<el.ss<<gp<<'}'<<gp;}cout<<']'<<endl;
#endif

#define fastcin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'


#define All(a) a.begin(),a.end()
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}


const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;
const ll N = 2e5 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//



int l1, l2, l3, c1, c2, c3;
int n, fr, to;
vi dis;

void preprocessing(){

}


int dist(int st1, int st2){
    debug(dis[st1])
    debug(dis[st2])
    return (dis[st2] - dis[st1]);
}

vi dpp(N, -1);

int func(int from){
    if(from==to)return 0;
    if(from>to)return inf;
    ll ans = inf;

    if(dpp[from]!=-1)return dpp[from];

    auto it = --upper_bound(All(dis), dis[from]+l1);
    int went = it-dis.begin();
    int diss = dist(from,to);
    if(0<diss && diss<=l1)ans = min(ans, c1);
    else if(went!=fr && went<=to && dist(from,went)<=l1 && dist(from,went)>0)ans = min(ans, c1+func(went));

    it = --upper_bound(All(dis), dis[from]+l2);
    went = it-dis.begin();
    debug(went)
    diss = dist(from,to);
    debug(from)
    debug(went)
    debug(dist(from,went))
    if(l1<diss && diss<=l2){
        debug(diss)
        ans = min(ans, c2);
    }
    else if(went!=fr && went<=to && dist(from,went)<=l2 && dist(from,went)>l1){
        debug(c2)
        ans = min(ans, c2+func(went));
    }

    it = --upper_bound(All(dis), dis[from]+l3);
    went = it-dis.begin();
    diss = dist(from,to);
    debug(went)
    if(l2<diss && diss<=l3){
        ans = min(ans, c3);
    }
    else if(went!=fr && went<=to && dist(from,went)<=l3 && dist(from,went)>l2)ans = min(ans, c3+func(went));

    return dpp[from] = ans;
}

void solve(int testcases){
    cin>>l1>>l2>>l3>>c1>>c2>>c3;
    debug(c1)
    debug(c2)
    debug(c3)
    cin>>n>>fr>>to;
    if(to<fr)swap(fr,to);

    dis.push_back(0);
    dis.push_back(0);

    rep(i,0,n-1){
        int x;
        cin>>x;
        dis.push_back(x);
    }
    debugc(dis)
    ll ans = func(fr);
    cout<<ans<<endl;


}

int32_t main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    rep(i,1,t+1)solve(i);
    return 0;
}
