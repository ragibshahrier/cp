#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    int x;
    cin >> n >> x;
    vector<int> a(n);
    unordered_map<int, int> mj;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mj[a[i]] = i;
    }
    sort(a.begin(), a.end());

    int l, r;

    for (int i = 1; i < (n - 1); i++)
    {
        l = i + 1;
        r = n;
        while (l < r)
        {
            long long sum = a[i] + a[l] + a[r];

            if (sum == x)
            {
                cout << mj[a[i]] << " " << mj[a[l]] << " " << mj[a[r]] << endl;
                return;
            }

            else if (sum < x)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}