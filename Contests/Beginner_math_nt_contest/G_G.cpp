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


vector<bool>ispres;
const int N = 1e6+7;


void precompute(){

}


void solve(){
    int n;
    cin>>n;
    rep(i,0,n){
        int x;
        cin>>x;
        ispres[x]=1;
    }
    rep(i,2,N){
        if()
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
