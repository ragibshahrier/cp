#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
 
typedef long long ll;
 
#define int long long
 
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
#define pow2(i) (1LL<<i)

// #define DEBG

#define debug(n)
#define debugc(a)
#define debugcc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<'{'<<gp<<el.ff<<','<<el.ss<<gp<<'}'<<gp;}cout<<']'<<endl;
#endif

#define fastcin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'


#define All(a) a.begin(),a.end()
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}


const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;
const ll N = 2e5 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//

long long modInverse(long long A, long long m)
{
    long long m0 = m;
    long long y = 0, x = 1;

    if (m == 1)
        return 0;

    while (A > 1) {
        long long q = A / m;
        long long t = m;

        
        m = A % m, A = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

__int128_t ceili(__int128_t a, __int128_t b){
    if(a*b>=0)return (a/b + (a%b!=0));
    else return (a/b);
}


void preprocessing(){

}

void solve(int testcases){
    int x,y,p,q;
    cin>>x>>y>>p>>q;
    int ans;
    if(p==q){
        if(x==y)ans = 0;
        else ans = -1;
    }else if(p==0){
        if(x==0)ans = 0;
        else ans = -1;
    }else if(x/(__gcd(x,y)) == p && y/(__gcd(x,y))==q){
        ans = 0;
    }else{
        __int128_t a,b,pp,qq,xx,yy;
        xx = x;
        yy = y;
        pp = p;
        qq = q;
        debug("else")
        if(p==1){
        debug("else1")
            a = max({(__int128_t)0, ceili((yy-qq*xx),(qq-1)), ceili(yy-xx*qq,qq)});
            // a = max({0LL, (ll)ceil((y-1.0*q*x)/(q-1)), (ll)ceil(y/q-x)});
            b = qq*(a+xx)-yy;
        }else{
        debug("else2")
            __int128_t xxx = pp - (xx%pp);
            xxx%=pp;
            a = max({(__int128_t)0, ceili((pp*yy-qq*xx),(qq-pp)), ceili((yy*pp-xx*qq),qq)});
            // a = max({0LL, (ll)ceil(1.0*((1.0*p*y)/(q-p)-(1.0*q*x)/(q-p))), (ll)ceil(1.0*(1.0*y*p)/q-x)});
            debug((p*y))
            debug(a)
            debug(xxx)
            if(a%pp != xxx){
                a += (((xxx - (a%pp))%pp)+pp)%pp;
            }
            debug(a)
            b = (a+xx)/pp * qq - yy;
        }
        // int invq = modInverse(q,p);
        // int a = (((y*invq)%p - x)%p + p)%p;
        // debug(a)
        // int b = (x*q-p*y+a*q)/p;
        // ans = b;
        ans = b;
        // cout<<a<<endl;
        debug(a)
        debug(b)
        // x = x+a;
        // y = y+b;
        debug(x/__gcd(x,y))
        debug(y/__gcd(x,y))


    }
    cout<<ans<<endl;
    // cout<< (ll)ceili(-7,3)<<endl;
    debug(__gcd(p,q))

}

int32_t main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1)solve(i);
    return 0;
}
