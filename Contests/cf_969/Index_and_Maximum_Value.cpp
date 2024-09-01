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
    int n,m;cin>>n>>m;
    vll a(n);
    get_vector(a);
    vll diff(n+1);
    // map<ll,int>mp;
    ll maxi = 0;
    rep(i,0,n){
        // mp[a[i]]++;
        maxi = max(maxi,a[i]);

    }
    
    // put_vector(diff);
    while(m--){
        char s;cin>>s;
        int x,y;cin>>x>>y;

        if(s=='+'){
            if(maxi<=y && maxi>=x){
                // mp[maxi]--;
                
                maxi++;
                // mp[maxi]++;

            }
            
        }
        else{
            if(maxi<=y && maxi>=x){
                // mp[maxi]--;
                
                maxi--;
                // mp[maxi]++;

            }

        }
        cout<<maxi<<gp;
    }
    // debug(1)
    // vll ans(n+1);
    // rep(i,1,n+1){
    //     ans[i]=diff[i]+ans[i-1];
    //     cout<<ans[i]<<gp;
    // }
    cout<<endl;
    



}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
