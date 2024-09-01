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
const ll N = 2e5 + 7;


//==============================CODE STARTS HERE==============================//


vi lpf(N);

void preprocessing(){
    rep(i,2, N){
        if(lpf[i]==0){
            for(int j = i; j<N; j+=i){
                lpf[j]=i;
            }

        }
    }
}

void solve(){
    int n;cin>>n;
    vi a(n);
    get_vector(a);
    ll cntof0 = 0;
    map<set<int>,ll>mp;
    rep(i,0,n){
        if(a[i]==0){cntof0++;continue;}
        set<int>prs;
        while(a[i]!=1){
            auto it = prs.find(lpf[a[i]]);
            if(it==prs.end())prs.insert(lpf[a[i]]);
            else prs.erase(it);
            a[i]/=lpf[a[i]];
        }
        mp[prs]++;



    }
    ll ans = 0;
    ans += cntof0*(n-cntof0) + cntof0*(cntof0-1)/2;
    debug(1)
    for(auto el:mp){
        debugc(el.ff);
        debug(el.ss);
        ans += el.ss*(el.ss-1)/2;
    }
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
