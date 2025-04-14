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
const ll N = 200 + 7;
const ll K = 200 + 7;
const ll D = 1e4 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//



int n,k;

void preprocessing(){

}

pi pp(int i){
    int t = 0;
    int ii =i ;
    while(ii%2==0 && ii>0){
        t++;
        ii/=2;
    }
    ii = i;
    int f= 0;
    while(ii%5==0 && ii>0){
        f++;
        ii/=5;
    }
    return {f,t};
}

// int func(int i, int left, vpi& ft){
//     if(left==0 || i>=n){
//         return 0;
//     }
    
// }



pi lastff(multiset<pi>ms){
    if(ms.empty()){
        return {0,0};
    }
    auto it = --ms.end();
    return *it;
    
}
int dpp[D][2][K];

void solve(int testcases){
    cin>>n>>k;

    vi a(n);
    get_vector(a);

    random_shuffle(All(a));

    

    vi f(n+1);
    vi t(n+1);

    int fs = 0;
    int ts = 0;

    
    
    rep(i,0,n){
        pi x = pp(a[i]);
        f[i+1] = x.ff;
        fs += f[i+1];
        t[i+1] = x.ss;
        ts += t[i+1];
    }


    int mx = min(fs,ts);

    int up = min(mx+5, 1000LL);
    int down = 5003-up;
    up = min(5003+up+2,D);

    // debugc(f);
    // debugc(t);
    
    memset(dpp, -1, sizeof(dpp));


    rep(i,0,n+1){
        rep(j,0,k+1){
            rep(d,down,up){
                if(i==0){
                    if(j==0){
                        dpp[d][i&1][j] = 0;
                    }else{
                        dpp[d][i&1][j] = -inf;
                    }
                    continue;
                }
                int dd = d-5003;
                int take = d-t[i]+f[i];
                take = max(down, take);
                take = min(take, up-1);
                int aa = -inf;
                if(j>0)aa = dpp[take][(i-1)&1][(j-1)];
                int bb = dpp[d][(i-1)&1][j];
                if(dd>0){
                    aa += min(dd+f[i], t[i]);
                }else if(dd<0){
                    aa += min(-dd+t[i], f[i]);
                }else{
                    aa += min(t[i],f[i]);
                }
                dpp[d][i&1][j] = max(aa,bb);

            }
        }
    }

    ll ans = dpp[5003][n&1][k];

    debug(dpp[5003-1][2][1])
    debug(dpp[5003-3][1][0])
    debug(dpp[5003-1][1][1])
    debug(dpp[5003-3][0][0])

    cout<<ans<<endl;










}

int32_t main(){
    fastcin();
    srand(time(0));

    int t=1;
    // cin>>t;
    preprocessing();
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
