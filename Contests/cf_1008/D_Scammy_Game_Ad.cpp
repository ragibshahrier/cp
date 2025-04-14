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
#define bitcnt(x) ((sizeof(x) <= sizeof(int)) ? (32 - __builtin_clz(x)) : (64 - __builtin_clzll(x)))

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

struct ops{
    char type;
    int num;
};


int incf(int op, ops opr){
    int ans;
    if(opr.type=='x'){
        ans = op*(opr.num-1);
    }else{
        ans = opr.num;
    }
    return ans;
}

void solve(int testcases){
    int n;
    cin>>n;
    vector<pair<ops,ops>>vops(n);
    rep(i,0,n){
        char x,y;
        int a,b;
        cin>>x>>a>>y>>b;
        vops[i].ff.type = x;
        vops[i].ss.type = y;
        vops[i].ff.num = a;
        vops[i].ss.num = b;
        
    }
    
    // debug(1)
    pi anss1 = {1,1};
    pi anss2 = {1,1};

    int ans  = 0;

    rep(i,0,n){
        int inc1 = incf(anss1.ff, vops[i].ff)+incf(anss1.ss, vops[i].ss);
        int inc2 = incf(anss2.ff, vops[i].ff)+incf(anss2.ss, vops[i].ss);
        int inc = max(inc1,inc2);
        
        pi temp1 = {anss1.ff+inc1, anss1.ss};
        pi temp2 = {anss1.ff, anss1.ss+inc1};
        pi temp3 = {anss2.ff, anss2.ss+inc2};
        pi temp4 = {anss2.ff+inc2, anss2.ss};

        if(temp1.ff<=temp4.ff){
            anss1 = temp4;
        }else{
            anss1 = temp1;
        }

        if(temp2.ss>=temp3.ss){
            anss2 = temp2;
        }else{
            anss2 = temp3;
        }




        debug(anss1.ff)
        debug(anss1.ss)
        debug(anss2.ff)
        debug(anss2.ss)

        ans = max(ans, anss1.ff+anss1.ss);
        ans = max(ans, anss2.ff+anss2.ss);
    }


    cout<<ans<<endl;


}

int32_t main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
