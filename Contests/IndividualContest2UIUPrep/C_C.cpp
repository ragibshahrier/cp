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
#define bitcnt(x) ((sizeof(x) <= sizeof(int)) ? (32 - __builtin_clz(x)) : (64 - __builtin_clzll(x)))

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
const ll N = 5000 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//

string s;
vi pre;

vvi dpp(N, vll(N,-1));


void preprocessing(){

}

ll func(int l, int r){
    if(r-l<=1){
        return 0;
    }
    if(s[l]=='a'){
        return func(l+1,r);
    }else if(s[r]=='a'){
        return func(l,r-1);
    }
    if(pre[r+1]-pre[l]==0){
        return 0;
    }
    if(dpp[l][r] != -1){
        return dpp[l][r];
    }
    // else if(pre[r+1]-pre[l]==1){
    //     return 1;
    // }
    // int x = l;
    // int y = r;

    // while(s[x]=='b' && x<y){
    //     x++;
    // }
    // while(s[y]=='b' && x<y){
    //     y--;
    // }
    // ll ans = min(r-y + x-l + func(x,y), pre[y+1]-pre[x]);
    // if(y-x+1 == pre[y+1]-pre[x]){
    //     ans = min({ans, r-y, x-l, y-x+1});
    // }
    // return ans;

    ll ans = min({func(l,r-1)+1, func(l+1,r)+1, pre[r+1]-pre[l]});

    return dpp[l][r] = ans;

}

void solve(int testcases){
    cin>>s;

    int n = s.length();
    pre.resize(n+5);
    rep(i,0,n){
        pre[i+1] = pre[i];
        if(s[i]=='a'){
            pre[i+1]++;
        }
    }
    ll ans = func(0,n-1);    
    cout<<n - ans<<endl;

}

int32_t main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
