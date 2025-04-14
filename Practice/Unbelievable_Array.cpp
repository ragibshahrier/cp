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
const ll N = 1e5 + 7;
// const ll N = 10;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//


int leaders[N];
vi par;
vi repp;
vi sz;

void preprocessing(){

}

int findset(int v){
    if(v==par[v]){
        return v;
    }

    return par[v] = findset(par[v]);
}

void unite(int a, int b, int c){
    if(findset(a)==findset(b)){
        repp[findset(a)] = c;
        return;
    }

    int x = findset(a);
    int y = findset(b);

    if(sz[x]<sz[y]){
        swap(x,y);
    }

    par[y] = x;
    sz[x] += sz[y];
    repp[x] = c;
    leaders[c] = x;
}

void solve(int testcases){
    int n,q;
    cin>>n>>q;

    vi a(n);
    get_vector(a);

    memset(leaders, -1, sizeof(leaders));

    par.resize(n);
    repp.resize(n);
    sz.resize(n);



    
    rep(i,0,n){
        if(leaders[a[i]]==-1){
            leaders[a[i]] = i;
            repp[i] = a[i];
        }
    }


    rep(i,0,n){
        par[i] = leaders[a[i]];
        sz[par[i]]++;
    }

    cout<<"Case "<<testcases<<": "<<endl;

    while(q--){
        int x,y,z;
        cin>>x>>y;
        if(x==1){
            cin>>z;
            if(leaders[y]==-1 || y==z)continue;
            if(leaders[z]==-1){
                repp[leaders[y]] = z;
                leaders[z] = leaders[y];
                leaders[y] = -1;
                continue;
            }

            unite(leaders[y],leaders[z],z);
            leaders[y]  = -1;
        }else{
            y--;
            int l = findset(y);
            cout<<repp[l]<<endl;
        }
    }

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
