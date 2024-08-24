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



ll logi(ll a, ll b){
    ll ans = 0;
    if(b==1)return INT_MAX;
    while(a>0){
        a/=b;
        ans++;
    }
    return ans;

}

void solve(){
    ll a,b;
    cin>>a>>b;
    ll ans=0;
    ll tempans = 0;
    while(a!=0){
        debug(a)
        debug(b)
        debug(logi(a,b))
        debug(logi(a,b+1))
        
        if(logi(a,b)>logi(a,b+1)){
            b++;
        }else{
            a/=b;
        }
        ans++;
    }
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
