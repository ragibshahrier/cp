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
    int n;
    cin>>n;
    vector<vll>mat(n,vll(n));
    rep(i,0,n){
        rep(j,0,n){
            cin>>mat[i][j];
        }
    }
    vll a(n);
    a[1]=sqrt((mat[0][1]*mat[1][2])/mat[0][2]);
    debug(a[1])
    a[0] = mat[0][1]/a[1];
    rep(i,2,n){
        a[i]=mat[0][i]/a[0];
    }
    for(auto el:a){
        cout<<el<<" ";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
