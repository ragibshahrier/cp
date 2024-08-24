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
    ll a,b,c;
    cin>>a>>b>>c;
    ll tent = 0;
    tent+=a;
    if(b%3 == 0){
        tent+=b/3+ceil(c/3.0);
        cout<<tent<<"\n";
    }
    else{
        if(((b%3)+c)<3){
            cout<<-1<<"\n";
        }
        else{
            if(b%3 == 1){
                tent+=(b/3)+1+ceil((c-2)/3.0);
            }
            else{
                tent+=(b/3)+1+ceil((c-1)/3.0);
            }
            cout<<tent<<"\n";
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
