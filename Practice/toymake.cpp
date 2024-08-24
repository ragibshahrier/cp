#include<bits/stdc++.h>
 
using namespace std;

bool check(vector<int> arr, long long mid, int m){
    long long count_of_m = 0;
    for(int i = 0; i < arr.size(); i++){
        count_of_m += mid/arr[i];
    }
    return (count_of_m >= m);
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long lo = 0, hi = (a[n-1]*static_cast<long long>(m)), mid;
    long long time = hi;
    while((hi-lo)>0){
        mid = (hi+lo)/2;
        if(check(a, mid, m)){
            time = mid;
            hi = mid;
        }else{
            lo = mid+1;
        }
    }
    cout<<lo<<endl;
    if(check(a, lo, m))time = lo;
    else time = hi;
    cout << time << endl;
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