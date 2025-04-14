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
const ll N = 1e7 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//


set<int> primes;

void preprocessing(){
    int nn = 1e8+10;
    vi erat(N);
    rep(i, 2, N){
        if(erat[i]){
            continue;
        }
        primes.insert(i);
        for(int j = i+i; j<N; j+=i){
            erat[j] = 1;
        }
    }

}

// void solve(int testcases){
//     int i = 1;
//     rep(j,i,17){
//         int t = 0;
//         int k=1 ;
//         for(; k<16; k++){
//             t*=10;
//             t+=2;
//             // debug(t)
//             if(t%j==0){
//                 break;
//             }
//         }
//         if(k>=16)cout<<j<<gp<<-1<<endl;

//         else cout<<j<<gp<<k<<endl;
        
//     }

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

int isprime(int n){
    if(primes.find(n)!=primes.end()){
        return 1;
    }
    return 0;
}

int order(int n, int m){
    int tut = m;
    for(int i = 1; i*i<=m; i++){
        if(m%i==0){
            if(isprime(i)){
                tut/=i;
                tut*=(i-1);
            }
            if(i!=m/i){
                if(isprime(m/i)){
                    tut/=(m/i);
                    tut*=(m/i-1);
                }
            }
        }
    }
    set<int>divs;
    for(int i = 1; i*i<=tut; i++){
        if(tut%i==0){
            divs.insert(i);
            divs.insert(tut/i);
        }
    }

    for(auto el:divs){
        if(power(n,el,m)==1){
            return el;
        }
    }
    return -1;


}

// int order(int n, int m){
//     int y = n;
//     int i;
//     for(i=1; i<m; i++){
//         if(y%m == 1){
//             return i;
//         }
//         y*=n;
//         y%=m;
//     }
//     return i;
// }


void solve(int testcases){
    // if(testcases!=1){
    //     cout<<endl;
    // }
    int n;
    cin>>n;
    // debugc(primes)

    if(n%2==0){
        n/=2;
    }
    if(n==1){
        cout<<1<<endl;
        return;
    }
    
    if(__gcd(n,10LL)!=1){
        cout<<-1<<endl;return;
    }
    n*=9;
    
    // if(10%n==1){
    //     cout<<n<<endl;return;
    // }

    // if(__gcd(9LL,n)!=1){
    //     n*=9;
    // }
    
    ll ans;
   
    ans = order(10, n);

    cout<<ans<<endl;
    



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
