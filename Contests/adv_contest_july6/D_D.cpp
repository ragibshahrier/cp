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


ll gcdd(vector<ll>v, set<ll>&s){
    ll ans = 0;
    for(auto el:v){
        ans = __gcd(el, ans);
    }
    ll x = sqrt(ans);
    for(int i = 1; i<=x; i++){
        if(ans%i==0){
            s.insert(i);
            s.insert(ans/i);
        }
    }
    return ans;
}
void solve(){
    ll w,l;
    cin>>w>>l;
    set<ll>s;
    gcdd({w,w-2,l-1},s);
    gcdd({w,w-1,l-1,l-2,},s);
    gcdd({w,w,l-2},s);
    gcdd({w-1,w-1,l,l-2},s);
    gcdd({w-1,w-1,l-1,l-1},s);
    gcdd({w-1,w-2,l-1,l},s);
    gcdd({w-2,w-2,l},s);
    
    cout<<s.size()<<" ";
    for(auto el:s){
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
