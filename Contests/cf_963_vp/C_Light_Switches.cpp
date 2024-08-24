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
    int n,k;
    cin>>n>>k;
    vll a(n,0);
    debug(1)
    vi mp2((k*2+7),0);

    // memset(mp2, 0, sizeof(mp2));
    int ffff=0;
    ll maxi = 0;
    rep(i,0,n){
        cin>>a[i];
        maxi = max(a[i],maxi);
        mp2[(a[i]% (k*2))]++;
        if(mp2[((a[i]%(k*2))+k)%(2*k)]!=0){
            ffff=1;
        }
    }
    if(n==1){
        cout<<a[0]<<endl;return;
    }
    debugc(mp2)
    debugc(a)
    if(ffff==1){
        // mp2.clear();
        debug("")
        debug("")
        debug("")
        debug("")
        debug("")
        debug("")
        debug("")
        debug("")
        cout<<-1<<endl;return;
    }
    // ll lo = maxi;
    // ll hi = maxi + 2*k-1;
    // ll mid = (hi+lo)/2;
    // while(hi-lo>1){
    //     mid = (hi+lo)/2;
    //     bool on=1;
    //     rep(i,0,n){
    //         if((mid-a[i])%(2*k) >= k){
    //             on=0;break;
    //         }
    //     }
    // }
    vi mp;
    // mp.clear();
    for(int i=0; i<2*k+7; i++){
        if(mp2[i]>0){
            mp.push_back(i);
        }
    }
    debugc(mp)
    

    ll cnt = 0;
    ll cmaxi = 0;
    ll ind=-1;
    ll sz = mp.size();
    auto it=mp.begin();
    ll temp = *it;
    ll indd=-1;
    debug(indd)
    it++;
    int fff=1;
    cnt=1;
    // for(; it!=mp.end();it++){
    //     if(*it == temp+1){
    //         // fff=1;
    //         if(ind==-1){
    //             ind=temp;
    //             indd=temp;
    //         }
    //         temp=*it;
    //         cnt++;

    //     }else{
    //         fff++;
    //         temp=*it;
    //         ind=-1;
    //         indd = *it;
    //     }

    //     // if(mp.find((i%(2*k)))!=mp.end()){
    //     //     if(ind==-1)ind = i;
    //     //     cnt++;
    //     // }else{
    //     //     if(cnt==sz){
    //     //         break;
    //     //     }
    //     //     cnt=0;
    //     //     ind=-1;
    //     // }
        
    // }
    if(mp.size()==1){
        cout<<maxi<<endl;return;
    }



    for(int i=1; i<mp.size()*2; i++){
        debug(i)
        debug(((abs(mp[(i+1)%(mp.size())]+2*k-mp[(i)%mp.size()]))%(2*k)-1))
        if((abs(mp[(i+1)%(mp.size())]+2*k-mp[(i)%mp.size()]))%(2*k)-1>=k){
        debug(i)
            indd=mp[(i)%mp.size()];
            sz=2*k-((abs(mp[(i+1)%(mp.size())]+2*k-mp[(i)%mp.size()])-1)%(2*k));
            debug(sz)
        }
    }




    debugc(mp)
    debug(ind)
    debug(mp.size())
    debug(fff)
    ll ans;
    // if(fff==1 || fff==2)
    if(indd!=-1){
        // indd+=(sz-1);
        debug(indd)
        indd%=(2*k);
        debug(maxi )
        debug((maxi%(2*k)) )
        ans = maxi+((indd+2*k)-(maxi%(2*k)))%(2*k);
        cout<<ans<<endl;
    }
    else cout<<-1<<endl;

    // mp.clear();
    // mp2.clear();





}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--){
        debug(t)
        solve();
    }
    return 0;
}
