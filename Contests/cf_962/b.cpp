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
    int n, k;
    cin>>n>>k;
    vector<vi> ans(n/k, vi(n/k));
    for(int i = 0; i<n; i++){
        string s ;
        cin>>s;

        for(int j = 0; j<n; j++){
            char x;
            x = s[j];
            int xx = x - '0';
            ans[i/k][j/k] = xx;
            debug(i)
            debug(xx)
            debug(i/k)
            debug(j/k)
            debug(ans[i/k][j/k])
            debug(n)

            
        }
        debug(i)
        debug(n)
    }
    debug(n/k)
    rep(ii,0,n/k){
        rep(jj,0,n/k){
            cout<<ans[ii][jj];
            debug(ans[0][0])

        }
        cout<<endl;
    }

}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
