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
#define po2(n) (1LL<<n)


//#define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------


ll digits(ll x){
    ll ans = 0;
    while(x!=0){
        x/=10;
        ans++;
    }
    if(ans==0)ans++;
    return ans;
}

string numtostring(ll n){
    string s = "-C0000";
    int ii=5;
    while(n!=0){
        char x = (n%10)+'0';
        s[ii]=x;
        ii--;
        n/=10;

    }
    return s;
}

ll power2(int n){
    if(n<=61){
        return po2(n);
    }
    ll ans = 1e18;
    return ans;
}

void solve(){
    ll n;
    ll k;
    string s;
    cin>>s>>n>>k;
    cout<<s;
    k--;
    int i= n-1;
    ll ii=0;
    
    while(k!=0){
        if(k<=power2(i)){
            cout<<numtostring(ii);
            ii=0;
            k--;
        }else{
            k-=power2(i);
            ii++;
        }
        i--;
    }
    cout<<endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
