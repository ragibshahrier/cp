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
const ll N = 1e6 + 7;


//==============================CODE STARTS HERE==============================//

vector<vll> dpp(N+3, vll(2,-1));

ll func(int n, int i){
    debug(n)
    if(n==1){
        if(i==0)return dpp[n][0]=1;
        else return dpp[n][1]=1;
    }
    if(dpp[n][i]!=-1)return dpp[n][i];
    ll ans = 0;
    if(i==0){
         ans += func(n-1,0)*4;
         ans%=M;
         ans += func(n-1,1);
         ans%=M;
         return dpp[n][i]=ans;
    }
    if(i==1){
         ans += func(n-1,0);
         ans%=M;
         ans += func(n-1,1)*2;
         ans%=M;
         return dpp[n][i]=ans;
    }


}

void preprocessing(){
    dpp[1][0]=1;
    dpp[1][1]=1;
    rep(i,2,N){
        dpp[i][0]=((dpp[i-1][0]*4)%M + dpp[i-1][1])%M;
        dpp[i][1]=(dpp[i-1][0] + (dpp[i-1][1]*2)%M)%M;
    }
}

void solve(){
    int n;
    cin>>n;
    cout<<(dpp[n][0]+dpp[n][1])%M<<endl;


}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
