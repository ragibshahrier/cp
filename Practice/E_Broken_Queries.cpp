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

int ask(int l, int r){
    cout<<"? "<<l<<" "<<r<<endl;
    cout.flush();
    int anss;
    cin>>anss;
    return anss;
}

void tell(int k){
    cout<<"! "<<k<<endl;
    cout.flush();

}




void preprocessing(){

}


pi tellrng(int n, int loa, int hia, int mid){
    int l,r;
    int rng = mid-(hia-loa+1);

    if(n-hia >= rng){
        l = loa;
        r = hia+rng;
        return {l,r};
    }else{
        rng -= (n-hia);
        l = loa-rng;
        r = n;
        return {l,r}; 
    }
}

void solve(int testcases){
    int n;
    cin>>n;

    int a,b,c;

    int met = 0;

    int loa,hia;

    a = ask(1,n/4);
    b = ask(1+n/4,2*n/4);
    c = ask(1+2*n/4,3*n/4);

    if(a+b+c==3){
        met = 1;
        loa = 1;
        hia= n/4; 
    }else if(a+b+c==2){
        met =1;
        if(a==0){
            loa = 1+n/4;
            hia = n/2;
        }else if(b==0){
            loa = 1;
            hia  =  n/4;

        }else if (c==0){
            loa = 1;
            hia  = n/4;
        }
    }


    else if(a+b+c==0){
        met = 0;
        loa = 1+3*n/4;
        hia= n; 
    }else if(a+b+c==1){
        met =0;
        if(a==1){
            loa = 1;
            hia = n/4;
        }else if(b==1){
            loa = 1+n/4;
            hia  =  n/2;

        }else if (c==1){
            loa = 1+n/2;
            hia  = 3*n/4;
        }
    }

    ll ans;
    if(met==1){
        ll lo = 2;
        ll hi = n/4;

        while(hi-lo>1){
            ll mid = lo + (hi-lo)/2;

            int l = loa;
            int r = loa + mid-1;

            if(ask(l,r)){
                hi = mid;
            }else{
                lo = mid+1;
            }
        }

        int l = loa;
        int r = loa + lo-1;

        if(ask(l,r)){
            ans = lo;
        }else{
            ans = hi;
        }
    }else{
        ll lo = n/4+1;
        ll hi = n-1;
        while(hi-lo>1){
            ll mid = lo + (hi-lo)/2;

            pi p = tellrng(n, loa, hia, mid);

            int l = p.ff;
            int r = p.ss;
            
            if(ask(l,r)){
                lo = mid+1;
            }else{
                hi = mid;
            }
            
            
        }
        pi p = tellrng(n, loa, hia, lo);

        int l = p.ff;
        int r = p.ss;

        if(ask(l,r)){
            ans = hi;
        }else{
            ans = lo;
        }
    }

    tell(ans);



}

int32_t main(){
    // fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
