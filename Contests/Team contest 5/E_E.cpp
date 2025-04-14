#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
// using namespace __gnu_pbds; 
#define int long long
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

template <typename T> class SegmentTree {
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
        T left_min = query(left(node), start, m, l, r);
        T right_min = query(right(node), m + 1, end, l, r);
        return max(left_min, right_min);
    }

public:
    // Constructor to initialize the segment tree with the
    // input array
    SegmentTree(const vector<T>& a)
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



void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vi a(n);
    vi  b(m);
    vi kk(k);
    get_vector(a);
    get_vector(b);
    get_vector(kk);
    multiset<int>kkk(All(kk));
    multiset<int>bb(All(b));
    map<int,int>mp;
    rep(i,0,n){
        mp[a[i]]=i;
    }
    vpi miss;

    for(int i = n; i>=1; i--){
        if(bb.find(i)==bb.end()){
            miss.push_back({i,mp[i]});
        }
    }
    SegmentTree<int>str1(a);
    vi trk(n);
    SegmentTree2<int>str2(trk);

    debugcc(miss)

    for(auto el:miss){
        debug(el.ff)


        int ele = el.ff;
        int ind = el.ss;


        ll lo = ind+1;
        ll hi  = n-1;
        ll forr = hi-lo+1;
        ll mid = (hi+lo)/2;

        if(ind == n-1){
            forr = 0;
        }
        else if(str1.query(lo,hi)<ele){
            forr = hi-lo+1;
        }
        else{
            while(hi-lo>1){
                mid = (hi+lo)/2;
                if(str1.query(lo,mid) > ele){
                    hi = mid;
                    // forr = hi-ind;
                }else if(str1.query(mid+1,hi) > ele){
                    lo = mid+1;
                }
            }

            if(str1.query(lo,lo) > ele){
                forr  = lo-(ind+1);
            }else{
                forr = hi-(ind+1);
            }
        }

        hi = ind-1;
        lo = 0;
        int bac;
        mid = (hi+lo)/2;
        if(ind == 0){
            bac = 0;
        }
        else if(str1.query(lo,hi)<ele){
            bac = hi-lo+1;
        }
        else{
            while(hi-lo>1){
                mid = (hi+lo)/2;
                if(str1.query(mid+1,hi) > ele){
                    lo = mid+1;
                    // forr = hi-ind;
                }else if(str1.query(lo,mid) > ele){
                    hi = mid;
                }
            }
            if(str1.query(hi,hi) > ele){
                bac  = (ind-1)-hi;
            }else{
                bac = (ind-1)-lo;
            }


        }
        int len = forr+bac+1;
        len -= str2.query(ind-bac,ind);
        len -= str2.query(ind, ind+forr);
        debug(ele)
        debug(ind)
        debug(len)
        debugc(kkk)
        if(kkk.size()==0){
            cout<<"NO"<<endl;
            return;
        }
        auto itt = kkk.upper_bound(len);
        if(itt == kkk.begin()){
            cout<<"NO"<<endl;
            return;
        }
        itt--;
        kkk.erase(itt);
        str1.update(ind, -1);
        str2.update(ind, 1);
        
        

        


    }
    cout<<"YES"<<endl;



}

int32_t main(){
    fastcin();
    // freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
