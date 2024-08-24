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

void solve(){
    int n;
    cin>>n;
    multiset<ll>sa;
    rep(i,0,n){
        int x;
        cin>>x;
        while((x&1)==0){
            x>>=1;
        }
        sa.insert(x);
    }
    debugc(sa)
    auto it = sa.end();it--;
    ll maxi = *it;
    vll b(n);
    get_vector(b);
    debug(n)
    rep(i,0,n){
        ll nn= b[i];
        bool d = 0;
        while(nn>0){
            auto itt = sa.find(nn);
            if(itt!=sa.end()){
                debug(*itt)
                d=1;
                sa.erase(itt);
                break;
            }
            nn>>=1;
        }
        debug(nn)
            debug(d)
        if(d)continue;
        // nn = b[i];
        // while(nn<=maxi){
        //     auto itt = sa.find(nn);
        //     if(itt!=sa.end()){
        //         d=1;
        //         sa.erase(itt);
        //         break;
        //     }
        //     nn*=2;
        // }
        // if(d)continue;
        cout<<"NO"<<endl;return;
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
