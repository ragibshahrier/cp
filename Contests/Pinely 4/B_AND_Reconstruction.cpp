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

//#define DEBG

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
    vll andi(n-1);
    rep(i,0,n-1){
        cin>>andi[i];
    }
    vll ans(n);
    for(int i=n-2; i>=0; i--){
        for(int j=0; j<32; j++){
            if(checkbit(andi[i],j)){
                setbit(ans[i],j);
                setbit(ans[i+1],j);
            }
        }
    }
    for(int i =0; i<n-1; i++){
        if((ans[i] & ans[i+1]) != andi[i]){
            cout<<-1<<endl;return;
        }
    }
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
