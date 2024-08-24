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


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

bool ison(int t, int k){
    if()
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>p(n);
    for(int i = 0; i<n; i++){
        cin>>p[i];
    }
    int lcd = 1;
    for(int i = 1; i<k*2; i++){
        lcd = (lcd*(i+1))/(__gcd(lcd, i+1));
    }
    for(int i = 1; i<)


}

int main(){
    fastcin();

    int tt=1;
    cin>>tt;
    preprocessing();
    while(tt--)solve();
    return 0;
}
