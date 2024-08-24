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
    int n, m;
    string s,f;
    cin>>n>>s>>m>>f;
    unordered_map<char, ll> mp, mp2;
    for(auto ch:f){
        mp2[ch]++;
    }
    for(auto ch:s){
        mp[ch]++;
    }
    ll ans = INT_MAX;
    
    for(auto el: mp2){

        ans = min(ans, mp[el.first] / el.second);
    }
    cout<<ans<<endl;
   // cout<<"runned";
    
    

}

int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}