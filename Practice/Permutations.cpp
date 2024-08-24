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
    int n;
    cin>>n;
    if(n==1){
        cout<<1;
        return;
    }
    if(n<=3){
        cout<<"NO SOLUTION";
        return;
    }
    int x=((n+1)/2)*2-1;
    while(x>=1){
        cout<<x gp;
        x-=2;

    }
    x= n-(n%2);
    while(x>=2){
        cout<<x gp;
        x-=2;
    }

}

int main(){
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
