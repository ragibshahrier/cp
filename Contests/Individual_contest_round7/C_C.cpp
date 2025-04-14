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
const ll N = 2e5 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(int testcases){
    int n,m;
    cin>>n>>m;

    vvi grid(n,vi(m));
    vvi grid1(n,vi(m));
    vvi grid11(n,vi(m));
    vvi grid2(n,vi(m));
    vvi grid22(n,vi(m));

    rep(i,0,n){
        get_vector(grid[i]);
    }

    rep(i,0,n){
        map<int,int>mp;
        rep(j,0,m){
            mp[grid[i][j]] = 0;
        }
        int k = 1;
        for(auto &el:mp){
            el.ss = k;
            k++;
        }
        k--;
        rep(j,0,m){
            grid11[i][j] = k;
            grid1[i][j] = mp[grid[i][j]]; 
        }
    }
    rep(j,0,m){
        map<int,int>mp;
        rep(i,0,n){
            mp[grid[i][j]] = 0;
        }
        int k = 1;
        for(auto &el:mp){
            el.ss = k;
            k++;
        }
        k--;
        rep(i,0,n){
            grid22[i][j] = k;
            grid2[i][j] = mp[grid[i][j]]; 
        }
    }

    // rep(i,0,n){
    //     rep(j,0,m){
    //         cout<<grid1[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // rep(i,0,n){
    //     rep(j,0,m){
    //         cout<<grid11[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // rep(i,0,n){
    //     rep(j,0,m){
    //         cout<<grid2[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // rep(i,0,n){
    //     rep(j,0,m){
    //         cout<<grid22[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    

    rep(i,0,n){
        rep(j,0,m){
            int temp = max(grid1[i][j], grid2[i][j]);

            int anss = max(temp-grid1[i][j]+grid11[i][j], temp-grid2[i][j]+grid22[i][j]);

            cout<<anss<<" ";
        }
        cout<<endl;
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
