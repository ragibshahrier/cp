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



int n,p,k;
vi a;

void preprocessing(){

}

int check(int mid){
    int spend = 0;
    int i = mid-1;
    while(i>=0){
        spend += a[i];
        if(i>=k-1)i-=k;
        else if(n-mid+i>=k-1){
            i-=k;
        }
        else i--;
    }

    if(spend<=p){
        return 1;
    }
    return 0;

}

void solve(int testcases){
    cin>>n>>p>>k;
    a.clear();
    a.resize(n);
    get_vector(a);

    sort(All(a));

    vvi f(k);
    int j = 0;
    while(j<k){
        int i  = j;
        while(i+k<=n){
            i+=k;
            f[j].push_back(a[i-1]);
        }
        j++;
    }

    vi pre(n+1);
    rep(i,1,n+1){
        pre[i] = pre[i-1]+a[i-1];
    }
    vvi fff(k);
    int ii = 0;
    for(auto& v:f){
        fff[ii].resize(v.size()+1);

        rep(j,1,v.size()+1){
            fff[ii][j] = fff[ii][j-1]+v[j-1];
        }

        ii++;
    }
    int ans = 0;
    for(int iii = 0; iii<k; iii++){
        debug(ans)
        debug(iii)
        debug(pre[iii])
        debug(*(--upper_bound(All(fff[iii]), p-pre[iii])))
        debugc(fff[iii])
        debugc(f[iii])
        int now = 0; 
        auto it = (--upper_bound(All(fff[iii]), p-pre[iii]));
        if(pre[iii]+(*it)<=p)now = iii+((it)-fff[iii].begin())*k;
        if(ans<now) ans = now;

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
