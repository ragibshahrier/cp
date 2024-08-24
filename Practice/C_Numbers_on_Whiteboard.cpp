#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; i<n; i++)
#define gp <<" "<<
//#define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif


void solve(){
    int n;
    cin>>n;
    int jj=n, ii=n-2;
    cout<<2<<endl;
    if(n==2){
        cout<<1 gp 2<<endl;
        return;
    }
    rep(i, 0, n-1){
        if(i==1){
            cout<<n-1 gp n-1<<endl;
        }else{
            cout<<ii gp jj<<endl;
            ii--;jj--;
        }
    }


}



 
int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}