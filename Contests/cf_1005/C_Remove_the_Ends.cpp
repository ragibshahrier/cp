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


int absi(int x){
    if(x<0)return -x;
    return x;
}

void solve(int testcases){
    int n;
    cin>>n;
    vi a(n);
    get_vector(a);

    // int i = 0, j = 0;
    // int sum = 0;
    // int ans = 0;
    // while(i<n){
    //     sum += absi(a[i]);
    //     if(i!=0 && a[i-1]<0 && a[i]>0){
    //         while(j<i){
    //             sum -= absi(a[j]);
    //             j++;
    //         }
    //     }
    //     ans = max(ans, sum);
    //     i++;
    // }

    vi pref1(n);
    if(a[0]>0)pref1[0] = a[0];
    rep(i,1,n){
        pref1[i]=pref1[i-1];
        if(a[i]>0){
            pref1[i]+=a[i];
        }
    }

    vi pref2(n);

    if(a[n-1]<0)pref2[n-1]=absi(a[n-1]);

    for(int i = n-2; i>=0; i--){
        pref2[i] = pref2[i+1];
        if(a[i]<0){
            pref2[i]+=absi(a[i]);
        }
    }
    int ans = 0;
    // debugc(pref1);
    // debugc(pref2);
    rep(i,0,n){
        ans = max(ans, pref1[i]+pref2[i]);
    }


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
