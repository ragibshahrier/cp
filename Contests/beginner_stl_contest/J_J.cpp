#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; ii<n; ii++)
#define gp " "
// #define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

void solve(){
    int n;
    cin>>n;
    multiset<int>s;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];

    }
    sort(v.begin(),v.end());

    rep(i,0,n){
        int x;
        x = v[n-i-1];
        
        auto it = s.upper_bound(x);
        if(it==s.end()){
            s.insert(x);
        }
        else{
            s.erase(it);
            s.insert(x);
        }
        debug((s.size()))
    }
    cout<<s.size();



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
