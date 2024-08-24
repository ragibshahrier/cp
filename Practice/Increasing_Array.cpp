#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; i<n; i++)
#define gp <<" "<<
//#define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

void solve(){
    int n;
    ll ans=0;
    cin>>n;

    vi v(n);
    rep(i, 0, n){
        cin>>v[i];
    }
    rep(i, 1, n){
        if(v[i]<v[i-1]){
            ans+= v[i-1]-v[i];
            v[i]=v[i-1];
        }
        
    }
    cout<<ans;

}

int main(){
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
