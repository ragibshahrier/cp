#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
 
typedef long long ll;
 
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

ll ans = INT_MIN;
ll bitmx = 0;

vll per;
int n;
vll num;

ll func(){
    ll ans = 0;
    ll x = 1;

    rep(i,0,num.size()-1){
        x*=10;
    }
    int i  = 0;
    for(auto dig:num){
        if(dig==-1){
            dig = per[i];i++;
        }
        ans += dig*x;
        x/=10;
    }
    return ans;
}

ll bitcnt(ll number){
    return __builtin_popcount(number);
}

void perm(int nn){
    if(nn==n){
        ll number = func();
        ll bits = bitcnt(number);

        if(bits>bitmx){
            ans = number;
            bitmx = bits;
        }else if(bits==bitmx){
            ans = max(ans,number);
        }
        return;
    }
    for(int i = 0; i<10; i++){
        per.push_back(i);
        perm(nn+1);
        per.pop_back();
    }
}

void solve(){
    per.clear();
    num.clear();
    ans = INT_MIN;
    bitmx = 0;

    string s;
    cin>>s;
    
    int q=0;
    vi p(q);
    for(auto ch:s){
        if(ch=='?'){
            num.push_back(-1);
            q++;
        }else{
            num.push_back(ch-'0');
        }
    }
    n = q;
    // debug(n)
    perm(0);
    // per = {9,9};
    // num = {-1,-1,1};
    // debug(bitcnt(7));
    // cout<<func(per, num)<<endl;;
    cout<<ans<<endl;

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
