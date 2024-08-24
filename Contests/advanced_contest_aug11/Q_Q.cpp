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

ll logi(ll n, ll a){
    ll ans = 0;
    while(n>=a){
        n/=a;
        ans++;
    }
    return ans;
}

long long power(long long a, long long b) {
    long long result = 1;
    while(b) {
        if (b & 1) 
        result = result * a;
        a = a * a;
        b >>= 1;
    }
    return result;
}

ll modInverse(ll A)
{
    ll MM =M;
    ll m0 = M;
    ll y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1) {
        // q is quotient
        ll q = A / MM;
        ll t = MM;

        // m is remainder now, process same as
        // Euclid's algo
        MM = A % MM, A = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

void solve(){
    ll nn;
    cin>>nn;

    ll ans = 0;
    ll sq = sqrt(nn);
    for(ll i = 2; i<=sq; i++){
        ll xx = logi(nn,i);
        ll n = xx-1;
        ll tempans = 0;
        ll p = power(i,xx);
        ll modii = modInverse(i);
        ll modii1 = modInverse(i-1);
        // tempans += ((n* i* p/i) - (i*(p/i-1))/(i-1))/(i-1);
        // tempans += ((n* p) - (p - i)/(i-1));
        tempans += ((((n* ((p)%M))%M)%M - (((p - i))%M) *modii1)%M)%M;
        // if(tempans<0)debug(tempans)
        // debug(tempans)
        tempans+=((nn - p  + 1)%M * (xx)%M)%M;
        // if(tempans<0)debug(tempans)
        // debug(tempans)
        tempans%=M;
       
        ans+=(i*tempans)%M;
        ans+=M;
        ans%=M;
    }
    // cout<<ans<<endl;
    // debug(modInverse(2))
    ll modi2 = modInverse(2);
    ll modi6 = modInverse(6);
    sq++;
    ans+=((((((sq+nn)%M)*((nn-sq+1)%M))%M)*modi2)%M *((nn+1)%M))%M -( ( ( (  ((((nn%M)*(nn%M+1))%M))%M *((2*nn+1)%M)  )%M )%M)*modi6)%M + ((((((sq-1) *sq)%M *(2*sq-1))%M))%M * modi6)%M;
    ans%=M;
    ans+=M;
    ans%=M;
    cout<<ans<<endl;


}


void solve2(){
    ll nn;
    cin>>nn;

    ll ans = 0;
    ll sq = sqrt(nn);
    for(ll i = 2; i<=sq; i++){
        ll xx = logi(nn,i);
        ll n = xx-1;
        ll tempans = 0;
        ll p = power(i,xx);
        tempans += ((n*i* p/i) - (i*(p/i - 1)/(i-1)));
        debug(tempans)
        tempans+=((nn - p  + 1)%M * xx)%M;
        debug(tempans)
        tempans%=M;
        ans+=(i*tempans)%M;
    }
    // cout<<ans<<endl;
    debug(modInverse(2))
    ll modi2 = modInverse(2);
    ll modi6 = modInverse(6);
    sq++;
    ans+=((((sq+nn)%M)*((nn-sq+1)%M)*modi2)%M *((nn+1)%M))%M -( ( ( (  ((((nn%M)*(nn%M+1))%M))%M *((2*nn+1)%M)  )%M )%M)*modi6)%M + (((((sq-1) *sq)%M *(2*sq-1))%M) * modi6)%M;
    ans%=M;
    ans+=M;
    ans%=M;
    cout<<ans<<endl;
}


int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
