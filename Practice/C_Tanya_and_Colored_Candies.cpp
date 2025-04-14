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
int n,s,k;
vi a;

int absi(int x){
    if(x>=0)return x;
    return -x;
}


struct node{
    int i;
    int q;
    int c;
    bool operator<(const node& other){
        if(q<other.q)return true;
        else if(q>other.q)return false;
        else if(i==s-1) return true;
        else if(other.i==s-1) return false;
        else return c<other.c;
    }
};

int32_t dpp[53][4][53][2560];

int func(int i, int lastCol, int lastVal, int tot, vector<node>&vn){
    if(tot>=k){
        return 0;
    }

    if(i>=n || i<0)return inf;

    if(dpp[i][lastCol][lastVal][tot]!= -1)return dpp[i][lastCol][lastVal][tot];

    // if(tot+vn[i].q >=k && lastCol!=vn[i].c && lastVal<vn[i].q){
    //     return dpp[i][lastCol][lastVal][tot] = 0;
    // }


    ll ans = inf;
    if(i+1<n) ans = min(ans, func(i+1,lastCol,lastVal,tot,vn));
    // ans = min(ans, func(i-1,lastCol,lastVal,tot,vn)+1);
    if(lastCol!=vn[i].c && a[lastVal]<vn[i].q){
        if(tot+vn[i].q>=k) {
            ans = min(ans,absi(vn[i].i- lastVal));
            debug(i)
            debug(lastVal)
            debug(lastCol)
            debug(tot)
            debug(ans)
        }
        else if(i+1<n) {
            
            ans = min(ans, func(i+1, vn[i].c, vn[i].i, tot+vn[i].q, vn)+absi(vn[i].i- lastVal));
            debug(i)
            debug(lastVal)
            debug(lastCol)
            debug(tot)
            debug(dpp[i+1][vn[i].c][vn[i].i][tot+vn[i].q])
            debug(ans)
        }
        // ans = min(ans, func(i-1, vn[i].c, vn[i].q, tot+vn[i].q, vn)+1);
    }
    return dpp[i][lastCol][lastVal][tot] = ans;
    
}


void solve(int testcases){
    cin>>n>>s>>k;

    a.resize(n);
    get_vector(a);
    memset(dpp, -1, sizeof(dpp));

    string str;
    cin>>str;
    vector<node> vn(n);
    rep(i,0,n){
        vn[i].i = i;
        vn[i].q = a[i];
        if(str[i]=='R')vn[i].c = 1;
        if(str[i]=='G')vn[i].c = 2;
        if(str[i]=='B')vn[i].c = 3;
    }
    sort(All(vn));
    int newst = 0;
    debug(vn.size());
    debug(n)
    rep(i,0,n){
        debug(vn[i].i)
    }
    rep(i,0,n){
        if(vn[i].i==s-1){
            newst = i;
            break;
        }
    }
    debug(newst)
    ll ans = inf;
    rep(i,0,n){
        debug(func(i+1,vn[i].c,vn[i].i,vn[i].q,vn))
        // debug(absi(newst-i))
        ans = min(ans, func(i+1,vn[i].c,vn[i].i,vn[i].q,vn)+absi(s-1 - vn[i].i));
    }
    debug(dpp[2][2][2][2])
    if(ans<=3000)cout<<ans<<endl;
    else cout<<-1<<endl;


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
