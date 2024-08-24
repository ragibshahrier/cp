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

#define DEBG

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
const ll N = (1e7 + 7) * 3 /2;


//==============================CODE STARTS HERE==============================//


vll primes;
char erat[N];

void preprocessing(){
    memset(erat, 0, sizeof(erat));
    primes.push_back(1);
    primes.push_back(1);
    rep(i,2,N){
        if(erat[i]==0){
            primes.push_back(i);
            for(int j=i+i; j<N; j+=i){
                erat[j]=1;
            }
        }
    }
}

void solve(){
    ll n;
    cin>>n;
    ll sq=ceil(sqrt(n)*2/3);
    // sq*=2;
    // sq=(sq)/3 + (sq%3!=0) ;
    // debug(primes.size())
    debug(primes.back())
    
    // cout<<sq<<endl;
    vll ans;
    for(int i=1; primes[i]*primes[i-1]<=n; i++){
        ans.push_back(primes[i]*primes[i-1]);
    }
    cout<<ans.size()<<endl;
    put_vector(ans);




}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
