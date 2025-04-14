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

pi func(int n, int m, int c){
    int b = n*m/2;
    int w = n*m-b;

    if(c==0){
        return {w,b};
    }else{
        return {b,w};
    }
}

int cellfind(int n, int m){
    if((n+m) % 2==0){
        return 0;
    }
    return 1;
}


void solve(int testcases){
    int n,m;
    cin>>n>>m;

    int b = n*m/2;
    int w = n*m - b;

    debug(w)
    debug(b)

    int x1,y1, x2,y2;
    int x3,y3, x4,y4;
    int x5,y5, x6,y6;
    cin>>x1>>y1>>x2>>y2;
    
    pi c1 = func(x2-x1+1, y2-y1+1, cellfind(x1, y1));
    debug(c1.ff)
    debug(c1.ss)
    
    cin>>x3>>y3>>x4>>y4;
    pi c2 = func(x4-x3+1, y4-y3+1, cellfind(x3, y3));
    
    w-=c2.ff;
    b+=c2.ff;

    debug(c2.ff)
    debug(c2.ss)
    
    x5 = max(x1, x3);
    x6 = min(x2,x4);
    y5 = max(y1, y3);
    y6 = min(y2,y4);
    
    if(x5<=x6 && y5<=y6){
        pi c3 = func(x6-x5+1, y6-y5+1, cellfind(x5, y5));
        c1.ff-=c3.ff;
        c1.ss-=c3.ss;
    }

    debug(c1.ff)
    debug(c1.ss)
    
    b-=c1.ss;
    w+=c1.ss;


    cout<<w<<gp<<b<<endl;



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
