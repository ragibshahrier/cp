#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);


    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        int arr[n];
        for (int k = 0; k < n; k++) {
            cin >> arr[k];
        }

        int q;
        cin >> q;

        for (int j = 0; j < q; j++) {
            map <char, int> mp;
            map <int, char> rev_mp;

            string s;
            cin >> s;

            if (s.size() != n) {
                cout << "NO\n";
                continue;
            } else {
                int flag = 0;
                int count = 0;
                for (auto c : s) { 
                    int len = mp.size();
                    int past = mp[c];              
                    mp[c] = arr[count];

                    int rev_len = rev_mp.size();
                    char rev_past = rev_mp[arr[count]];
                    rev_mp[arr[count]] = c;

                    if (mp.size() == len) {
                        if (past != arr[count]) {
                            // cout << c << " - " << count <<" - past: " << past << " - now: " << arr[count] << "\n";
                            flag = 1;
                        }
                    }

                    if (rev_mp.size() == rev_len) {
                        if (rev_past != c) {
                            // cout << c << " - " << count <<" - past: " << past << " - now: " << arr[count] << "\n";
                            flag = 1;
                        }
                    }
                    count++;
                }

                if (flag == 1) cout << "NO\n";
                else cout << "YES\n";
            }

        }
    }
    return 0;
}