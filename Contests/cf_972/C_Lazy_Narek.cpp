#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
 
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
const ll N = 1e3+7;


//==============================CODE STARTS HERE==============================//

vector<string>vs;
vector<char> arr = {'n', 'a', 'r', 'e', 'k'};
int n,m;

void preprocessing(){

}

vector<vector<pll>> dpp(N, vector<pll>(6));

pll b = {-1,-1};

pll func(int lvl, int start){
    debug(lvl)
    debug(start)
    if(lvl==n){
        return {0,0};
    }
    if(dpp[lvl][start]!=b){
        return dpp[lvl][start];
    }
    pll ans = {0,0};
    pll a1 = func(lvl+1, start);
    int  i = start;
    int j = 0;
    ll pointn = 0;
    ll pointc = 0;
    for(auto ch:vs[lvl]){
        if(ch==arr[i]){
            if(i==4){
                pointn+=5;
                i=0;
                j=0;
            }
            else{
                i++;
                j++;
            }
        }else{
            pointc++;
        }
    }
    debug(i)
    pll a2  = func(lvl+1, i);
    a2.ss += vs[lvl].length();
    a2.ff += pointn;
    debug(lvl)
    debug(start)
    debug(a2.ff)
    debug(a2.ss)
    // debug(a1.ff*2-a1.ss)
    // debug(a2.ff*2-a2.ss)

    if(a1.ff*2-a1.ss > ans.ff*2-ans.ss){
        ans = a1;
        debug(ans.ff*2-ans.ss)

    }
    if((a2.ff*2-a2.ss) > (ans.ff*2-ans.ss)){
        debug(1)
        ans = a2;
    }
    debug(ans.ff)
    debug(ans.ss)
    return dpp[lvl][start] = ans;

}

void solve(){
    vs.clear();
    cin>>n>>m;
    vs.resize(n);
    rep(i,0,n){
        rep(j,0,6){
            dpp[i][j] = {-1,-1};
        }
        string s;
        cin>>s;
        int j = 0;
        for(auto ch:s){
            
            j++;
            if(find(All(arr),ch)!=arr.end()){
                vs[i].push_back(ch);
            }
        }
    }

    pll ansp = func(0,0);
    debug(ansp.ff)
    debug(ansp.ss)
    ll ans = 2*ansp.ff- ansp.ss; 
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
