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
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el.ff<<','<<el.ss<<gp;}cout<<']'<<endl;
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
    ll l,r;
    ll l1,r1;
    cin>>l>>r>>l1>>r1;
    set<ll>mp;
    set<ll>mp2;
    for(ll i=l1; i<=r1;i++){
        if(((i-1)>=l) && ((i-1)<=r)){
            // mp[{i-1,i}]=1;
            mp.insert(i-1);
        }
        if(((i+1)>=l) && ((i+1)<=r)){
            // mp[{i,i+1}]=1;
            mp.insert(i);
        }
    }
    for(ll i=l; i<=r;i++){
        if(((i-1)>=l1) && ((i-1)<=r1)){
            // mp[{i-1,i}]=1;
            mp2.insert(i-1);
        }
        if(((i+1)>=l1) && ((i+1)<=r1)){
            // mp[{i,i+1}]=1;
            mp2.insert(i);
        }
    }

    // debugc(mp)
    cout<<max(mp.size(),mp2.size())<<endl;

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
