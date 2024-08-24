#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
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


#define All(a) a.begin(),a.end()
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}


const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;
const ll N = 2e5 + 7;


//==============================CODE STARTS HERE==============================//


vll fact(N);

void preprocessing(){
    fact[0]=1;
    rep(i,1,N){
        fact[i]=(fact[i-1]*i)%M;
    }
}

ll modInverse(ll A, ll M)
{
    ll m0 = M;
    ll y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1) {

        ll q = A / M;
        ll t = M;

        M = A % M, A = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

ll comb(ll n, ll r){
    return (((fact[n]*modInverse(fact[n-r],M))%M)*modInverse(fact[r],M))%M;
}




void solve(){
    ll n, k;
    cin>>n>>k;
    ll ans = comb(n,k)%M;
    ll sum = 0;
    rep(i,0,n){
        int x;
        cin>>x;
        sum+=x;

    }
    debug(sum)
    ll zeros = n-sum;
    if(zeros<=k/2){
        cout<<ans<<endl;
        return;
    }
    debug(ans)
    ll sub=0;
    for(ll i = (k+1)/2; i<=zeros && i<=k; i++){
        debug(k-i)
        if(sum<k-i)continue;
        sub+= ((comb(zeros,i)*comb(sum, k-i))%M);
    }
    sub%=M;
    ans-=sub;
    ans = ((ans+M)%M);
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
