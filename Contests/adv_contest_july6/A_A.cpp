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


void insertion(list<ll>& looplen, int element){
    bool f = 1;
    for(auto it = looplen.begin(); it!=looplen.end(); ){
        auto itnow = it;
        it++;
        if(element % (*itnow) == 0){
            // looplen.erase(itnow);
            f=0;
            break;
        }
    }
    if(f)looplen.push_back(element);
}


void solve(){
    string s;
    ll d;
    cin>>s>>d;
    list<ll> looplen;
    ll count = 0;
    ll starter =0, loopcnt = 0;
    ll ans = 0;
    //bool f=0;
    rep(i,0,s.length()){
        count++;
        if(count == 1){
            starter = i;
            continue;
        }
        debug(count)
        debugc(looplen)
        if(!looplen.empty()){
            for(auto it = looplen.begin(); it!=looplen.end();){
                auto itnow = it;
                it++;
                auto el = *itnow;
                int x = count%el;
                if(x==0)x=el;
                if(s[i]!=s[starter+x-1]){
                    looplen.erase(itnow);
                }
            }
        }

        if(count<=d+1 && s[starter]==s[i]){
            insertion(looplen, count-1);
        }
        if(count>d && looplen.empty()){
            ans++;
            count = 1;
            starter = i;
            looplen.clear();

        }
        debug(count)
        debugc(looplen)

        // if(s[i]==s[starter+loopcnt] && !f){
        //     loopcnt++;
        // }else if(count<=d && !f){
        //     if(s[i]==s[starter]){
        //         loopcnt=1;
        //     }else{
        //         loopcnt=0;
        //     }
        // }else if(count==d+1 && s[i]==s[starter] && !f){
        //     loopcnt=1;
        // }else if(count>d && s[i]==s[i-d]){
        //     f=1;

        // }
        // else{
        //     ans++;
        //     count = 1;
        //     loopcnt = 0;
        //     starter = i;
        //     f=0;
        // }

    }
    ans++;
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
