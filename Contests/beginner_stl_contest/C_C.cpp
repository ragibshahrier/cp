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
    int n, x;
    cin>>n>>x;
    multiset<ll> s;
    rep(i, 0, n){
        ll y;
        cin>>y;
        s.insert(y);
    }
    // int i=0, st=0, en=n-1;
    // int point = st;
    // ll sum = 0;
    ll ans=0;
    // while(i<n){
    //     if(sum+p[point]>x){
    //         ans++;
    //         if(point==st){
    //             point = en-1;
    //         }
    //     }
        

    // }
    debug(s.size());
    
    
    while(s.size()>1){
        auto ite = s.end();
        ite--;
        debug(*ite);
        auto its = s.begin();
        
        if((*its+*ite) <=x){
            ll temp1 = *its;
            ll temp2 = *ite;
            s.erase(its);
            s.erase(ite);
            ans++;
            debug(temp1)
            debug(temp2)
        }
        else{
            s.erase(ite);
            ans++;
        }

    }
    if(s.size()==1)ans++;
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
