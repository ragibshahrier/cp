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

//ll n;
const ll M = 1e9+7;

// void solve(){
//     ll ans=0;
//     ll n;
//     cin>>n;
//     ll sq = sqrt(n);
//     // debug(sq)
//     for(ll i=1; i<=sq; i++){
//         // ans = (ans+(((n/i)-1)*i));
//         // if(n/i !=i) ans = (ans+(((n/i)-1)*i));
//         // debug(i)
//         // debug(ans)
//         // if(n/i > i-1)
//         ans = (ans + ((i%M)*((n/i - (i-1))%M))%M)%M;
//         ll x = n/i;
//         if(x&1)ans = (  ans + (( ((x)%M) * (((x+1)/2))%M) )%M   )%M;
//         else ans = (  ans + ( (((x/2)%M) * (((x+1)))%M) )%M   )%M;
//         if(i&1)ans = (ans -((((i)%M)*((i+1)/2)%M))%M)%M;
//         else ans = (ans -((((i/2)%M)*((i+1))%M))%M)%M;
//         if(ans<0)ans+=M;
        
//     }
//     // ans+=n-1;
//     // if(n&1)ans += (((((n+1)/2)%M)*(n%M))%M);
//     // else ans += (((((n+1))%M)*((n/2)%M))%M);
//     // ans = ans%M;
//     if(ans<0)ans+=M;
//     cout<<ans;
//     //return ans;

// }

ll solve(ll n){
    ll ans=0;
    //ll n;
    // cin>>n;
    ll sq = sqrt(n);
    // debug(sq)
    for(ll i=1; i<=sq; i++){
        // ans = (ans+(((n/i)-1)*i));
        // if(n/i !=i) ans = (ans+(((n/i)-1)*i));
        // debug(i)
        // debug(ans)
        // if(n/i > i-1)
        ans = (ans + ((i%M)*((n/i - (i-1))%M))%M)%M;
        ll x = n/i;
        if(x&1)ans = (  ans + (( ((x)%M) * (((x+1)/2))%M) )%M   )%M;
        else ans = (  ans + ( (((x/2)%M) * (((x+1)))%M) )%M   )%M;
        if(i&1)ans = (ans -((((i)%M)*((i+1)/2)%M))%M)%M;
        else ans = (ans -((((i/2)%M)*((i+1))%M))%M)%M;
        if(ans<0)ans+=M;
        
    }
    // ans+=n-1;
    // if(n&1)ans += (((((n+1)/2)%M)*(n%M))%M);
    // else ans += (((((n+1))%M)*((n/2)%M))%M);
    // ans = ans%M;
    if(ans<0)ans+=M;
    // cout<<ans;
    return ans;

}

ll divsum(ll n){
    ll sq=sqrt(n);
    ll ans = 0;
    for(ll i=1; i<=sq; i++){
        if(n%i==0){
            ans+=i;
            if(n/i!=i){
                ans+=n/i;
            }
        }
        ans = ans%M;
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    ///cin>>t;
    // while(t--)solve();

    ll ans = 0;
    ll nn = 1e12;
    ll i = 1;
    for(i; i<=nn; i++){
        ans = (ans + divsum(i)%M)%M;
        if(ans==solve(i)){
            // cout<<i<<" "<< solve(i)<<" "<<ans<<endl;
            continue;
        }
        else {cout<<endl<<i<<" "<< solve(i)<<" "<<ans<<endl;return 0;}
    }
    cout<<"all passed";


    return 0;
}
