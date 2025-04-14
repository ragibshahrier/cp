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
const ll N = 3e5 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//


int n,k;
vi a;


void preprocessing(){

}

int dpp[N];
int cnt = 0;

// int func(int nd){
//     cnt++;
//     if(nd==n){
//         return 0;
//     }
//     if(nd+k>n){
//         return inf;
//     }
//     if(dpp[nd]!=-1){
//         return dpp[nd];
//     }
//     ll ans = inf;


//     rep(i,nd+k,nd+k+k){
//         if(i+k>n){
//             break;
//         }
//         ans = min(ans, max(a[i-1]-a[nd],func(i)));
//     }
//     ans = min(ans, a[n-1]-a[nd]);

//     return dpp[nd] = ans;
// }

int func(int nd, int mid){
    // debug(nd)
    // debug(mid)
    cnt++;
    if(nd==n){
        return 0;
    }
    // debug(1)
    if(nd+k>n){
        return inf;
    }
    // debug(1)
    // if(dpp[nd]!=-1){
    //     return dpp[nd];
    // // }
    // debug(1)
    debug(nd)
    ll ans = inf;

    int up = n-k;

    int ind = upper_bound(All(a), a[nd]+mid)-a.begin();
    debug(up)
    debug(ind)
    
    int down = nd+k;
    debug(down)

    int indd = min(up, ind);
    indd = max(indd,down);

    debug(indd)

    ans = min(ans, max(a[indd-1]-a[nd],func(indd, mid)));
    // ans = min(ans, max(a[ind-1]-a[nd],func(ind)));


    // rep(i,nd+k,nd+k+k){
    //     if(i+k>n){
    //         break;
    //     }
    // }
    ans = min(ans, a[n-1]-a[nd]);

    return dpp[nd] = ans;
}


void solve(int testcases){
    memset(dpp,-1,sizeof(dpp));
    cin>>n>>k;
    a.resize(n);
    get_vector(a);

    sort(All(a));
    debugc(a)
    

    vi ansv(n);

    int i = 0;
    multiset<int>msfuncs;
    multiset<int>msaij;

    while(i<k-1){
        ansv[i] = inf;
        // msaij.insert(-a[i+1]);
        i++;
    }
    vvi swic(n+2);
    
    vi hasfunc(n+1,1);
    vi hasaij(n+1,0);
    int j = i-k;
    int ii = 2*k-1;
    ii = min(n-1,ii);
    
    while(i<n && i<2*k-1){
        ansv[i] = a[i]-a[0];
        // msaij.insert(-a[i+1]);
        // if(hasfunc[j]==1)msfuncs.insert(ansv[j]);

        // for(auto el:swic[i]){
        //     // if(kk==5)break;
        //     // kk++;
        //     if(msfuncs.find(ansv[el])!=msfuncs.end())msfuncs.erase(msfuncs.find(ansv[el]));
        //     // msfuncs.erase(msfuncs.find(ansv[el]));
        //     hasfunc[el]=0;
        //     if(el<n-1)hasaij[el]=1;
        // }
        // if(hasaij[j]){
        //     msaij.insert(-a[j+1]);
        // }

        if(i<n-1){
            int ind = upper_bound(All(a), ansv[i] + a[i+1]) - a.begin();
            ind = max(ii,ind);
            swic[ind].push_back(i);
        }
        i++;
        j++;
    }
    debug(i)
    debugc(ansv)
    debugc(msaij)
    debugc(msfuncs)
    
    while(i<n){
        debug(i)
        debug(j)
        debugc(a)
        debug(hasfunc[j])
        if(hasfunc[j]==1)msfuncs.insert(ansv[j]);
        debugc(swic[i])
        int kk = 0;

        
        for(auto el:swic[i]){
            // if(kk==5)break;
            // kk++;
            debug(kk)
            if(msfuncs.find(ansv[el])!=msfuncs.end())msfuncs.erase(msfuncs.find(ansv[el]));
            // msfuncs.erase(msfuncs.find(ansv[el]));
            hasfunc[el]=0;
            if(el<n-1){
                hasaij[el]=1;
                if(el<j){
                    msaij.insert(-a[el+1]);
                }
            }
        }
        if(hasaij[j]){
            msaij.insert(-a[j+1]);
        }
        
        debugc(ansv)
        debugc(msaij)
        debugc(msfuncs)
        
        
        int temp1 = inf;
        if(!msaij.empty())temp1 = *msaij.begin() + a[i];
        int temp2 = inf;
        if(!msfuncs.empty())temp2 = *msfuncs.begin();
        
        ansv[i] = min(temp1, temp2);
        debugc(ansv)

        if(i<n-1){
            int ind = upper_bound(All(a), ansv[i] + a[i+1]) - a.begin();
            debug(ind)
            swic[ind].push_back(i);
        }
        
        i++;
        j++;
    }

    cout<<ansv[n-1]<<endl;


    



    // debug(cnt)


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
