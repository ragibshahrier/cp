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




void preprocessing(){

}

long long power(long long a, long long b) {
    long long result = 1;
    while(b) {
        if (b & 1) 
        result = (result * a)%M;
        a = a * a;
        a%=M;
        b >>= 1;
    }
    result%=M;
    return result;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vll a(n);
    get_vector(a);
    vll acc(n+1);
    ll ss = 0;
    rep(i,1,n+1){
        acc[i]=a[i-1]+acc[i-1];
        ss+=a[i-1];
    }
    ll mini = 0;
    ll maxsum = 0;
    for(int i = 0, j=0; i<n+1 && j<n+1; ){
        if(acc[j]<mini){
            mini = acc[j];
            i = j;
        }
        maxsum = max(maxsum, acc[j]-acc[i]);
        j++;
    }
    debug(power(2,7));
    debug(maxsum)
    ll ans = ss%M+(maxsum%M * (power(2,k)-1))%M;
    
    ans%=M;
    ans+=M;
    ans%=M;
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
