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
//#define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------
const int N = 2e5 + 7;

int n, a, b;
vi v(N);



ll func(int start){
    if(start == b)return 0;
    if(min(v[start], v[b])>=abs(start-b)){
        return 1;
    }
    for(int i=)
}

void solve(){
    cin>>n>>a>>b;
    rep(i,1,n+1){
        cin>>v[i];
    }
    ll ans = func(a);
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
