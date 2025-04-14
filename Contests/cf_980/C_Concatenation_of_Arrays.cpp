#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
 
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




void preprocessing(){

}

bool cmp(pair<pi,int> a, pair<pi,int> b){
    pi x = a.ff;
    pi y = b.ff;
    ll ans1 = 0,ans2 = 0;
    ans1 = (x.ff>y.ff)+(x.ss>y.ff)+(x.ff>y.ss)+(x.ss>y.ss);
    ans2 = (y.ff>x.ff)+(y.ss>x.ff)+(y.ff>x.ss)+(y.ss>x.ss);
    if(ans1<ans2){
        return 1;
    }else if(ans1>ans2){
        return 0;
    }else{
        if(abs(x.ff-x.ss)>abs(y.ff-y.ss)){
            return 0;
        }else{
            return 1;
        }
    }
}

void collision(){
    int n;
    cin>>n;
    vi a(n);
    get_vector(a);
    ll ans = 0;
    rep(i,0,n){
        rep(j,i,n){
            if(a[i]>a[j]){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<pi,int>> a(n);
    // get_vector(a);
    rep(i,0,n){
        cin>>a[i].ff.ff>>a[i].ff.ss;
        a[i].ss = i;
    }

    sort(All(a),cmp);
    rep(i,0,n){
        cout<<a[i].ff.ff<<gp<<a[i].ff.ss<<gp;
    }
    cout<<endl;
    debug(cmp({{1,3},0},{{1,3},1}))

}

int main(){
    fastcin();

    int t=1;
    preprocessing();
    cin>>t;
    while(t--)solve();
    // collision();
    return 0;
}
