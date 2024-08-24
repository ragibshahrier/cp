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
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif




//----------------------CODE STARTS HERE-------------------



const ll M = 1e9+7;


ll binexp(ll a,ll b, ll m){
    ll ans = 1;
    ll aa=a;
    while(b!=0){
        
        if((b&1) == 1){
            ans=(ans*aa)%m;
            
        }
        aa=(aa*aa)%m;
        b=b>>1;
    }
    return ans;
}


ll modinv(ll n, ll m){
    return binexp(n,m-2,m);
}

void solve(){
    ll n;
    cin>>n;
    ll numofdiv = 1;
    ll sumofdiv = 1;
    ll numofdivM_1 = 1;
    ll proddiv = 1;
    ll nn = 1;
    bool hasodd=0;
    vector<pll> p(n);
    rep(i,0,n){
        cin>>p[i].first;
        cin>>p[i].second;
        if((p[i].second&1)){
            hasodd = 1;
        }
        
        numofdiv = (numofdiv*(p[i].second+1))%M;
        numofdivM_1 =  (numofdivM_1*(p[i].second+1))%(M-1);
        sumofdiv = (sumofdiv * ((binexp((p[i].first),p[i].second+1,M)-1)*modinv(p[i].first-1, M))%M)%M;
        nn = (nn * binexp(p[i].first, p[i].second, M))%M;

    }

   // ll modinv2 = (numofdivM_1)

    debug(numofdivM_1)
    //ll yyy = sqrt(nn);
    bool f = 1;
    if(hasodd == 0){
        nn = 1;
        rep(i,0,n){
            
            nn = (nn * binexp(p[i].first, p[i].second>>1, M))%M;

        }
    }else{
        numofdivM_1 = 1;
        rep(i,0,n){
            if((p[i].second & 1) && f){
                numofdivM_1 =  (numofdivM_1*((p[i].second+1)>>1))%(M-1);
                f=0;
            }
            else numofdivM_1 =  (numofdivM_1*(p[i].second+1))%(M-1);
            
        }

    }
    debug(nn)

    proddiv = binexp(nn, (numofdivM_1), M);
    
    debug(numofdivM_1)
    // rep(i,0,n){
    //     ll base = binexp(p[i].first, ((p[i].second * (p[i].second+1))/2)%(M-1), M)%(M);
    //     ll po = ((p[i].second)/2)%(M-1);
    //     po*=
    //     proddiv = (proddiv * binexp(base,po,M))%M;
    //     debug(po)

    // }
    cout<<numofdiv<<" "<<sumofdiv<<" "<<proddiv;

    //cout<<endl<< (10*modinv2)%(M-1);

    // ll xxxx = 6.4e13;
    // ll xxx=9770624070000;
    // cout<<endl<<xxxx%M;
    // cout<<endl<<(xxx%M);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    

    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}
