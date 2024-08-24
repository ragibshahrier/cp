#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; ii<n; ii++)
#define gp " "

//bit_manupulation
#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define resetbit(x,n) (x=(x&(~(1LL<<n))))

// #define DEBG

#define debug(n)
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#endif

#define fastcin() ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;


//----------------------CODE STARTS HERE-------------------




void preprocessing(){

}

void solve(){
    int n;
    cin>>n;
    vll a(n);
    ll avg = 0;
    vll ans;
    ll maxi = 0 ;
    ll mini = inf;
    bool f = 0;
    rep(i,0,n){
        cin>>a[i];
        maxi = max(a[i],maxi);
        mini = min(a[i],mini);
        if(a[i]>0)f=1;
    }
    if(f==0){
        cout<<0<<endl<<endl;return;
    }
    avg = (maxi+mini)/2;
    ans.push_back(avg);
    rep(j,0,40){
    debug(avg)
        ll tempavg = 0;
        maxi = 0;
        mini = inf;
        f = 0;
        rep(i,0,n){
            a[i] = abs(avg - a[i]);
            maxi = max(a[i],maxi);
            mini = min(a[i],mini);
            //tempavg+=a[i];
            debug(a[i])
            if(a[i]>0)f=1;
        }
        if(f==0){
            
            break;
        }
        tempavg/=n;
        avg = (maxi+mini)/2;
        ans.push_back(avg);

    }
    if(f==1){cout<<-1<<endl;return;}
    cout<<ans.size()<<endl;
    for(auto el: ans){
        cout<<el<<" ";
    }
    cout<<endl;


}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
