#include<bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 

// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

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
#define checkbit(x,n) (x&(1LL<<n))
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


const int N = 2e5+7;  
  
ll arrsize;
  
vll treee(4 * N); 

void build( vll& arr)  
{  
    for (int i=0; i<arrsize; i++)     
        treee[arrsize+i] = arr[i]; 
      
    for (int i = arrsize - 1; i > 0; --i)      
        treee[i] = treee[i<<1LL] + treee[i<<1LL | 1];     
} 
  
// update a treee node 
void updatetreeeNode(int p, int value)  
{  

    treee[p+arrsize] += value; 
    p = p+arrsize; 
      

    for (int i=p; i > 1; i >>= 1) 
        treee[i>>1] = treee[i] + treee[i^1]; 
} 
  
// interval [l, r) 
ll query(ll l, ll r)  
{  
    ll res = 0; 
      
    // loop to find the sum in the range 
    for (l += arrsize, r += arrsize; l < r; l >>= 1LL, r >>= 1LL) 
    { 
        if (l&1)  
            res += treee[l++]; 
      
        if (r&1)  
            res += treee[--r]; 
    } 
      
    return res; 
} 



void preprocessing(){

}

void solve(){
    int nn, q;
    cin>>nn>>q;
    vi a(nn);
    arrsize=N;
    vll arr(N,0);
    build(arr);
    
    vll arr2(nn+7,0);
    rep(i,0,nn){
        cin>>a[i];
    }
    for(int i=0; i<nn; i++){
        debugc(arr2)
        if(i==0){
            updatetreeeNode(1,1);
            arr2[i]=1;
            continue;
        }
        ll lo = 1;
        ll hi = 2e5 +4 ;
        ll mid = (hi+lo)/2;

        while(hi-lo>1){
            mid = (hi+lo)/2;
            debug(mid)
            ll x = (query(1,mid+1))/mid + 1 ;
            debug(x)
            if(x >a[i]){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        debug(lo)
        debug(hi)
        debug(arr[lo])
        
        ll x = (query(1,lo+1))/lo + 1 ;
        
        debug(x)
        if((x)>a[i]){
            arr2[i]=hi;
            updatetreeeNode(hi,1);
        }else{
            arr2[i]=lo;
            updatetreeeNode(lo,1);
        }
        debugc(arr2)


    }
    while(q--){
        int i,x;
        cin>>i>>x;
        if(x>=arr2[i-1]){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
