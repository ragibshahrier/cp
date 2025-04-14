#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
#define int long long
 
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

// #define DEBG

#define debug(n)
#define debugc(a)
#define debugcc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<'{'<<gp<<el.ff<<','<<el.ss<<gp<<'}'<<gp;}cout<<']'<<endl;
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
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(){
    int n,k;
    cin>>n>>k;
    vi a(n);
    
    get_vector(a);
    
    sort(All(a));
    vvi aa;
    vi temp;
    // temp.push_back(a[0]);
    map<int,int>mp;
    rep(i,0,n){
        mp[a[i]]++;
    }
    // rep(i,1,n){
    //     if(a[i]-a[i-1]<=1){
    //         if(a[i]!=a[i-1])temp.push_back(a[i]);
            
    //     }else{
    //         aa.push_back(temp);
    //         temp.clear();
    //         temp.push_back(a[i]);
    //     }
    // }
    // aa.push_back(temp);
    // temp.clear();

    for(auto el:mp){
        if(temp.size()==0){
            temp.push_back(el.ff);
        }
        else if(el.ff - temp.back() == 1){
            temp.push_back(el.ff);

        }else{
            aa.push_back(temp);
            temp.clear();
            temp.push_back(el.ff);
        }
    }
    aa.push_back(temp);
    temp.clear();


    ll ans = 0;
    for(auto& elv:aa){
        debugc(elv)
        int sz = elv.size();
        ll tempans = 0;
        int i = 0;
        for(; i<k && i<sz; i++){
            tempans+=mp[elv[i]];
        }
        debug(i)
        for(;i<sz;i++){
            debug(tempans)
            ll tt = tempans;
            debug(elv[i-k])
            debug(elv[i])
            debug(mp[elv[i-k]])
            debug(mp[elv[i]])
            tempans = max(tempans, tt+mp[elv[i]]-mp[elv[i-k]]);
        }
        debug(tempans)
        ans = max(ans,tempans);
    }
    cout<<ans<<endl;



}

int32_t main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
