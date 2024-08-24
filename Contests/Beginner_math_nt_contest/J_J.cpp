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
#define debug(n) cout<<endl<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

void solve(){
    int a,b,q;
    cin>>a>>b;
    if(a>b){
        int temp = a;
        a=b;
        b=temp;
    }
    int d = a/__gcd(a,b);
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        ll k = r/b;
        ll validk = (k>=1)?((k-1)/d + 1):0;
        ll validnum1 = validk*b;
        if(k%d == 0){
            validnum1+= (r%b)+1;
        }
        k = (l-1)/b;
        validk = (k>=1)?((k-1)/d + 1):0;
        ll validnum2 = validk*b;
        if(k%d == 0){
            validnum2+= ((l-1)%b)+1;
        }
        debug(validnum2)
        debug(validnum1)
        ll ans = r-l+1 - (validnum1- validnum2);
        cout<<ans<<" ";
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
