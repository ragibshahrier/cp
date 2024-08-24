#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; ii<n; ii++)
#define gp " "

//bit_manupulation
#define checkbit(x,n) (((x&(1LL<<n))>0))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define resetbit(x,n) (x=(x&(~(1LL<<n))))

// #define DEBG

#define debug(n)
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#endif

#define fastcin() ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;


//----------------------CODE STARTS HERE-------------------


void preprocessing(){

}

bool check(vi& a, int k){
    int n = a.size();
    for(int m=0; m<31; m++){
        vi pre(n+1);
        pre[0]=0;
        rep(i,1,n+1){
            pre[i]=pre[i-1]+checkbit(a[i-1],m);
        }
        debug(m)
        debugc(pre)
        for(int i=0, j=i+k;i<n-k; i++,j++){
            debug(k) 
            debug(pre[j])
            debug(pre[i])
            debug(pre[j+1])
            debug(pre[i+1])
            if(((pre[j]-pre[i]>0) && (pre[j+1]-pre[i+1]==0))||((pre[j]-pre[i]==0) && (pre[j+1]-pre[i+1]>0))){
                // debug(k)
                // debug(a[i])
                // debug(pre[i])
                // debug(a[j])
                // debug(m)
                return 0;
            }
        }
    }
    return 1;
    
}


void solve(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }

    ll lo = 1; 
    ll hi = n;
    ll mid=(hi+lo)/2;
    while(hi-lo>1){
        mid = (hi+lo)/2;
        debug(mid)
        if(check(a, mid)){
            debug(mid)
            hi = mid;
        }else{
            lo = mid+1;
        }
        
    }

    if(check(a,lo))cout<<lo<<endl;
    else cout<<hi<<endl;
    debug((checkbit(3,2)))



}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
