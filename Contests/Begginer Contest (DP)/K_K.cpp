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
    int n;cin>>n;
    vi a(n+1);
    rep(i,0,n)cin>>a[i];
    vector<ll> ap(n+1);
    pair<ll,int> maxi = {0,0};
    map<ll,pll>mp;
    rep(i,0,n){
        
        if(mp.find(a[i]-1)==mp.end()){
            mp[a[i]]= {1,i};
            ap[i]=-1;

        }else{
            mp[a[i]]={mp[a[i]-1].ff+1, i};
            ap[i]=mp[a[i]-1].ss;
        }
        if(mp[a[i]].ff>maxi.ff){
            maxi={mp[a[i]].ff, i};
        }
    }
    cout<<maxi.ff<<endl;
    int x = maxi.ss;
    vi ans;
    int i=0;
    
    while(x!=-1){
        ans.push_back(x+1);
        x = ap[x];
        i++;

    }
    reverse(All(ans));
    put_vector(ans);



}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
