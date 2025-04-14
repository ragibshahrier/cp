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

pi rev(pi x){
    pi y ;
    y.ff = x.ss;
    y.ss = x.ff;
    return y;
}

void solve(int testcases){
    int n;
    cin>>n;

    vpi a(n);
    vpi b(n);
    rep(i,0,n){
        cin>>a[i].ff>>a[i].ss;
        b[i].ff = a[i].ss;
        b[i].ss = a[i].ff;

    }

    multiset<pi>m1(All(b));
    multiset<pi>m2(All(a));
    multiset<pi>m3;
    int curlok = 0;
    int ans = 0;
    while(!m1.empty()){
        pi x = *m1.begin();
        ans += x.ff;
        m2.erase(m2.find(rev(x)));
        m1.erase(m1.find(x));
        pi y = rev(x);
        y.ff *= -1;
        m3.insert(y);
        curlok++;
        debugcc(m1);
        debugcc(m2);
        while(!m2.empty() && m2.begin()->ff<=curlok){
            m1.erase(m1.find(rev(*m2.begin())));
            m2.erase(m2.begin());
            curlok++;
            debugcc(m1);
            debugcc(m2);
            debug(curlok)
        }
        debug(ans)

        int tem = 0;
        auto it = m3.begin();
        debugcc(m3);
        debugcc(m1);
        debugcc(m2);

        while(it!=m3.end()){
            auto itt = it;
            it++;

            if(tem>=-(itt->ff)){
                ans-=itt->ss;
                m3.erase(itt);
                
            }
            tem++;

        }
        debug(ans)
        




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
