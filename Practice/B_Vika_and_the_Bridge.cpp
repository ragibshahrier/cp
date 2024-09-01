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


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(){
    int n,k;
    cin>>n>>k;
    vi a(n);
    get_vector(a);
    
    
    vector<multiset<ll>> stcol(k+1);
    vi prevcol(k+1,-1);
    rep(i,0,n){
        stcol[a[i]].insert(-(i-prevcol[a[i]]-1))++;
        prevcol[a[i]]=i;
    }
    rep(i,1,k+1){
        stcol[i].insert(-(n-prevcol[i]-1));
    }
    ll ans = inf;
    rep(i,1,k+1){
        auto& el= stcol[i];
        debugc(el)
        int x = -*el.begin();
        el.erase(el.begin());
        el.insert(-x/2);
        ans = min(ans,-*el.begin());


        // if(el.begin()->ss==1)ans = min(ans,-el.begin()->ff-1);
        // else ans = min(ans,-el.begin()->ff);
    }
    vpi aa = {{1,2},{2,3},{3,4}};
    debugcc(aa)
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
