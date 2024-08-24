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
    ll ans=0, xr=0;
    cin>>n;
    rep(i, 1, n+1){
        xr ^= i;
    }
    rep(i, 0, n-1){
        int x;
        cin>>x;
        // if(i==0){
        //     ans=x;
        //     continue;
        // }
        ans^=x;

    }
    cout<<(ans^xr);

}

int main(){
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}
