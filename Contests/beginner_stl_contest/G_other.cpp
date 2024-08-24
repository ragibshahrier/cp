#include<bits/stdc++.h>
 
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), ans1;
    bool ans = 0;
    unordered_map<int, int> mj;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mj[a[i]] = i+1;
    }
    sort(a.begin(), a.end());
    int i = 0,j = 0, k = 0;
long long sum = 0;
    for (i = 0; i < n; ++i) {
        sum += a[i];
        if(x >= sum){
            j = i;
        }
        while(sum > x && k < j){
            sum -= a[k++];
        }
        if(sum == x){
            ans = 1;
            ans1.push_back(k);
            ans1.push_back(j);
            break;
        }
    }
    if(ans){
    for(int i = ans1[0], j = 0; i <= ans1[1]; i++){
        if(mj[a[i]] == mj[a[i+1]]){
         cout << (mj[a[i]]+j) << " ";
         j++;
         continue;   
        }
        cout << mj[a[i]] << " ";
    }cout << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
solve();
return 0;
}