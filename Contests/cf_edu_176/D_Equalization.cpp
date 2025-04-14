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
int lim = 30;

int dpp[40][58][58];

int func(int now, int a, int b){
    debug(now)
    debug(a)
    debug(b)
    if(a<=0 && b<=0){
        return 0;
    }
    if(now>35){
        return INF;
    }
    if(dpp[now][a][b]!=-1){
        return dpp[now][a][b];
    }

    int aa=INF,bb=INF,cc=INF;
    // if(a<now && a>0){
    //     return INF;
    // }
    // if(b<now && b>0){
    //     return INF;
    // }

    if(a>0){
        aa= func(now+1, max(0LL,a-now),b);
        if(aa<INF){
            aa+=(1LL<<now);
        }
    } 
    if(b>0){
        bb= func(now+1, a,max(0LL,b-now));   
        if(bb<INF){
            bb+=(1LL<<now);
        }
    }

    cc = func(now+1, a,b);
    ll ans = 0;
    ans =  min({aa,bb,cc});

    debug(ans)


    return dpp[now][a][b]=ans;
    
}

void solve(int testcases){
    int x,y;
    cin>>x>>y;
    memset(dpp, -1,sizeof(dpp));

    int anc;

    int xx =x, yy=y;
    int disx = 0;
    int disy = 0;
    while(xx!=yy){
        if(xx>yy){
            xx/=2;
            disx++;
        }else{
            yy/=2;
            disy++;
        }
    }

    debug(disx)
    debug(disy)
    debug(disx+disy)
    ll ans = func(1,disx,disy);
    cout<<ans<<endl;

}

int32_t main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
