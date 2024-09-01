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




void preprocessing(){

}

void solve(){
    int n,m;
    cin>>n>>m;
    vi a(n);
    get_vector(a);
    double hsh[n+5];
    memset(hsh,0,sizeof(hsh));
    while(m--){
        int x;double y;
        cin>>x>>y;
        hsh[x]=hsh[x]+(1-hsh[x])*y;
    }
    vector<double> dpp(n+5);
    vll acc(n+1);
    rep(i,1,n+1){
        acc[i]=acc[i-1]+a[i-1];
    }
    rep(i,1,n+1){
        if(acc[i]!=1LL*i*(i+1)/2){
            dpp[i]=0;
        }else if(i==1){
            dpp[i]=1;
        }else if(a[i-1]!=i){
            dpp[i]=hsh[i];
        }else{
            dpp[i]=dpp[i-1]+(1-dpp[i-1])*hsh[i];
        }
    }
    cout<<dpp[n]<<endl;

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
