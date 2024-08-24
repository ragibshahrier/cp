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
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp; for(auto el:a){cout<<el<<" ";}cout<<gp<<']'<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

const int N = 2e5+7;

ll n,v;
vll t(N), a(N);
vector<ll>dp(N,-1);
set<ll>ss;
ll it=0;
ll bans=0;
ll cans=0;

ll func1(int i){
    if(i>n)return 0;
    if(dp[i]>=0)return dp[i];
    ll ans = 0;
    // int kicks=0;
    // auto itt=s.upper_bound(i);
    // while(itt!=s.end()){
    //     it++;
    //     ll el = *itt;
    //     // if(dp[ii]==-2)break;
    //     // if((n-i)-ans<=(el-i-1)){
    //     //     // dp[ii]=-2;
    //     //     break;
    //     // }
    //     if((t[el]-t[i])*v>=abs(a[el]-a[i])){
    //         s.erase(itt);
    //         ll tempans = func(el);
    //         ans = max(ans, tempans+1);
    //         bans = max(ans,bans);
    //         debug(ans)
    //         debug(tempans)
    //         debug(el)
    //         debug(i)
            
            
    //         //if(ans>((n-i)/2)+0)break;

    //     }
    //     debug(it)
    //     itt = s.upper_bound(el);
    // }
    for(int ii=i+1; ii<n+1;ii++){
        it++;
        auto el = ii;
        
        // if(dp[ii]==-2)break;
        if((n-i)-ans<=(el-i-1)){
            // dp[ii]=-2;
            break;
        }
        if((t[el]-t[i])*v>=abs(a[el]-a[i])){ 
            
            ll tempans = func1(el);
            ans = max(ans, tempans+1);
            cans = max(ans,cans);
            debug(ans)
            debug(tempans)
            debug(el)
            
            //if(ans>((n-i)/2)+0)break;

        }
        
    }

    

    return dp[i]=ans;
}

set<ll>sssss;
ll func(int i, set<ll>&sss){
    if(i>n)return 0;
    if(dp[i]>=0)return dp[i];
    ll ans = 0;
    // int kicks=0;
    list<ll>l;
    //auto ittt = sssss.upper_bound(i);
    // for(auto itt=ittt; itt!=sssss.end(); ){
    //     auto el = *itt;
    //     auto temp = itt;
    //     itt++;
    //     if((t[el]-t[i])*v<abs(a[el]-a[i])){
    //         sssss.erase(temp);
    //         l.push_back(el);
    //     }
    // }
    debugc(s)
    debug(i)
    //auto ssss=sssss;
    auto itt=sssss.upper_bound(i);
    while(itt!=sssss.end()){
        it++;
        ll el = *itt;
        // if(dp[ii]==-2)break;
        if((n-i)-ans<=(el-i-1)){
            // dp[ii]=-2;
            break;
        }
       if((t[el]-t[i])*v<abs(a[el]-a[i])){
            sss.erase(el);
            //sssss.erase(itt);
            l.push_back(el);
            //ssss.erase(el);
            ll tempans = func(el, sssss, sssss);
            ans = max(ans, tempans+1);
            bans = max(ans,bans);
            debug(ans)
            debug(tempans)
            debug(el)
            debug(i)
            
       }    
            //if(ans>((n-i)/2)+0)break;

        
        debug(it)
        itt = sssss.upper_bound(el);
    }
    //s.clear();
    
    for(auto el:l){
        sssss.insert(el);
    }
    

    

    return dp[i]=ans;
}

void solve(){
    cin>>n>>v;
    t[0]=0,a[0]=0;
    rep(i,1,n+1){
        cin>>t[i];
    }
    
    rep(i,1,n+1){
        cin>>a[i];
        if(abs(a[i])<= v*t[i])ss.insert(i);
    }
    //auto itt = s.begin();
    ll ans = func(0,ss, ss);
    // func1(0);
    cout<<bans;
    // cout<<cans;
    debug(it);


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
