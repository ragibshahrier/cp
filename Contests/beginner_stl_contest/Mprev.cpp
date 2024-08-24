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
    int n, m, k;
    cin>>n>>m>>k;
    vi v(n);
    vector<pair<int,int>> of(m), of2;
    map<int,int>mp;
    rep(i,0,n){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    
    double rat=0;
    int hi=INT_MAX;
    rep(i,0,m){
        cin>>of[i].first>>of[i].second;
        // if(1.0*of[i].first/of[i].second <= rat){
        //     if(1.0*of[i].first/of[i].second == rat){
        //         if(hi>of[i].first){
        //             hi = of[i].first;
        //         }
        //     }else{
        //         rat = 1.0*of[i].first/of[i].second;
        //         hi = of[i].first;
        //     }
        // }
        if(of[i].first<=k && mp[-of[i].first]<of[i].second){
            mp[-of[i].first]=of[i].second;
        }
    }
    //sort(of.begin(), of.end(), greater<pair<int,int>>());
    // rep(i,0,m){
    //     if(of[i].first==hi && 1.0*of[i].first/of[i].second<=rat){
    //         of2.push_back({of[i].first, of[i].second});
    //     }else if(of[i].first<hi){

    //     }

    // }
    

    auto it = mp.begin();
    
    bool f = 1;
    ll ans=0;
    rep(i,0,k){
        ans+=v[i];
    }

    while(it!=mp.end()){
        auto itt = it;
        ll tempans=0;
        int i=1;
        int kk=i;
        for(i=1; i<=k; i++){
            int j = k-i;
            debug(itt->first)
            while(((i-kk)%(-(itt->first)))==0 && k-i+1<-(itt->first) && itt!= mp.end()){
                itt++;
                kk=i;
            }
            if(itt!=mp.end()){
                if(((i-kk)%(-(itt->first)))<(-(itt->first))-itt->second){
                    tempans+=v[j];
                }

            }else{
                tempans+=v[j];
            }
            debug(tempans)
        }it++;

        ans = min(tempans, ans);
        debug(ans)
    }
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
