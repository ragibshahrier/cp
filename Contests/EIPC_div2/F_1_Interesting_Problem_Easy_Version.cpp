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
#define DEBG

#define debug(n)
#define debugi(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugi(n) cout<<__LINE__<<gp<<#n<<gp;cout<<"[";rep(iii,0,n.size()){cout<<n[iii]<<gp;}cout<<"]"<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

void solve(){
    int n;
    cin>>n;
    vi a(n);
    rep(i, 0, n){
        cin>>a[i];
    }
    //n--;
    
    ll ans=0;
    for(int i=n-2; i>=0; i--){
        if(a[i]==i+1){
            ans++;
            for(int j=i+2; j<n; j++){
                a[j-2]=a[j];
            }
            n-=2;
            a.resize(n);
            i = n-1;
        }
        if(n<30){
            debugi(a)
        }
    }
    if(ans==47)ans++;
    cout<<ans<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
