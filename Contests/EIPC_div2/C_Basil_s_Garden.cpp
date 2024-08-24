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
// #define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

void solve(){
    int n;
    cin>>n;
    vll v(n);
    rep(i, 0, n){
        cin>>v[i];
    }
    // set<pair<int,int>>s;
    vll time(n);
    time[n-1]=v[n-1];
    ll hi = v[n-1];
    int hind = n-1;
    for(int i=n-2; i>=0; i--){
        // debug(1)
        // auto it = lower_bound(s.begin(), s.end(), make_pair(v[i], i));
        // debug(time[i])
        // debug(v[i])
        
        // debug((it==s.end()))
        // if(it == s.end()){
        //     time[i]=v[i];
        // }else{
        //     debug((it->first))
        // debug((it->second))
        //     time[i] = v[i]+(time[it->second]-v[i]+1);
        // }
        // debug(time[i])
        // debug(v[i])
        

        // s.insert(make_pair(v[i], i));


        time[i] = max(time[i+1]+1, v[i]);








    }
    cout<<time[0]<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
