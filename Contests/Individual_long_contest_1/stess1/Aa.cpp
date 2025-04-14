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
int func(int l){
}

int nthRoot(int n, int m) {
    if (n == 1) {
        return m;
    }

    double  low = 1LL, high = min((int)(1e9+3), m), mid;
    long long  ans = -1;
    // int ii = 20;
    while (high-low>1) {
        mid = low + (high-low)/2;
        mid = (int)mid;

        double  x = mid;
        debug(mid)
        debug(x)
        for (int i = 1; i < n; i++) {
            x *= mid;
            debug(x)
            if (x > m * 1LL || x<0){
                debug(1)
                if(x<0){
                    x=m+10;
                }
                break;
            }
        }
        debug(x)
        debug(m)
        debug(mid)
        debug(high)
        debug(low)
        if (x == m * 1LL) {
            // debug(x)
            ans = mid;
            return ans;
            // break;
        } else if (x > m)
            high = mid - 1;
        else
            low = mid;

        debug(high)
        debug(low)
    }
    // debug(ans)
    debug(high)
    debug(low)
    long long  x = high;
    for (int i = 1; i < n; i++) {
        x *= high;
        if (x > m * 1LL || x<0)
            return low;
    }
    debug(x)

    return (high);
}

void solve(int testcases){
    
    // set<int>s;
    
    // int N = 100000000;
    // int M = N;
    
    // rep(i,2,N){
    //     int x = i*i;
    //     while(x<=M && x>0){
    //         s.insert(x);
    //         x*=i;
    //     }
    // }
    
    // cout<<s.size()<<endl;
    
    // for(auto el:s){
        //     cout<<el<<endl;
        // }
        
    int N = 1000000-1;
    rep(i,80000,N){
        cout<<nthRoot(4,i)<<gp<<nthRoot(3,i)<<gp<<nthRoot(2,i)<<endl;   
    }
    
    // int y = 586000;
    // int y = 7;
    // cout<<nthRoot(4,y)<<gp<<nthRoot(3,y)<<gp<<nthRoot(2,y)<<endl;   

    

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
