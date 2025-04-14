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

void solve(int testcases){
    int n;
    cin>>n;

    vvi vs(n, vi(5));

    rep(i,0,n){
        get_vector(vs[i]);
    }

    if(n<=2){
        cout<<n<<endl;
        rep(i,0,n){
            cout<<i+1<<endl;
        }
        // return;
    }

    // debug(1)

    vi bads(n+1);
    vi goods;

    vvi dots(n+1, vi(n+1));

    rep(i,1,n+1){
        rep(j,i,n+1){
            dots[i][j] = 0;
            rep(k,0,5){
                dots[i][j]+=vs[i-1][k]*vs[j-1][k];
            }
            dots[j][i] = dots[i][j];
        }
    }

    rep(i,1,n+1){
        // if(good){
        //     break;
        // }
        if(bads[i]==1){
            continue;
        }
        int f = 0;
        rep(j,1,n+1){
            rep(k,1,n+1){
                if(j==k || j==i || k==i)continue;
                int an = dots[j][k]-dots[i][j]-dots[i][k]+dots[i][i];
                if(an>0){
                    f = 1;
                    break;
                }else{
                    bads[j] = 1;
                    bads[k] = 1;
                }
            }
            if(f)break;
        }

        if(f)bads[i]=1;
        else{
            // good = i;
            goods.push_back(i);
            break;
            
        } 

    }
    int nn = goods.size();
    cout<<nn<<endl;

    rep(i,0,nn){
        cout<<goods[i]<<endl;
    }

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
