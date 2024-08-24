#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; i<n; i++)
#define gp <<" "
//#define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

void solve(){
    string a,b;
    cin>>a>>b;

    vi vb(b.length());

    rep(i, 0, b.length()){
        vb[i]=-b.length()+i;
    }



}

int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
