#include<bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
            a[i] = i+1;
    }//cout<<2*((n/2)*1LL*(n/2))<<" "<<(n&1)<<endl;
    if(k&1){
        cout << "NO" << endl;
        return;
    }
    
    else if(((n&1) == 0 && k > 2*((n/2)*1LL*(n/2))) || ((n&1) != 0 && k > 2*((n/2)*1LL*(n/2 + 1)))){
        cout << "NO" << endl;
        return;
    }else{
        for(int i = 1, j= 1; i<= n; i++, j+=2){
            if(k >= 2*(n-j)){
                swap(a[i-1], a[n-i]);
                k -= 2*(n-j);
            }else{
                swap(a[n-i], a[n-i-(k/2)]);
                k -= k;
            }
            if(k==0){
                break;
            }
        }
        cout << "Yes" << endl;
        for(auto j : a){
            cout << j << " ";
        }cout << endl;
        return;
    }
    
}
int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}