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
const ll M = 1e9 + 7;
const ll N = 2e5 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    vvll grid(n,vll(k));
    rep(i,0,n){
        rep(j,0,k){
            cin>>grid[i][j];
        }
    }
    vvll reg(k, vll(n));
    rep(j,0,k){
        rep(i,0,n){
            if(i==0){
                reg[j][i]=grid[i][j];
            }else{
                reg[j][i] = grid[i][j]|reg[j][i-1];
            }
        }
    }
    rep(j,0,k){
        debugc(reg[j])
    }
    while(q--){
        int m;
        cin>>m;
        ll mn = 0;
        ll mx = n-1;
        rep(i,0,m){
            int x,y;
            char o;
            cin>>x;
            cin>>ws;
            cin>>o;
            cin>>y;
            debug(x)
            debug(o)
            debug(y)
            x--;
            if(o=='<'){
                mx = min(mx,1LL * (lower_bound(All(reg[x]),y)-reg[x].begin()-1));
            }else{
                mn = max(mn, 1LL * (upper_bound(All(reg[x]),y)-reg[x].begin()));
            }
            debug(mx)
            debug(mn)

        }
        if(mn<=mx){
            cout<<mn+1<<endl;
        }else{
            cout<<-1<<endl;
        }
    }




}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
