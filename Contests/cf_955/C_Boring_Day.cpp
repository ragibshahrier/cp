#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; i<n; i++)
#define gp " "
//#define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif


void solve(){
    int n, l, r;
    ll ans=0, cmp=0;
    cin>>n>>l>>r;
    vll a(n), acc(n);
    auto iit = acc.begin();
    rep(i, 0, n){
        cin>>a[i];
    }
    acc[0]=a[0];

    rep(i, 1, n){
        acc[i]=acc[i-1]+a[i];
    }

    rep(i, 0, n){
        if(acc[i]-cmp<l){
            continue;
        }else if(acc[i]-cmp<=r){
            ans++;
            cmp=acc[i];
            iit = acc.begin()+(i+1);
        }else{
            auto it=lower_bound(iit, acc.begin()+i, acc[i]-r);
            if(it!=acc.begin()+i){
                if(acc[i]-*it>=l){
                    iit = iit = acc.begin()+(i+1);
                    cmp=acc[i];
                    ans++;
                }
                
            }
        }

    }
    cout<<ans<<endl;



}



 
int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
