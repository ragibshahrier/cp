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


void preprocessing(){

}

const int N = 100000;  
  
int n; // array size 
  
// Max size of tree 
int tree[4 * N]; 
  
// function to build the tree 
void build(vi& arr)  
{  
    // insert leaf nodes in tree 
    for (int i=0; i<n; i++)     
        tree[n+i] = arr[i]; 
      
    // build the tree by calculating parents 
    for (int i = n - 1; i > 0; --i)      
        tree[i] = tree[i<<1] | tree[i<<1 | 1];     
} 
  
// function to update a tree node 
void updateTreeNode(int p, int value)  
{  
    // set value at position p 
    tree[p+n] = value; 
    p = p+n; 
      
    // move upward and update parents 
    for (int i=p; i > 1; i >>= 1) 
        tree[i>>1] = tree[i] + tree[i^1]; 
} 
  
// function to get sum on interval [l, r) 
int query(int l, int r)  
{  
    int res = 0; 
      
    // loop to find the sum in the range 
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
    { 
        if (l&1)  
            res |= tree[l++]; 
      
        if (r&1)  
            res |= tree[--r]; 
    }
      
    return res; 
} 



bool check(vi& a, int k){
    int nn = a.size();
    int j = 0;
    ll ans = 0;
    for(int i=0; i<nn-k+1; i++){
        if(i==0){
            ans = query(i,i+k);
        }else{
            if(ans != query(i , i+k)){
                debug(ans)
                debug(query(i,i+k))
                debug(k)
                debug(i)
                return 0;
            }
        }
    }
    return 1;
}


void solve(){
    cin>>n;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    build(a);
    ll lo = 1; 
    ll hi = n;
    ll mid=(hi+lo)/2;
    while(hi-lo>1){
        mid = (hi+lo)/2;
        if(check(a, mid)){
            hi = mid;
        }else{
            lo = mid+1;
        }
        
    }


    if(check(a,lo))cout<<lo<<endl;
    else cout<<hi<<endl;



}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
