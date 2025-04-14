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

int iPow(int a, int e) {
    int r = 1;
    if (e == 0) return r;
    while (e != 0) {
        if ((e & 1) == 1) r *= a;
        e >>= 1;
        a *= a;
    }
    return r;
}

int nthRoot(int n, int a) {
    int v = 1, bit, tp, t;
    if (n == 0) return 0; 
    if (n == 1) return a;
    tp = iPow(v,n);
    while (tp < a) { 
        v <<= 1;
        tp = iPow(v,n);
    }
    if (tp == a) return v; 
    v >>= 1;
    bit = v >> 1;
    tp = iPow(v, n);   
    while (a > tp) {
        v += bit;      
        t = iPow(v, n);
        if (t > a) v -= bit;    
        else tp = t;
        if ( (bit >>= 1) == 0) break;
    }
    return v;   
}

// int nthRoot(int n, int m) {
//     if (n == 1) {
//         return m;
//     }

//     double  low = 1LL, high = min((int)(1e9+3), m), mid;
//     long long  ans = -1;
//     while (high-low>1) {
//         mid = low + (high-low)/2;
//         mid = (int)mid;

//         double  x = mid;
//         debug(mid)
//         debug(x)
//         for (int i = 1; i < n; i++) {
//             x *= mid;
//             debug(x)
//             if (x > m * 1LL || x<0){
//                 debug(1)
//                 if(x<0){
//                     x=m+10;
//                 }
//                 break;
//             }
//         }
//         debug(x)
//         debug(m)
//         debug(mid)
//         debug(high)
//         debug(low)
//         if (x == m * 1LL) {
//             // debug(x)
//             ans = mid;
//             return ans;
//             // break;
//         } else if (x > m)
//             high = mid - 1;
//         else
//             low = mid;

//         debug(high)
//         debug(low)
//     }
//     // debug(ans)
//     debug(high)
//     debug(low)
//     long long  x = high;
//     for (int i = 1; i < n; i++) {
//         x *= high;
//         if (x > m * 1LL || x<0)
//             return low;
//     }
//     debug(x)

//     return (high);
// }

int sqrtt(int m){
    ll lo = 1, hi = min((int)(1e9+3), m);
    ll  ans = -1;

    while(lo<=hi){
        int mid = lo + (hi-lo)/2;

        if (mid*mid == m * 1LL) {
            ans = mid;
            return ans;
        } else if (mid*mid > m)
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    return ans;

}

int func(int l){
    if(l==0)return 0;
    if(l<=3)return 1;
    set<int>s;

    int N = nthRoot(4,l);
    debug(N)
    int a = nthRoot(3,l);
    debug(a)
    int b = nthRoot(2,l);
    debug(b)
    int M = l;

    int aa=0, bb = 0;
    int cnt = 0;

    rep(i,2,N+1){
        if(s.find(i)!=s.end())continue;
        double x = 1.0*i*i;
        while(x<=M && x>0){
            cnt++;
            // debug(x)
            // if(sqrtt(x)<=N)
            s.insert((int)x);
            if(N<x && x<=a)aa++;
            else if(a<x && x<=b)bb++;
            x=x*i;
        }
    }
    debug(cnt)

    // debugc(s)
    ll ans = s.size() + (b-a-bb) + (a-N-aa)*2;
    // cout<<s.size()<<endl;
    return ans+1;

    // for(auto el:s){
    //     cout<<el<<endl;
    // }
}

int func2(int n){
    if(n==0)return 0;
    if(n<4)return 1;
    int i = nthRoot(2,n);
    vi v;
    v.push_back(i);
    int ii = 3;
    debugc(v)
    while(v.back()>1 && ii<70){
        i = nthRoot(ii,n);
        v.push_back(i);
        ii++;
    }
    debugc(v)

    int ans = 0;
    int nn = v.size();

    rep(i,0,nn-1){
        ans+=(v[i]-v[i+1])*(i+1);
    }

    return ans+1;
}

void solve(int testcases){
    int l,r;
    cin>>l>>r;
    int y = func(r)-func(l-1);
    cout<<y<<endl;
    




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
