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
#define pow2(i) (1LL<<i)

#define DEBG

#define debug(n)
#define debugc(a)
#define debugcc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<'{'<<gp<<el.ff<<','<<el.ff<<gp<<'}'<<gp;}cout<<']'<<endl;
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


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}


void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    if(b>a){
        int temp=b;
        b=a;
        a=temp;
    }
    vi aa(n);
    get_vector(aa);
    rep(i,0,n){
        aa[i]%=b;
    }
    sort(All(aa));
    ll gab = __gcd(a,b);
    ll ans = 0;
    debugc(aa)
    debug(gab)
    vll aaa;
    aaa.push_back(0);
    rep(i,0,n-1){
        if(2*((aa[i+1]-aa[i])%gab)<=gab){
            // ans+=(aa[i+1]-aa[i])%gab;
            aaa.push_back(aaa.back()+(aa[i+1]-aa[i])%gab);
        }else{
            aaa.push_back(aaa.back()+((aa[i+1]-aa[i])%gab)-gab);
            // ans+=((aa[i+1]-aa[i])%gab)-gab;
        }
    }
    // cout<<abs(ans)<<endl;
    ll mn = *min_element(All(aaa));
    ll mx = *max_element(All(aaa));
    // cout<<mx-mn<<endl;

    multiset<ll>ms(All(aa));
    rep(i,0,n-1){
        debugc(ms)
        auto it = ms.end();it--;
        ll curr  = *it-*ms.begin();
        debug(aa[i])
        ms.erase(ms.find(aa[i]));
        debugc(ms)
        ms.insert((aa[i+1]-(aa[i+1]-aa[i])%gab));
        it = ms.end();it--;
        ll curr1  = *it-*ms.begin();
        debugc(ms)
        ms.erase(ms.find(aa[i+1]-(aa[i+1]-aa[i])%gab));

        ms.insert((aa[i+1]+gab-(aa[i+1]-aa[i])%gab));
        it = ms.end();it--;
        ll curr2  = *it-*ms.begin();
        debugc(ms)
        ms.erase(ms.find((aa[i+1]+gab-(aa[i+1]-aa[i])%gab)));

        if(curr1>curr2 && curr>curr2){
            ms.insert((aa[i+1]+gab-(aa[i+1]-aa[i])%gab));
        }
        else if(curr2>curr1 && curr>curr1){
            ms.insert((aa[i+1]-(aa[i+1]-aa[i])%gab));
        }
        debugc(ms)

    }
    auto it = ms.end();it--;
        ll curr  = *it-*ms.begin();
        cout<<curr<<endl;



}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
