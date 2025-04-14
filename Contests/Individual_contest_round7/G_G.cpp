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

template <typename T> class LazySegmentTree {
    private:
        // Segment tree and lazy array to store values and lazy updates
        vector<T> tree, lazy;
        // Input array
        vector<T> arr;
        // Size of the input array
        int n;
    
        // Helper function to get the left child of a node
        int left(int node) { return 2 * node + 1; }
    
        // Helper function to get the right child of a node
        int right(int node) { return 2 * node + 2; }
    
        // Helper function to calculate the middle index
        int mid(int l, int r) { return l + (r - l) / 2; }
    
        // Function to build the segment tree
        void build(int node, int start, int end) {
            if (start == end) {
                tree[node] = arr[start];
                return;
            }
            int m = mid(start, end);
            build(left(node), start, m);
            build(right(node), m + 1, end);
            tree[node] = min(tree[left(node)], tree[right(node)]);
        }
    
        // Function to propagate the lazy values
        void propagate(int node, int start, int end) {
            if (lazy[node] != 0) {
                tree[node] += lazy[node];
                if (start != end) { // Not a leaf node
                    lazy[left(node)] += lazy[node];
                    lazy[right(node)] += lazy[node];
                }
                lazy[node] = 0;
            }
        }
    
        // Function to update a range of values
        void updateRange(int node, int start, int end, int l, int r, T val) {
            propagate(node, start, end);
            if (r < start || end < l)
                return; // Out of range
            if (l <= start && end <= r) {
                lazy[node] += val;
                propagate(node, start, end);
                return;
            }
            int m = mid(start, end);
            updateRange(left(node), start, m, l, r, val);
            updateRange(right(node), m + 1, end, l, r, val);
            tree[node] = min(tree[left(node)], tree[right(node)]);
        }
    
        // Function to query the minimum value in a given range
        T queryRange(int node, int start, int end, int l, int r) {
            propagate(node, start, end);
            if (r < start || end < l)
                return INT_MAX;
            if (l <= start && end <= r)
                return tree[node];
            int m = mid(start, end);
            T left_min = queryRange(left(node), start, m, l, r);
            T right_min = queryRange(right(node), m + 1, end, l, r);
            return min(left_min, right_min);
        }
    
    public:
        // Constructor to initialize the lazy segment tree with the input array
        LazySegmentTree(const vector<T>& a)
            : arr(a), n(a.size()) {
            tree.resize(4 * n);
            lazy.resize(4 * n, 0);
            build(0, 0, n - 1);
        }
    
        // Public function to update the range of values
        void updateRange(int l, int r, T val) {
            updateRange(0, 0, n - 1, l, r, val);
        }
    
        // Public function to query the minimum value in a given range
        T queryRange(int l, int r) {
            return queryRange(0, 0, n - 1, l, r);
        }
};


void solve(int testcases){
    int n;
    cin>>n;
    vi a(n);
    get_vector(a);

    vi arr(n);

    vi hsh(n+1);

    rep(i,0,n){
        hsh[a[i]]=i;
    }
    ll ans = 0;

    LazySegmentTree<int>lst(arr);

    for(int i = n; i>=1; i--){
        int ind = hsh[i]+lst.queryRange(hsh[i],hsh[i]);
        int dest = i-1;
        int lo = ind+1;
        int up = dest;
        int temp = up*(up+1)/2 - lo*(lo-1)/2;
        debug(i)
        debug(ind)
        debug(dest)
        ans += temp;
        lst.updateRange(hsh[i], n-1, -1);
    }


    // for(int i=0; i<n-1; i++){
    //     for(int j= 0; j<n-i-1; j++){
    //         if(a[j]>a[j+1]){
    //             ans+=(j+1);
    //             swap(a[j],a[j+1]);
    //         }
    //     }
    // }
    // debugc(a)

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
