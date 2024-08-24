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


int digitsum(ll n){
    ll rem, digsum = 0;
    while(n>0){
        rem = n%10;
        digsum += rem;
        n = n/10;
    }
    return digsum;
}

int digit(ll n){
    ll dig = 0;
    while(n>0){
        dig++;
        n=n/10;
    }
    return dig;
}

void preprocessing(){

}

void solve(){
    ll n,s;
    cin>>n>>s;
    ll dig = digit(n);
    ll digsum = digitsum(n);
    if(s == 162 || digsum == s){
        cout<<0<<"\n";
        return;
    }
    if(s == 1){
        cout<<(pow(10,dig))-n<<"\n";
        return;
    }
    
    while(digsum>s){
        if(dig == 1){
            cout<<10-n<<"\n";
            return;
        }
        if(dig == 2){
            
        }
    }

    

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
