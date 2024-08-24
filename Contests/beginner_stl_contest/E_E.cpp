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
    int n;cin>>n;
    vi l(n);
    rep(i,0,n){
        cin>>l[i];
    }
    map<int, pair<int,int>> m;
    ll ans=0, tempans=0;
    rep(i,0,n){
        debug(tempans)
        debug(m[l[i]].first)
        debug(m[l[i]].second)

        if(i+1 - m[l[i]].second <= tempans){
            ans = max(ans, tempans);

            // tempans=(i+1)-m[l[i]].second;
            tempans = i+1 - m[l[i]].second;
            m[l[i]].second = i+1;

        }
        else{
            debug(2)
            tempans++;
            ans = max(ans, tempans);
            m[l[i]].first++;
            m[l[i]].second=i+1;
        }
    }
    cout<<ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
