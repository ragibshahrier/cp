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




void preprocessing(){

}

vll par;

ll find(int i){
    if(par[i]==i){
        return i;
    }
    return par[i] = find(par[i]);
}


void solve(int testcases){
    int n;
    cin>>n;
    par.clear();
    par.resize(n);
    vi a(n);
    get_vector(a);
    set<pi>s;
    int mx = -1;
    rep(i,0,n){
        if(mx==-1 || a[mx]<a[i]){
            s.insert({a[i],i});
            mx = i;
            par[i] = i;
        }
        else{
            par[i] = mx;
            auto it = s.upper_bound({a[i],inf});
            for(;it!=s.end();){
                auto itt = it;
                it++;
                if(itt->first < a[mx]){
                    par[itt->second] = mx;
                    s.erase(itt); 
                }
            }
        }
    }
    debugc(par)
    rep(i,0,n){
        par[i] = find(i);
    }
    rep(i,0,n){
        cout<<a[par[i]]<<gp;
    }
    cout<<endl;

}

int32_t main(){
    fastcin();
    freopen("out.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1)solve(i);
    return 0;
}
