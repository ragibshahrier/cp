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

//#define DEBG

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
const int N = 1e6+7;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vi a(n);
    vi b(m);
    get_vector(a);
    get_vector(b);
    ll ans=0;
    ll cnt = 0;
    map<int,int>mp1;
    map<int,int>mp2;
    rep(i,0,m){
        mp2[b[i]]++;
    }
    rep(i,0,m){
        mp1[a[i]]++;
        if(mp1[a[i]]<=mp2[a[i]]){
            cnt++;
        }
    }
    if(cnt>=k)ans++;
    for(int l=0, r = m;r<n;l++,r++){
        mp1[a[l]]--;
        if(mp1[a[l]]<mp2[a[l]]){
            cnt--;
        }
        mp1[a[r]]++;
        if(mp1[a[r]]<=mp2[a[r]]){
            cnt++;
        }
        if(cnt>=k)ans++;
    }
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
