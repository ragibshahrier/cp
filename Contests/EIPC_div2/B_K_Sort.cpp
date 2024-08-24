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
    int n;
    cin>>n;
    vll v(n), vn(n);
    rep(i, 0, n){
        cin>>v[i];
    }
    
    ll ex = 0, pay=0;
    rep(i, 1, n){
        if(v[i]<v[i-1]){
            vn[i]=v[i-1]-v[i];
            v[i]=v[i-1];
        }

    }
    sort(vn.begin(), vn.end());
    // rep(i, 0, n){
    //     cout<<vn[i]<<endl;
    // }
    ll mini=0;
    rep(i, 0, n){
        pay+=(vn[i]-mini)*1LL*((n-i) +1);
        mini+= (vn[i]-mini)*1LL;
    }

    cout<<pay<<endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
