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

int n,c;

struct node{
    int down;
    int disk;
    int total;
    int ind;
};

vector<node> nodes(N);
vi ansarr(N);

void preprocessing(){

}

bool comptot(node nd1, node nd2){
    if(nd1.total>=nd2.total)return 1;
    return 0;
}
bool compdisk(node nd1, node nd2){
    if(nd1.disk<=nd2.disk)return 1;
    return 0;
}

bool check(ll mid, vector<int>& v, int xx){
    vector<node> nodes2 = nodes;
    vector<node> anscheck;
    ll occd = 0;
    int i = 0;
    while(anscheck.size()<mid){
        int j=i;
        j += mid-anscheck.size();
        if(j>n)break;
        sort(nodes2.begin()+i, nodes2.end(), compdisk);
        
        for(auto el:nodes2){
            cout<<el.ind<<gp;
        }
        cout<<endl;

        sort(nodes2.begin()+i, nodes2.begin()+j, comptot);
        
        for(auto el:nodes2){
            cout<<el.total<<gp;
        }
        cout<<endl;

        debug(anscheck.size())
        debug(occd)

        rep(k, i, j){
            if(c-occd>=nodes2[k].total){
                anscheck.push_back(nodes2[k]);
                if(xx)v.push_back(nodes2[k].ind);
                occd+=nodes2[k].disk;
            }
        }
        i=j;


    }
    if(anscheck.size()==mid)return 1;
    return 0;

}

void gen(ll ans){

}

void solve(int testcases){
    
    cin>>n>>c;
    nodes.resize(n);
    rep(i,0,n){
        ll x,y;
        cin>>x>>y;
        nodes[i].down = x;
        nodes[i].disk = y;
        nodes[i].total = max(x, y);
        nodes[i].ind = i;
    }
    ll hi = n;
    ll lo = 0;
    vector<int> ansv;
    
    // while(hi-lo>1){
    //     ll mid = lo + (hi-lo)/2;

    //     if(check(mid, ansv, 0)){
    //         lo = mid;
    //     }else{
    //         hi = mid-1;
    //     }
    // }
    ll ans;
    // if(check(hi, ansv, 0))ans = hi;
    // else ans = lo;

    // debug(check(ans, ansv, 1))
    // debug(check(0, ansv, 0))
    // debug(check(1, ansv, 0))
    debug(check(2, ansv, 1))

    debugc(ansv)

    



}

int32_t main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    rep(i,1,t+1)solve(i);
    return 0;
}
