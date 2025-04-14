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



// C++ Program to Implement Segment Tree for Minimum Range
// Queries


// Template class for Segment Tree
template <typename T> class SegmentTree1 {
private:
    // Segment tree to store the minimums
    vector<T> tree;
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
    void build(int node, int start, int end)
    {
        // If the current node represents a single element,
        // store it in the tree
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        // Calculate the middle index
        int m = mid(start, end);
        // Recursively build the left and right children
        build(left(node), start, m);
        build(right(node), m + 1, end);
        // Internal node will store the minimum of the two
        // children
        tree[node]
            = max(tree[left(node)], tree[right(node)]);
    }

    // Function to update the value at a specific index in
    // the segment tree
    void update(int node, int start, int end, int idx,
                T val)
    {
        // If the current node represents a single element,
        // update it
        if (start == end) {
            arr[idx] = val;
            tree[node] = val;
            return;
        }
        // Calculate the middle index
        int m = mid(start, end);
        // Recursively update the left or right child
        if (idx <= m)
            update(left(node), start, m, idx, val);
        else
            update(right(node), m + 1, end, idx, val);
        // Internal node will store the minimum of the two
        // children
        tree[node]
            = max(tree[left(node)], tree[right(node)]);
    }

    // Function to query the minimum value in a given range
    T query(int node, int start, int end, int l, int r)
    {
        // If the current node's range is completely outside
        // the query range
        if (r < start || end < l)
            return INT_MIN;
        // If the current node's range is completely inside
        // the query range
        if (l <= start && end <= r)
            return tree[node];
        // Calculate the middle index
        int m = mid(start, end);
        // Recursively query the left and right children and
        // combine the results
        T left_max = query(left(node), start, m, l, r);
        T right_max = query(right(node), m + 1, end, l, r);
        return max(left_max, right_max);
    }

public:
    // Constructor to initialize the segment tree with the
    // input array
    SegmentTree1(const vector<T>& a)
        : arr(a)
        , n(a.size())
    {
        // Resize the tree to accommodate the segment tree
        // nodes
        tree.resize(4 * n);
        // Build the segment tree
        build(0, 0, n - 1);
    }

    // Public function to update the value at a specific
    // index
    // 0 based indexing
    void update(int idx, T val)
    {
        update(0, 0, n - 1, idx, val);
    }

    // Public function to query the minimum value in a given
    // range
    // closed interval, 0 based indexing
    T query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }
};


template <typename T> class SegmentTree2 {
private:
    // Segment tree to store the maximums
    vector<T> tree;
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
    void build(int node, int start, int end)
    {
        // If the current node represents a single element,
        // store it in the tree
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        // Calculate the middle index
        int m = mid(start, end);
        // Recursively build the left and right children
        build(left(node), start, m);
        build(right(node), m + 1, end);
        // Internal node will store the minimum of the two
        // children
        tree[node]
            = (tree[left(node)]+ tree[right(node)]);
    }

    // Function to update the value at a specific index in
    // the segment tree
    void update(int node, int start, int end, int idx,
                T val)
    {
        // If the current node represents a single element,
        // update it
        if (start == end) {
            arr[idx] = val;
            tree[node] = val;
            return;
        }
        // Calculate the middle index
        int m = mid(start, end);
        // Recursively update the left or right child
        if (idx <= m)
            update(left(node), start, m, idx, val);
        else
            update(right(node), m + 1, end, idx, val);
        // Internal node will store the minimum of the two
        // children
        tree[node]
            = (tree[left(node)]+ tree[right(node)]);
    }

    // Function to query the minimum value in a given range
    T query(int node, int start, int end, int l, int r)
    {
        // If the current node's range is completely outside
        // the query range
        if (r < start || end < l)
            return 0;
        // If the current node's range is completely inside
        // the query range
        if (l <= start && end <= r)
            return tree[node];
        // Calculate the middle index
        int m = mid(start, end);
        // Recursively query the left and right children and
        // combine the results
        T left_min = query(left(node), start, m, l, r);
        T right_min = query(right(node), m + 1, end, l, r);
        return (left_min+ right_min);
    }

public:
    // Constructor to initialize the segment tree with the
    // input array
    SegmentTree2(const vector<T>& a)
        : arr(a)
        , n(a.size())
    {
        // Resize the tree to accommodate the segment tree
        // nodes
        tree.resize(4 * n);
        // Build the segment tree
        build(0, 0, n - 1);
    }

    // Public function to update the value at a specific
    // index
    // 0 based indexing
    void update(int idx, T val)
    {
        update(0, 0, n - 1, idx, val);
    }

    // Public function to query the minimum value in a given
    // range
    // closed interval, 0 based indexing
    T query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }
};




// template <typename T> class SegmentTree2 {
// private:
//     // Segment tree to store the minimums
//     vector<T> tree;
//     // Input array
//     vector<T> arr;
//     // Size of the input array
//     int n;

//     // Helper function to get the left child of a node
//     int left(int node) { return 2 * node + 1; }

//     // Helper function to get the right child of a node
//     int right(int node) { return 2 * node + 2; }

