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

//bit_manupulation
#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define resetbit(x,n) (x=(x&(~(1LL<<n))))

//#define DEBG



#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

void solve(){
    ll n;
    cin>>n;
    list<ll>ans;
    ans.push_front(n);
    for(int i = 0; i<=61; i++){
        if(checkbit(n,i)){
            ll n1=n;
            resetbit(n1,i);
            if(n1>0)ans.push_front(n1);
        }
    }
    cout<<ans.size()<<endl;
    for(auto el:ans){
        cout<<el<<" ";
    }
    cout<<endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
