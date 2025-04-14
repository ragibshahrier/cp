#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
 
typedef long long ll;
 
#define int long long
 
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

void solve(int testcases){
    int n,m,v;
    cin>>n>>m>>v;
    vi a(n);
    get_vector(a);

    ll sum = 0;
    rep(i,0,n){
        sum+= a[i];
    }

    vi pref(n+1);
    rep(i,1,n+1){
        pref[i] = pref[i-1]+a[i-1];
    }
    int i = n-1;
    vector<list<int>> grid;
    int fed = 0;
    ll scre = 0;
    ll ans = 0;


    while(i>=0){
        list<int> temp;
        int s = 0;
        while(s<v && i>=0){
            s+=a[i];
            scre+=a[i];
            temp.push_back(i);
            i--;
        }
        if(s>=v){
            fed++;
            grid.push_back(temp);
        }
        if(fed>=m)break;
    }

    debug(grid.size())
    debug(fed)
    if(fed<m){
        cout<<-1<<endl;
        return;
    }
    debug(sum)
    // if(scre==sum){
    //     cout<<0<<endl;
    //     return;
    // }
    list<int>tempp;
    while(i>=0){
        tempp.push_back(i);
        ans+=a[i];
        i--;
    }
    grid.push_back(tempp);
    while(grid.size()>1){
        debug(1)
        // rep(i,0,grid.size()){
        //     debugc(grid[i]);
        // }
        debug(ans)
        grid[grid.size()-2].splice(grid[grid.size()-2].end(), grid[grid.size()-1]);
        grid.pop_back();
        list<int>& li = grid[grid.size()-1];

        ll sumi = pref[li.front()+1]-pref[li.back()];

        ll cfed=0;
        while(cfed<v){
            cfed+=a[li.back()];
            li.pop_back();
        }
        ans = max(ans,sumi-cfed);



    }

    debug(1)
    // cout<<grid.size()<<endl;
    // cout<<grid.size()<<endl;
    // rep(i,0,grid.size()){
    //     debugc(grid[i]);
    // }
    cout<<ans<<endl;
    




}

int32_t main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1)solve(i);
    return 0;
}
