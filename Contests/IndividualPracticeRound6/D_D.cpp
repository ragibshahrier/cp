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
    int n,m;
    cin>>n>>m;

    vi cangoN(n+m+5,inf);
    vi cangoN2(n+m+5,inf);

    cangoN[n]=0;
    cangoN2[1]=0;

    vector<string>vs(n+1);

    rep(i,1,n+1){
        string s;
        cin>>s;

        vs[i] = s;
    }

    for(int i = n-1; i>=1; i--){
        rep(j,0,m){
            debug(i+j+1)
            if(cangoN[i+j+1]!=inf && vs[i][j]=='1'){
                cangoN[i]=min(cangoN[i+j+1]+1, cangoN[i]);
            }
        }
    }
    for(int i = 1; i<=n; i++){
        rep(j,0,m){
            debug(i+j+1)
            if(vs[i][j]=='1'){
                cangoN2[i+j+1]=min(cangoN2[i]+1, cangoN2[i+j+1]);
            }
        }
    }

    debugc(cangoN)
    vi ans(n+1, inf);
    for(int i = 2; i<=n-1; i++){
        for(int j=i-1; j>=max(0LL,i-m); j--){
            for(int k = 0; k<m; k++){
                if(j+k+1>i && vs[j][k]=='1' && cangoN[j+k+1]!=inf){
                    ans[i] = min(ans[i], cangoN[j+k+1]+cangoN2[j]+1);
                }
            }
        }
    }

    for(int i = 2; i<=n-1; i++){
        if(ans[i]<n+100){
            cout<<ans[i]<<" ";
        }else{
            cout<<-1<<" ";

        }
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
