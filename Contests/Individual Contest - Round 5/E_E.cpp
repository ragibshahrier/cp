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

#define DEBG

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


//==============================CODE STARTS HERE==============================//

int n, m,k;
vector<string>vs;
vector<vll>cls;

void preprocessing(){

}

vector<vll>dpp(505,vll(505,-1));

ll func(int lvl, int kk){
    if(lvl==n){
        return 0;
    }
    if(dpp[lvl][kk]!=-1){
        return dpp[lvl][kk];
    }
    vll& a = cls[lvl];
    debugc(a)
    int kkk = kk;
    // debug(a[a.size()-1]-a[0]+1)
    // debug(a[a.size()-1])
    // debug(a[0])
    ll ans = func(lvl+1,kk);
    if(a.size()>0)ans += a[a.size()-1]-a[0]+1;
    // debug(ans)
    kk--;
    for(int i=0, j=a.size()-1; i<=j && kk>=0; kk--){
        ll tempans = inf;
        
        if(i==j){
            tempans = func(lvl+1, kk);
            i++;
        }
        else if(a[i+1]-a[i]>a[j]-a[j-1]){
            i++;
            tempans = a[j]-a[i]+1+func(lvl+1,kk);
        }
        else{
            j--;
            tempans = a[j]-a[i]+1+func(lvl+1,kk);
        }
        
        ans = min(ans,tempans);
    }
    debug(lvl)
    debug(kkk)
    debug(ans)
    return dpp[lvl][kkk] = ans;
    // return ans;
}


void solve(){
    cin>>n>>m>>k;
    vs.resize(n);
    cls.resize(n);
    rep(i,0,n){
        cin>>vs[i];
        rep(j,0,m){
            if(vs[i][j]=='1'){
                cls[i].push_back(j);
            }
        }
    }
    ll ans = func(0,k);
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