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

int k;
vector<pair<int,int>> offs;
vector<ll> vacc(2050);
vector<ll> dp(2050,-1);

ll func(int remaining){
    debug(remaining)
    if(remaining<0)return 1e15;
    if(dp[remaining]!=-1)return dp[remaining];
    if(remaining==0){
        debug(0)
        return dp[remaining]=0;
    }
    ll ans=vacc[(k)]-vacc[k-remaining];
    debug(offs.size())
    for(int i=0; i<offs.size(); i++){
        if(offs[i].first<=remaining){
            debug(vacc[(k-remaining+offs[i].first-offs[i].second)])
            debug(vacc[(k-remaining)])

            ll tempans=func(remaining-offs[i].first)+vacc[(k-remaining+offs[i].first-offs[i].second)]-vacc[(k-remaining)];
            debug(tempans)
            ans = min(ans, tempans);


        }
    }
    debug(ans)
    return dp[remaining]=ans;
}


void solve(){
    
    int n, m;
    cin>>n>>m>>k;
    vector<pair<int,int>> of(m);
    vi v(n), v2(k);
    map<int,int>mp;
    rep(i,0,n){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    

    rep(i,0,m){
        cin>>of[i].first>>of[i].second;
        
        
        if(of[i].first<=k){
            if(mp[-of[i].first]<of[i].second)mp[-of[i].first]=of[i].second;
        }
    }
    for(auto el: mp){
        offs.push_back({-el.first, el.second});
    }

    for(int i=0; i<k; i++){
        v2[i]=v[k-i-1];
    }
    vacc[0]=0;
    rep(i, 1, k+1){
        vacc[i]=v2[i-1]+vacc[i-1];
    }
    ll ans = func(k);
    cout<<ans;


    


    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
