#include<bits/stdc++.h>


#define int long long
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define inf INT_MAX



using namespace std;
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
        // Internal node will store the maximum of the two
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
        // Internal node will store the maximum of the two
        // children
        tree[node]
            = max(tree[left(node)], tree[right(node)]);
    }

    // Function to query the maximum value in a given range
    T query(int node, int start, int end, int l, int r)
    {
        // If the current node's range is completely outside
        // the query range
        if (r < start || end < l)
            return INT_MAX;
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

    // Public function to query the maximum value in a given
    // range
    // closed interval, 0 based indexing
    T query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }
};








void solve(){
	int n; cin >> n;
	vector<int> a(n); for(int i=0; i < n; i++) cin >> a[i];
	for(int i=0; i < n; i++) a[i]--;
	vector<int> b(n, 2);
	map<int, int> mp;
	vector<int> dp(n, 0);

	vector<int> opt(n, 0);

	for(int i=0; i < n; i++){
		mp[a[i]] = i;
	}


	vector<int> seg(n + 1, 0);
	// segment tre array


	for(int i=0; i < n; i++){

		// max range from 0 to a[i]
		// idx will be the optimum idx;
		int idx = 0;
		for(int j=0; j <= a[i]; j++){
			if(seg[j] > seg[idx]) idx = j;
		}


		dp[i] = seg[idx];


		if(dp[i] != 0)
			opt[i] = mp[idx];
		else
			opt[i] = i;

		dp[i] = dp[i] + b[i];


		// update at a[i] position

		seg[a[i]] = dp[i];
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
	vector<pair<int, int>> aa, bb;

	for(auto it: st){
		if(a[it] < it)
			aa.pb({a[it], it});
		else
			bb.pb({a[it], it});
	}


	sort(aa.begin(), aa.end());

	sort(bb.begin(), bb.end());
	reverse(bb.begin(), bb.end());


	int same = 0;
	for(int i=0; i < n; i++) if(a[i] == i) same++;

	static int tc = 1;
	cout << "Case " << tc << ": ";


	cout << 3 * n - ans  - same<< endl;








	for(auto it: aa){
		cout << it.ss + 1 << " " << 1 << " " << it.ss + 1 << " " << 8 << endl;

		if(it.ff != it.ss)
			cout << it.ss + 1 << " " << 8 << " " << it.ff + 1 << " " << 8 << endl;

	}


	for(auto it: bb){
		cout << it.ss + 1 << " " << 1 << " " << it.ss + 1 << " " << 7 << endl;

		if(it.ff != it.ss)
			cout << it.ss + 1 << " " << 7 << " " << it.ff + 1 << " " << 7 << endl;
	}







	for(auto it: g){
		if(it != a[it])
			cout << it + 1 << " " << 1 << " " << a[it] + 1 << " " << 1 << endl;
	}

	for(auto it: aa){
		cout << it.ff + 1 << " " << 8 << " " << it.ff  + 1<< " " << 1 << endl;
	}

	for(auto it: bb){
		cout << it.ff + 1 << " " << 7 << " " << it.ff  + 1<< " " << 1 << endl;
	}






	
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
		
	int t; cin >> t;
	while(t--) solve();
	

	return 0;
}