#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
 
typedef long long ll;
 
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


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

vector<ll> initializeDiffArray(vector<ll>& A) 
{ 
    int n = A.size(); 
  
    // We use one extra space because 
    // update(l, r, x) updates D[r+1] 
    vector<ll> D(n + 1); 
  
    D[0] = A[0], D[n] = 0; 
    for (int i = 1; i < n; i++) 
        D[i] = A[i] - A[i - 1]; 
    return D; 
} 
  
// Does range update 
void update(vector<ll>& D, int l, int r, ll x) 
{ 
    D[l] += x; 
    D[r + 1] -= x; 
} 
  
// Prints updated Array 
void printArray(vector<ll>& A, vector<ll>& D) 
{ 
    for (int i = 0; i < A.size(); i++) { 
        if (i == 0) 
            A[i] = D[i]; 
  
        // Note that A[0] or D[0] decides 
        // values of rest of the elements. 
        else
            A[i] = D[i] + A[i - 1]; 
  
        
    } 
    
} 

vector<ll> A, ST;

void build(int node, int L, int R)
{
 
    // Leaf node where L == R
    if (L == R) {
        ST[node] = A[L];
    }
    else {
 
        // Find the middle element to
        // split the array into two halves
        int mid = (L + R) / 2;
 
        // Recursively travel the
        // left half
        build(2 * node, L, mid);
 
        // Recursively travel the
        // right half
        build(2 * node + 1, mid + 1, R);
 
        // Storing the sum of both the
        // children into the parent
        ST[node] = max(ST[2 * node] , ST[2 * node + 1]);
    }
}
 
void update(int node, int L, int R, int idx, int val)
{
 
    // Find the lead node and
    // update its value
    if (L == R) {
        A[idx] += val;
        ST[node] += val;
    }
    else {
 
        // Find the mid
        int mid = (L + R) / 2;
 
        // If node value idx is at the
        // left part then update
        // the left part
        if (L <= idx and idx <= mid)
            update(2 * node, L, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, R, idx, val);
 
        // Store the information in parents
        ST[node] = ST[2 * node] + ST[2 * node + 1];
    }
}
 
ll query(int node, int tl, int tr, int l, int r)
{
 
    // If it lies out of range then
    // return 0
    if (r < tl or tr < l)
        return 0;
 
    // If the node contains the range then
    // return the node value
    if (l <= tl and tr <= r)
        return ST[node];
    int tm = (tl + tr) / 2;
 
    // Recursively traverse left and right
    // and find the node
    return max(query(2 * node, tl, tm, l, r)
           , query(2 * node + 1, tm + 1, tr, l, r));
}


void solve(){
    int n,d,k;
    cin>>n>>d>>k;
    vll a(n);
    vll dd = initializeDiffArray(a);
    rep(i,0,k){
        int x,y;
        cin>>x>>y;
        update(dd, x-1, y-1, 1LL);
    }
    printArray(a,dd);
    debugc(a)

    A = a;
    ST.resize(4*n);
    build(1, 0, n-1);


    vll acc(n+1);
    rep(i,1,n+1){
        acc[i] = acc[i-1]+a[i-1];
    }
    debugc(acc)
    ll sb = inf,sm = 0;
    int stb = 0, stm = 0;
    rep(i,0,n-d+1){
        debug(stb)
        debug(stm)
        debug(acc[d+i]-acc[i])
        debug(acc[d+stb]-acc[stb])
        debug(acc[d+stm]-acc[stm])
        ll qq = query(1,0,n-1,i,i+d-1);
        debug(qq)

        if(qq>sb){
            sb = qq;
            stb = i;
        }
        if(qq<sm){
            sm = qq;
            stm = i;
        }
        debug(stb)
        debug(stm)
    }
    cout<<stb+1<<gp<<stm+1<<endl;


}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
