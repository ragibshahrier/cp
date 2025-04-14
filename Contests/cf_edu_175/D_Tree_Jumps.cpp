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
const ll M = 998244353;
const ll N = 2e5 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(int testcases){
    int n;
    cin>>n;

    vi a(n-1);
    get_vector(a);

    vvi child(n+1);
    vi lvl(n+1);
    vvi lvlmem(n+2);

    int mxlvl = 0;
    
    rep(i,0,n-1){
        lvl[i+2] = lvl[a[i]]+1;
        lvlmem[lvl[i+2]].push_back(i+2);
        child[a[i]].push_back(i+2);
        mxlvl = max(lvl[i+2], mxlvl);
    }

    vi lvltot(mxlvl+3);
    vi mem(n+3);
    debug(mxlvl)

    for(int i = mxlvl; i>=1; i--){
        lvltot[i] = lvlmem[mxlvl].size();
        for(auto el:lvlmem[i]){
            mem[el]++;
            
        }
        if(i==mxlvl){
            continue;
        }
        debugc(mem)
        for(auto el:lvlmem[i]){
            debugc(lvlmem[i])
            debug(lvltot[i+1])
            debug(el)
            
            // mem[el]++;
            mem[el]%=M;
            mem[el]+=lvltot[i+1];
            mem[el]%=M;
            for(auto ell:child[el]){
                mem[el]-=mem[ell];
                mem[el]%=M;
                mem[el]+=M;
                mem[el]%=M;
            }
            debugc(mem)
        }
        debugc(mem)

        lvltot[i] = 0;
        for(auto el:lvlmem[i]){
            lvltot[i] += mem[el];
            lvltot[i]%=M;
        }

        





    }

    cout<<lvltot[1]%M+1<<endl;





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
