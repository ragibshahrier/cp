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
    ll n,k;
    cin>>n>>k;
    vi a(n);
    get_vector(a);
    vpi disfrm10(n);
    ll ans=0;
    rep(i,0,n){
        disfrm10[i].ff=((a[i]+9)/10)*10-a[i];
        disfrm10[i].ss=i;
        ans += (a[i]/10);
    }
    sort(All(disfrm10));
    int kk=k;
    rep(i,0,n){
        if(kk==0 || kk<disfrm10[i].ff){
            kk=0;
            break;
        }
        kk-=disfrm10[i].ff;
        a[disfrm10[i].ss]+=disfrm10[i].ff;
        if(disfrm10[i].ff>0)ans++;

    }
    if(kk==0){
        cout<<ans<<endl;return;
    }
    if((ans+kk/10)>10*n){
        cout<<10*n<<endl;return;
    }
    else{
        ans+=kk/10;
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
