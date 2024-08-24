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

ll func(int n, int k){
    if(n==1)return 0;
    debug(n)
    debug(k)
    if(n<=k)return 1;
    else return func(n-(k-1),k)+1;
}


void solve(){
    int n,k;
    cin>>n>>k;
    ll ans = func(n,k);
    cout<<ans<<endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
