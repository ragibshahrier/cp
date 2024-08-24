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

void solve(){
    int n;
    cin>>n;
    vll a(n);
    ll evcnt = 0;
    ll maxi = 0;
    multiset<int>se,so;
    rep(i,0,n){
        cin>>a[i];
        if((a[i] & 1) == 0){
            evcnt ++;
            se.insert(a[i]);
        }else so.insert(a[i]);
        maxi = max(maxi,a[i]);
    }
    if(evcnt==0 || evcnt==n){
        cout<<0<<endl;return;
    }
    auto it1= se.end();it1--;
    auto it2= so.end();it2--;

    if(*it2 > *it1){
        cout<<se.size()<<endl;return;
    }
    ll add=*it2;
    for(auto el:se){
        if(el<add){
            add+=el;
        }
    }
    if(add> (*it1)){
        cout<<evcnt<<endl;return;
    }else{
        cout<<evcnt+1<<endl;
    }

    // if((maxi&1)==0){
    //     cout<<evcnt+1<<endl;
    // }else{
    //     cout<<evcnt<<endl;
    // }


}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
