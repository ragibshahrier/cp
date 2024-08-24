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


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(){
    ll  n,k;
    cin>>n>>k;
    vector<pll> a(n+1);
    ll sum = 0;
    ll tot;
    rep(i,1,n+1){
        cin>>a[i].ff;
        a[i].ss = i;
        sum+=a[i].ff;
        tot+=a[i].ff;
    }
    tot+=k;
    // ll avg = (sum+k)/n;
    // sum  = 0;
    // rep(i,1,n+1){
    //     if(a[i].ff<=avg){
    //         sum+=a[i].ff;
    //     }
    // }
    // avg = (sum+k)/n;
    // rep(i,1,n+1){
    //     if(a[i].ff<=avg){
    //         a[i].ff=avg;
    //         k-=(avg-a[i].ff);

    //     }
    // }
    // debug(1)
    // if(k>0){
    //     for(int i=1; i<n+1 && k>0; i++){
    //         if(a[i].ff==avg){
    //             a[i].ff++;
    //             k--;
    //         }
    //     }     
        
    // }
    sort(a.begin()+1,a.end());
    ll n_i;
    int i;
    ll mini;
    for(i=0; i<n; i++){
        if(k>=(a[i+1].ff-a[i].ff)*(i)){
            k-=((a[i+1].ff-a[i].ff)*(i));
        }else{
            n_i = n-(i-(k%i));
            mini = a[i].ff+(k/i);
            debug(mini)
            k=0;
            break;
        }
    }
    debug(k)
    if(i==n){
        n_i= (k%n!=0)? (k%n) : 0;
        mini = a[n].ff+(k/n);
    }
    debug(mini)
    debug(n_i)

    // ll mini = a[1].ff;
    // int i = 1;
    // for(i=2; i<n+1; i++){
    //     if(mini<a[i].ff){
    //         break;
    //     }

    // }
    // i--;
    ll ans = mini*n+(n_i)-(n-1);
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