//     // Helper function to calculate the middle index
//     int mid(int l, int r) { return l + (r - l) / 2; }

//     // Function to build the segment tree
//     void build(int node, int start, int end)
//     {
//         // If the current node represents a single element,
//         // store it in the tree
//         if (start == end) {
//             tree[node] = arr[start];
//             return;
//         }
//         // Calculate the middle index
//         int m = mid(start, end);
//         // Recursively build the left and right children
//         build(left(node), start, m);
//         build(right(node), m + 1, end);
//         // Internal node will store the minimum of the two
//         // children
//         tree[node]
//             = (tree[left(node)]+ tree[right(node)]);
//     }

//     // Function to update the value at a specific index in
//     // the segment tree
//     void update(int node, int start, int end, int idx,
//                 T val)
//     {
//         // If the current node represents a single element,
//         // update it
//         if (start == end) {
//             arr[idx] = val;
//             tree[node] = val;
//             return;
//         }
//         // Calculate the middle index
//         int m = mid(start, end);
//         // Recursively update the left or right child
//         if (idx <= m)
//             update(left(node), start, m, idx, val);
//         else
//             update(right(node), m + 1, end, idx, val);
//         // Internal node will store the minimum of the two
//         // children
//         tree[node]
//             = (tree[left(node)]+ tree[right(node)]);
//     }

//     // Function to query the minimum value in a given range
//     T query(int node, int start, int end, int l, int r)
//     {
//         // If the current node's range is completely outside
//         // the query range
//         if (r < start || end < l)
//             return 0;
//         // If the current node's range is completely inside
//         // the query range
//         if (l <= start && end <= r)
//             return tree[node];
//         // Calculate the middle index
//         int m = mid(start, end);
//         // Recursively query the left and right children and
//         // combine the results
//         T leftsum = query(left(node), start, m, l, r);
//         T rightsum = query(right(node), m + 1, end, l, r);
//         return (leftsum+ rightsum);
//     }

// public:
//     // Constructor to initialize the segment tree with the
//     // input array
//     SegmentTree2(const vector<T>& a)
//         : arr(a)
//         , n(a.size())
//     {
//         // Resize the tree to accommodate the segment tree
//         // nodes
//         tree.resize(4 * n);
//         // Build the segment tree
//         build(0, 0, n - 1);
//     }

//     // Public function to update the value at a specific
//     // index
//     // 0 based indexing
//     void update(int idx, T val)
//     {
//         // update(0, 0, n - 1, idx, val);
//     }

//     // Public function to query the minimum value in a given
//     // range
//     // closed interval, 0 based indexing
//     T query(int l, int r)
//     {
//         return query(0, 0, n - 1, l, r);
//     }
// };



void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vll a(n);
    vll b(m);
    vll kk(k);
    get_vector(a);
    get_vector(b);
    get_vector(kk);

    vi hsh(n+1);
    rep(i,0,m){
        hsh[b[i]]++;

    }
    map<int,int>indmp;
    vpi missing;
    rep(i,0,n){
        indmp[a[i]] = i;
        if(hsh[a[i]]==0){
            missing.push_back({a[i], i});
        }
    }
    sort(All(missing), greater<pi>());
    multiset<int>magic(All(kk));
    SegmentTree1<ll>seg1(a);
    vll trac(n);
    SegmentTree2<ll>seg2(trac);

    for(auto el:missing){
        int ele = el.ff;
        int ind = el.ss;

        int forr,bac;
        if(magic.size()==0){
            cout<<"NO"<<endl;return;
        }
        if(ind == n-1){
            forr= 0;
        }else if(seg1.query(ind+1,n-1)<ele){
            forr = n-1-ind;
        }else{
            ll hi = n-1;
            ll lo = ind+1;
            ll mid;
            while(hi-lo>1){
                mid = lo + (hi-lo)/2;
                if(seg1.query(lo,mid)>ele){
                    hi = mid;
                }else{
                    lo = mid+1;
                }
            }
            if(seg1.query(lo,lo)>ele){
                forr = lo-1-ind;
            }else{
                forr = hi-1-ind;
            }
        }

        if(ind == 0){
            bac = 0;
        }else if(seg1.query(0,ind-1)<ele){
            bac = ind;
        }else{
            ll hi = ind-1;
            ll lo = 0;
            ll mid;
            while(hi-lo>1){
                mid = lo + (hi-lo)/2;
                if(seg1.query(mid+1,hi)>ele){
                    lo = mid+1;
                }else{
                    hi = mid;
                }
            }
            if(seg1.query(hi,hi)>ele){
                bac = ind - (hi+1);
            }else{
                bac = ind - (lo+1);
            }
        }

        ll len = forr+bac + 1;
        len -= seg2.query(ind,ind+forr);
        len -= seg2.query(ind-bac,ind);
        auto itt = magic.upper_bound(len);
        debugc(magic)
        debug(len)
        if(itt == magic.begin()){
            cout<<"NO"<<endl;return;
        }
        itt--;
        magic.erase(itt);
        seg1.update(ind,-5);
        seg2.update(ind,1);
        


    }
    cout<<"YES"<<endl;




}

int main(){
    fastcin();
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
