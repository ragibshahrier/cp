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

//bit_manupulation
#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define resetbit(x,n) (x=(x&(~(1LL<<n))))




// Debugging

// #define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

void solve(){
    int n;
    ll p,h;
    cin>>n>>p>>h;
    ll x=0;
    ll hh=h-1;
    for(int i=0; i<62; i++){
        if(checkbit((hh+(1LL<<i)),i+1)){
            setbit(x, i);
        }
    }
    debug(x)
    for(int i=0; i<n; i++){
        ll y = 1LL<<(n-i);
        debug(y)
        if(p<=y/2){
            if(checkbit(x,i)){
                cout<<'L';
                p=(y/2+1)-p;
            }else{
                cout<<'R';
            }
        }
        else{
            p=p-y/2;
            if(checkbit(x,i)){
                cout<<'R';
                p=(y/2+1)-p;
            }else{
                cout<<'L';
            }

        }

    }
    



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
