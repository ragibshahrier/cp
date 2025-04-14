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

void solve(int testcases){
    int n;
    cin>>n;
    vi a(n);
    get_vector(a);
    vi two;
    map<int,int>mp;
    rep(i,0,n){
        mp[a[i]]++;
    }
    for(auto el:mp){
        if(el.ss>=2){
            two.push_back(el.ff);
        }
    }
    vll ans;
    if(two.size()>=2){
        ans.push_back(two[0]);
        ans.push_back(two[0]);
        ans.push_back(two[1]);
        ans.push_back(two[1]);
        put_vector(ans);
        return;
    }
    if(two.size()==0){
        cout<<-1<<endl;
        return;
    }
    sort(All(a));
    a.erase(lower_bound(All(a),two[0]));
    a.erase(lower_bound(All(a), two[0]));

    ans.push_back(two[0]);
    ans.push_back(two[0]);
    // debugc(a)
    
    rep(i,0,a.size()-1){
        if(a[i+1]-a[i]<two[0]*2){
            // debug(1)
            ans.push_back(a[i]);
            ans.push_back(a[i+1]);
            break;
        }
    }

    if(ans.size()==4)put_vector(ans);
    else cout<<-1<<endl;




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
