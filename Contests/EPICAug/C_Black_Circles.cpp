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
ll dis(pll f, pll s){
    return ((f.ff-s.ff)*(f.ff-s.ff)+(f.ss-s.ss)*(f.ss-s.ss));
}

void solve(){
    int n;
    cin>>n;
    vector<pll> c(n);
    rep(i,0,n){
        cin>>c[i].ff>>c[i].ss;

    }
    pll st,en;
    cin>>st.ff>>st.ss>>en.ff>>en.ss;
    ll dis1  = dis(st,en);
    rep(i,0,n){
        debug(dis1)
        debug(dis(c[i],en))
        if(dis1-dis(c[i],en)>=0){
            cout<<"NO"<<endl;return;
        }
    }
    cout<<"YES"<<endl;
    

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
