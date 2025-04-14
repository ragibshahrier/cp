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

void solve(int testcases){
    int n;
    cin>>n;
    vi a(n);

    get_vector(a);

    vpi pv;

    if(a[0]==1){
        pv.push_back({1,1});
    }else{
        pv.push_back({2,1});
    }

    rep(i,1,n){
        if(a[i]==pv.back().ff){
            pv[pv.size()-1].ss++;
        }else{
            pv.push_back({a[i],1});
        }
    }

    int sz = pv.size();
    ll ans = 0;

    debugcc(pv)

    vpi sube(sz+1);
    vpi subs(sz+1);
    sube[0] = {0,0};
    rep(i,1,sz){
        if(pv[i-1].ff==1){
            sube[i] = sube[i-1];
            sube[i].ff+=pv[i-1].ss;
        }else{
            sube[i] = sube[i-1];
            sube[i].ss = max(sube[i-1].ff,sube[i-1].ss);
            sube[i].ss+=pv[i-1].ss;
        }
    }

    subs[sz] = {0,0};
    for(int i = sz-1; i>=0; i--){

        if(pv[i].ff==2){
            subs[i] = subs[i+1];
            subs[i].ss+=pv[i].ss;
        }else{
            subs[i] = subs[i+1];
            subs[i].ff = max(subs[i+1].ff,subs[i+1].ss);
            subs[i].ff+=pv[i].ss;
        }
    }

    debugcc(sube);
    debugcc(subs);

    ans = pv[0].ss;
    
    rep(i,0,sz){
        int two = 0;
        int one = 0;
        int onn = 0;
        rep(j,i,sz){
            if(pv[j].ff==2){
                two+=pv[j].ss;
            }else{
                one = max(two,one)+pv[j].ss;
                onn +=pv[j].ss;
            }
            if(pv[i].ff==2 && pv[j].ff==2){
                ans = max(ans, max(sube[i].ss,sube[i].ff)+subs[j+1].ss+two);
            }else if(pv[i].ff==1 && pv[j].ff==1){
                ans = max(ans, sube[i].ff+max(subs[j+1].ff,subs[j+1].ss)+onn);
            }else if(pv[i].ff==2 && pv[j].ff==1){
                ans = max(ans, sube[i].ff+subs[j+1].ss+one);
            }
            // cout<<i<<" "<<j<<endl;
            debug(one)
            debug(onn)
            debug(two)
            debug(ans)
        }
    }

    cout<<ans<<endl;


}

int32_t main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
