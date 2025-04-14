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
#define checkbit(x,n) (((x)&(1LL<<(n)))!=0LL)
#define setbit(x,n) ((x)=((x)|(1LL<<(n))))
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

void solve(int testcases){
    int x,y;
    cin>>x>>y;
    int xx = x;
    int yy =y;

    // rep(i,0,100){
    //     if((x+i)+(y+i)==((x+i)^(y+i))){
    //         cout<<i<<endl;
    //     }
    // }
    
    if(x==y){
        cout<<-1<<endl;
        return;
    }

    ll ans=0;

    rep(i,0,35){
        // debug((x&(1LL<<i)))
        debug(i)
        debug(checkbit(x,i))
        debug(checkbit(y,i))
        if(checkbit(x,i)==0 && checkbit(y,i)==0){
            continue;
        }else if(checkbit(x,i)!=checkbit(y,i)){
            debug("ho")
            if(checkbit(x,i+1)!=checkbit(y,i+1)){
                continue;
            }else{
                int tempans = 0;
                setbit(tempans,i);
                x+=tempans;
                y+=tempans;
                debug(i)
                debug(tempans)
                ans+=tempans;
            }
        }else if(checkbit(x,i)==1 && checkbit(y,i)==1){
            int tempans = 0;
            setbit(tempans,i);
            debug(i)
            debug(tempans)
            x+=tempans;
            y+=tempans;
            ans+=tempans;

        }
        debug(ans)
    }
    debug(ans)
    if((xx+ans)+(yy+ans)==((xx+ans)^(yy+ans))){
        cout<<ans<<endl;
    }else{
        cout<<-1<<endl;
    }
    //100100100100100100100
    // 10010010010010010100


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
