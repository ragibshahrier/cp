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


//==============================CODE STARTS HERE==============================//


int n;

vector<vector<char>>mat(1000+3, vector<char>(1000+3,'*'));

void preprocessing(){

}

vvi dpp(1007, vi(1007,-1));

ll func(int a, int b){
    
    if(dpp[a][b]!=-1)return dpp[a][b];
    if(mat[a][b]=='*')return dpp[a][b]=0;

    if(a==n-1 && b==n-1){
        return dpp[a][b]=1;
    }
    ll ans = 0;
    
    ans+=func(a+1,b);
    ans%=M;
    
    ans+=func(a,b+1);
    ans%=M;

    return dpp[a][b] = ans;


}

void solve(){
    cin>>n;
    rep(i,0,n){
        rep(j,0,n){
            cin>>mat[i][j];
        }
    }
    cout<<func(0,0)<<endl;
    // rep(i,0,n+1){
    //     rep(j,0,n+1){
    //         cout<<dpp[i][j]<<gp;
    //     }
    //     cout<<endl;
    // }


}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
