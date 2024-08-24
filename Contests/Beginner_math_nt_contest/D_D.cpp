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

const int N = 1e6+7;


vi hsh(N);


void solve(){
    int n;
    cin>>n;
    int maxi = 0;
    rep(i,0,n){
        int x;
        cin>>x;
        hsh[x]++;
    }
    for(int i = 1; i<=N; i++){
        bool f=0;
        for(int j = i; j<=N; j+=i){
            if(hsh[j]>1){
                maxi=max(i,maxi);
            }else if(hsh[j]>0 && f){
                maxi=max(i,maxi);
            }else if(hsh[j]>0){
                f=1;
            }
        }
    }
    cout<<maxi;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
