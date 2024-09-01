#include<bits/stdc++.h>
using namespace std;
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

// #define DEBG

#define debug(n)
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#endif

#define fastcin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'


#define All(a) a.begin(),a.end()
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}


const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;


//==============================CODE STARTS HERE==============================//

vvll C(100, vll(100));


void preprocessing(){
    C[0][0]=1;
    rep(i,1,100){
        C[i][0]=1;
        C[i][i]=1;
        rep(j,1,i){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
}   



void solve(){
    int n,m;
    cin>>n>>m;
    vi rosum(n);
    vi colsum(m);

    rep(i,0,n){
        rep(j,0,m){
            int x;
            cin>>x;
            rosum[i]+=x;
            colsum[j]+=x;
        }
    }
    debugc(rosum);
    debugc(colsum);
    ll ans = 0;
    rep(i,0,n){
        rep(j,1,rosum[i]+1){
            debug(rosum[i])
            debug(j)
            ans+=C[rosum[i]][j];
            debug(ans)
        }
        rep(j,1,m-rosum[i]+1){
            debug(m-rosum[i])
            debug(j)
            ans+=C[m-rosum[i]][j];
            debug(ans)
        }
    }
    rep(i,0,m){
        rep(j,2,colsum[i]+1){
            ans+=C[colsum[i]][j];
        }
        rep(j,2,n-colsum[i]+1){
            ans+=C[n-colsum[i]][j];
        }
    }
    cout<<ans;

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
