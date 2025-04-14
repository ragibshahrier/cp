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

#define DEBG

#define debug(n)
#define debugc(a)
#define debugcc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<" ";}cout<<']'<<endl;
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
const ll N = 1e6 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//


vi primes;
vi hsh(N);
vi multiples(N);

void preprocessing(){
    vi erat(N);
    rep(i,2,N){
        if(erat[i]==0){
            primes.push_back(i);
        }else continue;

        multiples[i]+=hsh[i];
        for(int j = i+i; j<N; j+=i){
            erat[j] = 1;
            multiples[i]+=hsh[j];
        }

    }
}

void solve(int testcases){
    int n,x,y;
    cin>>n>>x>>y;

    vi a(n,13709);
    
    get_vector(a);
    // debugc(a)
    // sort(All(a));
    random_shuffle(All(a));
    vpi pr;
    
    rep(i,0,n){
        hsh[a[i]]++;
    }


    rep(i,0,N){
        if(hsh[i]){
            pr.push_back({i,hsh[i]});
        }
    }
    int sz = pr.size();
    preprocessing();
    
    int ans = INF;
    // debug(primes.size())
    // debugc(primes)

    for(auto el:primes){
        int tempans = 0;
        if(x<=y){
            tempans = x*(n-multiples[el]);
        }else{
            rep(i,0,sz){
                int num = pr[i].ff;
                int cnt = pr[i].ss;
                int xx = x;

                int yy = ((el-num%el)%el)*y;
                tempans += (min(xx,yy))*cnt;
                if(tempans>=ans){
                    break;
                }
            }

        }
        ans = min(ans,tempans);
    }

    cout<<ans<<endl;

}

int32_t main(){
    fastcin();
    srand(time(0));

    int t=1;
    // cin>>t;
    // preprocessing();
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
