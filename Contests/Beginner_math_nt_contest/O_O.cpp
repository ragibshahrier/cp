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
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#endif

//----------------------CODE STARTS HERE-------------------


const int N = 1e7+7;

// vi primes;
vi ert(N+7);
set<int>specprime;
vector<int>specprimev;



void solve(){

    int n;
    cin>>n;
    ll ans;
    auto it = upper_bound(specprimev.begin(), specprimev.end(), n);
    if(it==specprimev.end()){
        ans = specprimev.size();
    }else{
        ans = (int)(it-specprimev.begin());

    }
    cout<<ans<<endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=2; i<=N; i++){
        if(ert[i]==0){
            
            for(int j = i+i; j<=N; j+=i){
                ert[j]=1;
                
            }
        }
    }
    debug(ert[5])
    specprime.insert(2);
    rep(i, 1, 3600){
        int j;
        if(i&1)j=2;
        else j=1;
        for(;j<60;j+=2){
            ll x= i*i+j*j*j*j;
            if((x<N) && ert[x]==0){
                specprime.insert(x);
            }
        }
    }
    for(auto it = specprime.begin(); it!=specprime.end(); ){
        specprimev.push_back(*it);
        auto tempit = it;
        it++;
        specprime.erase(tempit);
    }
    debugc(specprimev);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
