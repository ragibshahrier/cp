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
const ll N = 1e5 + 50;


//==============================CODE STARTS HERE==============================//

int n;
vi a;
vll acc;


void preprocessing(){

}

ll dpp[N];

ll func(int n){
    if(n<=0){
        return 0;
    }
    if(dpp[n]!=-1)return dpp[n];
    ll ans = 0;
    int x = (a[n]+a[n-1])%10;
    if(a[n]+a[n-1]>=10){
        ans++;
    }
    ll y = func(n-2);
    if(x+acc[n-1]%10>=10){
        ans++;
    }
    ans+=y;
    return dpp[n] = ans;

}

void solve(){
    memset(dpp, -1, sizeof(dpp));
    cin>> n;
    a.resize(n);
    acc.resize(n+1);
    get_vector(a);
    rep(i,1,n+1){
        acc[i]=acc[i-1]+a[i-1];
    }
    int m;cin>>m;
    while(m--){
        int x,y;cin>>x>>y;
        if(x==y){
            cout<<0<<endl;continue;
        }
        x--;y--;
        ll ans = func(y)-func(x-1);
        if((acc[y+1]-acc[x])%10 + acc[x]%10 >= 10)ans--;
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
