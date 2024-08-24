#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        unordered_map<int, int> mp;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[(a[i] % (2 * k))]++;
        }

        bool valid = true;
        for (int i = 0; i < n; ++i) {
            int rem = (a[i] % (2 * k));
            if (mp[rem] > 0 && mp[(rem + k) % (2 * k)] > 0) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout << -1 << endl;
        } else {
            int maxi = *max_element(a.begin(), a.end());
            int ans = maxi + ((2 * k - maxi % (2 * k)) % (2 * k));
            cout << ans << endl;
        }
    }

    return 0;
}
