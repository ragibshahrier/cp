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
    vi a(n+1);
    vi b(n+1);
    rep(i,0,n){
        cin>>a[i];
    }
    ll ans=0;
    rep(i,0,n){
        debug(a[i]);
        debug(b[i]);
        if((a[i]-b[i])>2)ans++;
        else if((a[i]-b[i])<=2 && (a[i]-b[i])>0){
            if(a[i]>2 && a[i+1]<=a[i]){
                a[i+1]=min(a[i+1], a[i]-2);
            }else if(a[i]<=2){
                b[i+1]+=2;
            }else if(a[i+1]==a[i]+1){
                a[i+1]-=2;
            }
            // if(a[i+1]<=a[i] && a[i+1]>b[i]){
            //     a[i+1]=b[i];
            // }else if(a[i+1]>a[i] && b[i]==0){
            //     b[i+1]=a[i];
            // }
            ans++;
        }
    }
    cout<<ans<<endl;

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
