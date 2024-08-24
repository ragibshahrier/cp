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
    int n,k;
    cin>>n>>k;
    vi l(n),b(n);
    vector<pair<int,ll>>song(n);
    rep(i,0,n){
        cin>>l[i]>>b[i];
        song[i].first = b[i];
        song[i].second = l[i];
    }
    sort(song.begin(), song.end(), greater<pair<int,int>>());
    
    ll ans = 0;
    ll lensum=0;
    multiset<ll> s;
    rep(i,0,n){
        ll tempans=ans;
        if(i<k-1){
            tempans = (lensum+song[i].second) * song[i].first;
            // ans+=song[i].first*song[i].second;
            lensum += song[i].second;
            s.insert(song[i].second);
        }
        else{
            tempans = (lensum+song[i].second) * song[i].first;
            s.insert(song[i].second);
            lensum += song[i].second;
            auto it = s.begin();
            lensum -= *it;
            s.erase(it);

            // ll x = song[i-1].first - song[i].first;
            


        }
        ans = max(ans, tempans);
        debug(ans)
        debug(tempans)

        
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
