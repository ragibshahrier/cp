#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define N 200005

struct segtree{
    int tree[4*N];
    void init(int node, int l, int r){
        if(l == r) { tree[node] = 0; return; }
        init(node*2, l, (l+r)/2);
        init(node*2+1, (l+r)/2 + 1, r);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    void update(int node, int l, int r, int p, int x){
        if(p<l || p>r)return;
        if(l == r) { tree[node] = x; return; }
        update(node*2, l, (l+r)/2, p, x);
        update(node*2+1, (l+r)/2 + 1, r, p, x);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    int query(int node, int l, int r, int a, int b){
        if(r < a || l > b) return 0;
        if(a <= l && r <= b) return tree[node];
        return query(node*2, l, (l+r)/2, a, b) + query(node*2+1, (l+r)/2 + 1, r, a, b);
    }
}sg;

int n, m, k;
int a[N], b[N], chk[N], idx[N], c[N];

void solve(){
    // cout<<1;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        chk[i] = 0;
        c[i] = 0;
    }
    // segtree sg;
    sg.init(1, 1, n);

    set<int> idxx;
    multiset<int> mlen;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        idx[a[i]] = i;
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
        chk[b[i]] = 1;
    }
    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        mlen.insert(x);
    }

    idxx.insert(0);
    idxx.insert(n+1);

    int flag = 0;
    for(int i = 1; i < m; i++){
        if(idx[b[i]] > idx[b[i+1]]) flag = 1;
    }

    if(flag){
        cout << "NO\n";
        return;
    }

    for(int i = n; i >= 1; i--){
        if(chk[i]){
            idxx.insert(idx[i]);
        } else {
            auto it = idxx.upper_bound(idx[i]);
            int lo, hi;
            hi = *it;
            it--;
            lo = *it;

            int len = hi - lo - 1 - sg.query(1, 1, n, lo+1, hi-1);
            sg.update(1, 1, n, idx[i], 1);

            auto itr = mlen.upper_bound(len);
            if(itr == mlen.begin()){
                cout << "NO\n";
                return;
            }
            itr--;
            mlen.erase(itr);
        }
    }
    cout << "YES\n";
}

int main(){
    fast;
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}
