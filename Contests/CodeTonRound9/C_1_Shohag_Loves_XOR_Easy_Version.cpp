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

void findDivisor(int x, vector<int>&v){
    for(int i = 1; (i*i)<= x; i++){
        if(i == x) continue;
        if(x%i == 0){
            v.push_back(i);
            int j = x/i;
            if(j == x) continue;
            v.push_back(j);
        }
    }
}

void solve(int testcases){
    int x,m;
    cin>>x>>m;
    vector<int>v;
    // findDivisor(x,v);
    int tem = 0;
    int ans = 0;
    // debug(1)
    // debugc(v)
    // for(int i = 0; i<v.size(); i++){
    //     tem = x ^ v[i];
    //     // debug(tem)
    //     if(tem <= m) ans++; 
    // }
    for(int i = 1; i<=(x*3); i++){
        if(i > m) break;
        if(i == x) continue;
        // if(x%i == 0) continue;
        tem = x ^ i;
        if(x % tem == 0){
            ans++;
            continue;
        }
        // if(tem > m) continue;
        if(i % tem == 0) ans++;
    }
    cout<<ans<<"\n";
}

int32_t main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1)solve(i);
    return 0;
}
