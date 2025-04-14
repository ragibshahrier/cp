#include<bits/stdc++.h>


#define int long long
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define inf INT_MAX

#define gp " "
// #define DEBG


#define debug(n)
#define debugc(a)
#define debugcc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<'{'<<gp<<el.ff<<','<<el.ss<<gp<<'}'<<gp;}cout<<']'<<endl;
#endif

using namespace std;
template <typename T> class SegmentTree {
private:
    // Segment tree to store the minimums
    vector<pair<T,int>> tree;
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
            tree[node] = {arr[start],start};
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
            tree[node] = {val,start};
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
    pair<int,int> query(int node, int start, int end, int l, int r)
    {
        // If the current node's range is completely outside
        // the query range
        if (r < start || end < l)
            return {INT_MIN,-1};
        // If the current node's range is completely inside
        // the query range
        if (l <= start && end <= r)
            return tree[node];
        // Calculate the middle index
        int m = mid(start, end);
        // Recursively query the left and right children and
        // combine the results
        pair<T,int> left_min = query(left(node), start, m, l, r);
        pair<T,int> right_min = query(right(node), m + 1, end, l, r);
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
    pair<T,int> query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }
};






void solve(){
	int n; cin >> n;
	vector<int> a(n); for(int i=0; i < n; i++) cin >> a[i];
	for(int i=0; i < n; i++) a[i]--;
	vector<int> b(n, 2);

	vector<int> dp(n, 0);

	vector<int> opt(n, 0);

    SegmentTree<int>sg(dp);

	for(int i=0; i < n; i++){


			

		opt[i] = i;
        debugc(dp)




		// find max between 0 to a[i];
		// with index
        debugc(a)

        int x = min(sg.query(0,max(0LL,a[i]-1)),sg.query(0,max(0LL, i-1))).ss;
        // int xx = lower_bound(dp.begin(), dp.begin()+a[i]+1, x) - dp.begin();





		

		for(int j=0; j < i; j++){
			if(a[j] < a[i]){
				if(dp[opt[i]] < dp[j]){
					opt[i] = j;
				}

			}
		}
        debug(a[i])
        debug(opt[i])
        debug(x)


		dp[i] = dp[opt[i]];


		dp[i] = dp[i] + b[i];
        sg.update(i,dp[i]);

	}


	int idx = 0;
	for(int i=0;i < n; i++)
		if(dp[idx] < dp[i]) idx = i;

	int ans = dp[idx];	






	vector<int> g = {idx};
	while(opt[idx] != idx){
		idx = opt[idx];
		g.pb(idx);
	}

	set<int> st;
	for(int i=0; i < n;i++)
		st.insert(i);
	for(auto it: g)
		st.erase(it);
	vector<pair<int, int>> aa;

	for(auto it: st){
		aa.pb({a[it], it});
	}

	sort(aa.begin(), aa.end());


	int same = 0;
	for(int i=0; i < n; i++) if(a[i] == i) same++;




	cout << 3 * n - ans  - same<< endl;




	for(auto it: aa){

		cout << it.ss + 1 << " " << 1 << " " << it.ss + 1 << " " << 8 << endl;
		if(it.ff != it.ss)
			cout << it.ss + 1 << " " << 8 << " " << it.ff + 1 << " " << 8 << endl;
	}
	for(auto it: g){
		if(it != a[it])
			cout << it + 1 << " " << 1 << " " << a[it] + 1 << " " << 1 << endl;
	}
	for(auto it: aa){
		cout << it.ff + 1 << " " << 8 << " " << it.ff  + 1<< " " << 1 << endl;
	}














}





int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
		
	int t; cin >> t;
	while(t--) solve();
	

	return 0;
}