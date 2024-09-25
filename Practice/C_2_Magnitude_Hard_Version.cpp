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
const ll M = 998244353;
const ll N = 2e5 + 7;


//==============================CODE STARTS HERE==============================//


vll a;
int n;

vector<vector<pll>>dpp(N, vector<pll>(2,{-1,-1}));

void preprocessing(){

}

pll funcmaxi(int lvl, int maxmin){
    if(lvl == n){
        if(maxmin==0)return {0,1};
        else return {0,1};
    }
    if(dpp[lvl][maxmin].ff !=-1){
        return dpp[lvl][maxmin];
    }
    pll maxi = funcmaxi(lvl+1,0);
    pll mini = funcmaxi(lvl+1,1);
    pll ans;

    if(maxmin==0){
        debug(mini.ss)
        ans.ff = (maxi.ff + a[lvl]);
        ans.ss = maxi.ss;
        debug(ans.ff)
        debug(ans.ss)
        if(ans.ff<=abs(maxi.ff+a[lvl])){
            if(ans.ff == abs(maxi.ff+a[lvl])){
                ans.ss += maxi.ss;
            }else{
                ans.ff = abs(maxi.ff+a[lvl]);
                ans.ss = maxi.ss;
            }
        }
        debug(ans.ff)
        debug(ans.ss)
        if(ans.ff<=abs(mini.ff+a[lvl])){
            if(mini.ff!=maxi.ff){
                if(ans.ff==abs(mini.ff+a[lvl]))ans.ss += mini.ss;
                else ans.ss = mini.ss;
                ans.ff = abs(mini.ff+a[lvl]);
            }else{
                // ans.ff = abs(mini.ff+a[lvl]);
                // ans.ss = mini.ss;
            }
        }
        
        
    }else{
        ans.ff = (mini.ff + a[lvl]);
        ans.ss = mini.ss;
        if(ans.ff>=abs(mini.ff+a[lvl])){
            if(ans.ff == abs(mini.ff+a[lvl])){
                ans.ss += mini.ss;
            }else{
                ans.ff = abs(mini.ff+a[lvl]);
                ans.ss = mini.ss;
            }
        }
        
        // if(ans.ff>=mini.ff+a[lvl]){
        //     if(ans.ff == mini.ff+a[lvl]){
        //         ans.ss += mini.ss;
        //     }else{
        //         ans.ff = mini.ff+a[lvl];
        //         ans.ss = mini.ss;
        //     }
        // }

        
    }
    debug(lvl)
    debug(maxmin)
    debug(ans.ff)
    debug(ans.ss)
    ans.ss%=M;
    return dpp[lvl][maxmin]=(ans);
}

void solve(){
    
    cin>>n;
    a.resize(n);
    get_vector(a);
    rep(i,0,n+2){
        dpp[i][0] = {-1,-1};
        dpp[i][1] = {-1,-1};
    }
    reverse(All(a));

    pll ans = funcmaxi(0,0);
    cout<<ans.ss<<endl;


}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
