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

vll wgt(1e6+7);
vll cnct(1e6+7);

void solve(){
    ll n;
    cin>>n;
    ll ans=((n-1)/2)*((n-1)- (n-1)/2) + n + n-1;
    debug(ans)
    rep(i,0,n-1){
        cin>>cnct[i+2];
    }
    for(int i=n; i>=2; i--){
        if(cnct[i]==1){
            continue;
        }
        int from=i;
        int to=cnct[i];


        debug((n-1)-wgt[from]-1-wgt[to]-1)
        debug(wgt[to])
        debug(n-2 - (wgt[from]+1))
        debug((wgt[from]+1))
        debug(min((wgt[from]+1), n-2 - (wgt[from]+1)))

        
        if((n-1)-wgt[from]-1-wgt[to]-1 > wgt[to]){
            debug("1 if")
            ans+=1LL*min((wgt[from]+1), n-2 - (wgt[from]+1));
        }else if((n-1)-wgt[from]-1-wgt[to]-1 < wgt[to]){
            debug("2 if")
            ans-=1LL*min((wgt[from]+1), n-2 - (wgt[from]+1));
        }
        wgt[to]+=wgt[from]+1;
        debug(ans)
    }
    cout<<ans;


}

int main(){
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("output.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t=1;
    // cin>>t;
    while(t--)solve();
    // int n = 1e6;
    // rep(i,1,n){
    //     cout<<i<<" ";
    // }
    return 0;
}
