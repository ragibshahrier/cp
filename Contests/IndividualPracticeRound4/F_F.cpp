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

vvi adj1(N);
vvi adj2(N);
vi visited1(N);
vi visited2(N);

int A,B,C;
int a,c;
int found = 0;

int dfs1(int nd , set<int>&s, vi& v){
    if(s.find(nd)!=s.end()){
        return 0;
    }
    s.insert(nd);
    v.push_back(nd);
    if(nd==C){
        if(s.find(B)!=s.end()){
            found = 1;
        }
        s.erase(nd);
        v.pop_back();
        return 1;
    }
    if(nd==A)a=1;
    for(auto el:adj2[nd]){
        dfs1(el, s, v);
    }
    v.pop_back();
    s.erase(nd);
    return 1;
}
// int dfs2(int nd, set<int>&s, vi& v){
//     if(s.find(nd)!=s.begin()){
//         return 0;
//     }
//     s.insert(nd);
//     v.push_back(nd);
//     if(nd==A){
//         s.erase(nd);
//         v.pop_back();
//         return 1;
//     }
//     if(nd==B){
//         s.erase(nd);
//         v.pop_back();
//         return 0;
//     }
//     if(nd==C)c=1;
//     for(auto el:adj1[nd]){
//         dfs2(el);
//     }
// }

void solve(int testcases){
    int n,m;

    cin>>n>>m;
    cin>>A>>B>>C;

    rep(i,0,m){
        int x,y;

        cin>>x>>y;
        // if(x!=A && y!=A){
        //     adj1[x].push_back(y);
        //     adj1[y].push_back(x);
        // }
        // if(x!=C && y!=C){
        //     adj2[x].push_back(y);
        //     adj2[y].push_back(x);
        // }
        adj2[x].push_back(y);
        adj2[y].push_back(x);
    }

    a=0;
    set<int>s;
    vi v;
    dfs1(A, s, v);
    // if(a==0){
    //     cout<<"No"<<endl;
    //     return;
    // }

    // c = 0;
    // dfs2(B);
    // if(c==0){
    //     cout<<"No"<<endl;
    //     return;
    // }
    if(found)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


    



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
