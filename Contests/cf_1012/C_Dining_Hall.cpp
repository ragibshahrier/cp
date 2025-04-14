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


struct node{
    int x;
    int y;
    int st1;
    int st2;
};


vector<node>nodes;

bool comp(node n1, node n2){
    if(n1.st1!=n2.st1){
        return n1.st1<n2.st1;
    }
    if(n1.st2!=n2.st2){
        return n1.st2<n2.st2;
    }
    if(n1.x!=n2.x){
        return n1.x<n2.x;
    }
    return n1.y<n2.y;
}

void preprocessing(){
    rep(i,0,400){
        rep(j,0,400){
            node temp1 = {i*3+1, j*3+1, i+j, 1};
            node temp2 = {i*3+1, j*3+2, i+j, 2};
            node temp3 = {i*3+2, j*3+1, i+j, 2};
            node temp4 = {i*3+2, j*3+2, i+j+1, 2};
            nodes.push_back(temp1);
            nodes.push_back(temp2);
            nodes.push_back(temp3);
            nodes.push_back(temp4);
        }
    }

    sort(All(nodes),comp);

}

void solve(int testcases){
    int n;
    cin>>n;
    vi a(n,0);
    get_vector(a);

    int i = 0; int j = 0;
    vector<node>ansv;
    int sz = nodes.size();
    map<int,int>hsh;
    int mx = 0;
    rep(k,0,n){
        // debug(i)
        // debug(j)
        if(a[k]==0){
            assert(i<sz);
            ansv.push_back(nodes[i]);
            mx = max(nodes[i].x, mx);
            mx = max(nodes[i].y,mx);
            hsh[i]=1;
            while(hsh[j]==1)j++;
            
            while(nodes[i].st2!=1 || hsh[i]==1){
                assert(i<sz);
                i++;
            }
        }else{
            assert(j<sz);
            ansv.push_back(nodes[j]);
            mx = max(nodes[j].x, mx);
            mx = max(nodes[j].y,mx);
            hsh[j]=1;
            while(hsh[j]==1)j++;
            while(nodes[i].st2!=1 || hsh[i]==1){
                assert(i<sz);
                i++;
            }
            
            
        }
    }

    debug(ansv[n-1].x)
    debug(ansv[n-1].y)
    debug(ansv[n-2].x)
    debug(ansv[n-2].y)
    debug(mx)
    for(auto el:ansv){
        cout<<el.x<<gp<<el.y<<endl;
    }



}

int32_t main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    // freopen("out.txt", "w", stdout);
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
