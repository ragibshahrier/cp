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

//#define DEBG

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
    int n,m;
    cin>>n>>m;
    vi a(n+1);
    vector<pair<pi,int>> ins(m);
    rep(i,0,m){
        cin>>ins[i].ff.ff>>ins[i].ff.ss;
        ins[i].ss = i;

    }
    sort(All(ins));
    vi insa(m),insb(m);
    rep(i,0,m){
        insa[i] = ins[i].ff.ff -1;
        insb[i] = ins[i].ff.ff + ins[i].ff.ss - 1 -1;
    }
    rep(i,0,m){
        a[insa[i]]++;
        a[insb[i]+1]--; 
    }
    rep(i,1,n+1){
        a[i] = a[i-1] + a[i];
    }
    int i = 0;
    int on = 0;
    int start,end;
    int ans = 0;
    vpi ansv;
    while(i<n+1){
        if(on){
            if(a[i]<2){
                on=0;
                end = i-1;
                int ind = lower_bound(All(insa), start) - insa.begin();
                while(insa[ind]<=end){
                    if(insb[ind]<=end){
                        ans++;
                        ansv.push_back(i)
                    }
                    ind++;
                }

            }
        }else{
            if(a[i]>=2){
                on = 1;
                start = i;
            }

        }
    }

}

int32_t main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1)solve(i);
    return 0;
}
