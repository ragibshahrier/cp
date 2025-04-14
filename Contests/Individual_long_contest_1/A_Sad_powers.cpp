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
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<" ,";}cout<<']'<<endl;
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<'{'<<gp<<el.ff<<','<<el.ss<<gp<<'}'<<gp;}cout<<']'<<endl;
#endif

#define fastcin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'


#define All(a) a.begin(),a.end()
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}


const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e18 + 7;
const ll N = 2e5 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}


int rootup[62] = {0 ,0 ,1000000000 ,1000000 ,31622 ,3981 ,1000 ,372 ,177 ,100 ,63 ,43 ,31 ,24 ,19 ,15 ,13 ,11 ,10 ,8 ,7 ,7 ,6 ,6 ,5 ,5 ,4 ,4 ,4 ,4 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,1 ,1};

int cntt =  0;

int iPow(int a, int e) {
    int r = 1;
    if (e == 0) return r;
    while (e != 0) {
        cntt++;
        if ((e & 1) == 1) r *= a;
        e >>= 1;
        a *= a;
    }
    return r;
}

// int nthRoot(int n, int a) {
//     int v = 1, bit, tp, t;
//     if (n == 0) return 0; 
//     if (n == 1) return a;
//     tp = iPow(v,n);
//     while (tp < a) { 
//         cntt++;
//         v <<= 1;
//         tp = iPow(v,n);
//     }
//     if (tp == a) return v; 
//     v >>= 1;
//     bit = v >> 1;
//     tp = iPow(v, n);   
//     while (a > tp) {
//         v += bit;    
//         cntt++;  
//         t = iPow(v, n);
//         if (t > a) v -= bit;    
//         else tp = t;
//         if ( (bit >>= 1) == 0) break;
//     }
//     return v;   
// }
long long power(long long a, long long b, long long mod)
{
    long long result = 1;
    while (b) {
        if (b & 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

int loo;

int nthRoot(int n, int m) {
    if (n == 1) {
        return m;
    }

    int  low = 1LL, high = min(loo, rootup[n]), mid;
    long long  ans = -1;
    while (high-low>1) {
        mid = low + (high-low)/2;
        mid = (int)mid;

        // double  xx = mid;
        int  x = power(mid, n, M);
        debug(mid)
        debug(x)

        // for (int i = 1; i < n; i++) {
        //     x *= mid;
        //     // debug(x)
        //     // if (x > m * 1LL || x<0){
        //     //     debug(1)
        //     //     if(x<0){
        //     //         x=m+10;
        //     //     }
        //     //     break;
        //     // }
        // }
        debug(x)
        // debug(xx)
        // if(x!=xx)debug("11111111111111111111")
        // debug(m)
        // debug(mid)
        // debug(high)
        // debug(low)
        if (x == m * 1LL) {
            // debug(x)
            ans = mid;
            return ans;
            // break;
        } else if (x > m)
            high = mid - 1;
        else
            low = mid;

        // debug(high)
        // debug(low)
    }
    // debug(ans)
    // debug(high)
    // debug(low)
    long long  x = high;
    for (int i = 1; i < n; i++) {
        x *= high;
        if (x > m * 1LL || x<0)
            return low;
    }
    // debug(x)

    return (high);
}
    


int func(int l){
    if(l==0)return 0;
    if(l<=3)return 1;
    
    int roots[62];
    int cnt[62];

    loo = min((int)1e9, l);
    int loo = l;
    // vvi divisors(62);


    roots[2] = nthRoot(2,loo);
    // int yyyyyyyy = nthRoot(5,l,l);
    // debug(yyyyyyyy)

    rep(i,3,62){
        roots[i] = nthRoot(i,l);
    }
    debugc(roots)

    memset(cnt,0,sizeof(cnt));
    
    for(int i = 61; i>= 2; i--){
        cnt[i]+=roots[i]-1;
        if(!cnt[i])continue;
        for(int j = i+i; j<62; j+=i){
            // cntt++;
            // divisors[j].push_back(i);
            cnt[i]-=cnt[j];
            if(cnt[j]==0)break;
        }
        debugc(cnt)
    }
    debug(cntt)


    // for(int i = 61; i>=2; i--){
    //     debug(cntt)
    //     cnt[i]+=roots[i]-1;
    //     debug(cntt)
    //     if(cnt[i]==0)continue;
    //     for(auto el:divisors[i]){
    //         // cntt++;
    //         cnt[el]-=cnt[i];
    //     }
    // }

    // debugc(cnt)
    int sum = 0;
    rep(i,2,62){
        // cntt++;
        sum+=cnt[i];
    }

    return sum+1;
}

void solve(int testcases){
    int l,r;
    cin>>l>>r;

    int ans  = func(r)-func(l-1);
    cout<<ans<<endl;
    debug(cntt)

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
