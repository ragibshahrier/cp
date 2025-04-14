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

struct node{
    int val;
    int i;
    int n_i;
    int valact;
    bool operator<(const node& other) const {
        if (valact < other.valact) return true;
        if (valact > other.valact) return false;
        return i > other.i;
    }

};
int fff = 0;

int solve(int testcases){
    int n,c;
    cin>>n>>c;
    vi a(n);
    get_vector(a);

    int iii = 0;
    // if(n==4 && c==21 && testcases==1){
    //     return 1;
    // }

    // if(fff && testcases==345){
    //     // int n,c;
    //     // cin>>n>>c;
    //     cout<<n<<" "<<c<<endl;
    //     put_vector(a);
    //     return 1;
    // }
    // if(fff)return 1;

    vector<node>v;
    rep(i,0,n){
        node x;
        x.val = a[i];
        x.i = i+1;
        x.n_i = n-i;
        x.valact = a[i]+min(i+1,n-i);
        debug(x.valact)

        v.push_back(x);
        debug(v[i].valact)
    }
    debug(v[0].valact)
    sort(All(v));

    int i = 0;
    int f = 0;
    ll sum = 0;
    ll ans = 0;

    while(i<n){
        debug(v[i].valact)
        if(sum + v[i].valact>c){
            break;
        }
        sum += v[i].valact;
        ans++;
        if(v[i].i<=v[i].n_i){
            f=1;
        }
        i++;
    }

    int ii = i-1;
    debug(ans)
    debug(f)
    multiset<int>s;
    for(i; i<n; i++){
        s.insert(v[i].i + v[i].val);
    }
    if(f){
        cout<<ans<<endl;
        return 0;
    }
    debug(sum)
    rep(i,0,ii+1){
        if(sum+(v[i].i-v[i].n_i)<=c){
            cout<<ans<<endl;
            return 0;
        }
    }
    while(ii>=0){
        sum-=v[ii].valact;
        s.insert(v[ii].i+v[ii].val);
        ans--;
        if(*s.begin() + sum <= c){
            ans++;
            cout<<ans<<endl;
            return 0;
        }

        ii--;
    }

    cout<<ans<<endl;
    return 0;
    





}

int32_t main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    // int f= 0;
    rep(i,1,t+1){
       fff |= solve(i);
       
    }
    return 0;
}
