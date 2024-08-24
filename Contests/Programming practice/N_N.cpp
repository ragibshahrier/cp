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
const ll M = 998244353;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(){
    ll n,m;
    cin>>n>>m;
    bitset<64>nn(n);
    debug(nn)
    bitset<64>mm(m);
    debug(mm)
    ll ans = 0;
    rep(i,0,62){
        if(mm.test(i)){
            ll bb = 1LL<<(i+1);
            ll tempans = 0;
            tempans+= (((n/bb)%M)*((bb/2)%M))%M;
            tempans%=M;
            ll x  = n%bb - bb/2;
            x++;
            if(x>0){
                tempans+=x;
                tempans%=M;
            }
            debug(tempans)
            ans+=tempans;
            ans%=M;
        }
    }
    ans%=M;
    ans+=M;
    ans%=M;
    // cout<<((60LL%M)*((1LL<<(59))%M))%M<<endl;
    // cout<<(((1LL<<(59))%M))<<endl;

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
