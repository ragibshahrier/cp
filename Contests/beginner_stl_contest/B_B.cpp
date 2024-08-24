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

void solve(){
    int n, m, k;
    cin>>n>>m>>k;

    vi a(n),b(m);
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,m){
        cin>>b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i=0, j=0;
    ll ans=0;
    while(i<n && j<m){
        if(abs(a[i]-b[j])<=k){
            i++;j++;ans++;
        }
        else if((a[i]>b[j])){
            j++;
        }else if(a[i]<b[j]){
            i++;
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
