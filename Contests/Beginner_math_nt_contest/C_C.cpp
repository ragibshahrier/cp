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

vi divisornum(N);

void solve(){
    
    int x;
    cin>>x;
    cout<<divisornum[x]<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    rep(i,1,N+1){
        for(int j=i; j<=N; j+=i){
            divisornum[j]++;
        }
    }
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
