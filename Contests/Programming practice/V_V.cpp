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

//#define DEBG

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
const ll N = 1e5 + 7;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(){
    int h,w,t;
    cin>>h>>w>>t;
    vvll mat(h+4, vll(w+4));
    vvll matmin(h+4, vll(w+4));
    ll hsh[N];
    memset(hsh,0,sizeof(hsh));
    rep(i,1,h+1){
        rep(j,1,w+1){
            cin>>matmin[i][j];
            mat[i][j] = inf;
        }
    }
    rep(i,1,h+1){
        rep(j,1,w+1){
            mat[i][j] = max(matmin[i][j], min({mat[i-1][j], mat[i][j-1], mat[i][j]}));
        }
    }
    for(int i=h; i>=1; i--){
        for(int j=w; j>=1; j--){
            mat[i][j] = max(matmin[i][j], min({mat[i+1][j], mat[i][j+1], mat[i][j]}));
        }
    }
    rep(i,1,h+1){
        rep(j,1,w+1){
            mat[i][j] = max(matmin[i][j], min({mat[i-1][j], mat[i][j-1], mat[i][j]}));
        }
    }
    for(int i=h; i>=1; i--){
        for(int j=w; j>=1; j--){
            mat[i][j] = max(matmin[i][j], min({mat[i+1][j], mat[i][j+1], mat[i][j]}));
        }
    }
    rep(i,1,h+1){
        rep(j,1,w+1){
            cout<<mat[i][j]<<gp;
        }
        cout<<endl;
    }
    rep(i,1,h+1){
        rep(j,1,w+1){
            ++hsh[mat[i][j]];
        }
        // cout<<endl;
    }
    ll ans = h*w;
    rep(i,1,t+1){
        ans-=hsh[i];
        cout<<ans<<endl;
    }
   
   
    
    

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
