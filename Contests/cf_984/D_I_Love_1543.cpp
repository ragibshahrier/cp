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
const ll N = 1e3+50;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

vvll grid(N,vll(N));

int converter(int i, int n, int m, pi ref, int check){
    i = i%(2*(n+m-2));
    pi x;
    if(i<m-1){
        x =  make_pair(ref.ff+0,ref.ss+i);
    }
    else if(i<n+m-2){
        x =  make_pair(ref.ff+i-m+1, ref.ss+m-1); 
    }
    else if(i<n+m+m-3){
        x =  make_pair(ref.ff+n-1, ref.ss+(m-1) + n+m-2-i);
    }
    else{
        x =  make_pair(ref.ff+ (n-1) + (n+m+m-3)-i, ref.ss+ 0);
    }
    debug(i)
    debug(n)
    debug(m)
    debug(ref.ff)
    debug(ref.ss)
    debug(x.ff)
    debug(x.ss)
    debug(" ")
    if(grid[x.ff][x.ss]==check)return 1;
    return 0;
}

void solve(){
    int n,m;
    cin>>n>>m;
    
    rep(i,0,n){
        string s;
        cin>>s;
        rep(j,0,m){ 
            
            grid[i][j] = s[j]-'0';
        }
    }
    int nn = n;
    int mm = m;
    pi ref = {0,0};
    ll ans = 0;
    while(nn>0 && mm>0){
        rep(i,0,2*(nn+mm-2)){
            if(converter(i,nn,mm,ref,1) && converter(i+1,nn,mm,ref,5) && converter(i+2,nn,mm,ref,4) && converter(i+3,nn,mm,ref,3)){
                ans++;
            }
        }
        nn-=2;
        mm-=2;
        ref.ss+=1;
        ref.ff+=1;
    }
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
