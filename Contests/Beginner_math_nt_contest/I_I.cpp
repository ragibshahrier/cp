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

bool isequal(list<ll>& l){
    ll x = *(l.begin());
    for(auto el:l){
        if(el!=x){
            return false;
        }
    }
    return true;
}


void solve(){
    ll n;
    vector<ll>v;
    ll count =INT_MAX;
    cin>>n;
    rep(i,0,n){
        ll x;
        cin>>x;
        v.push_back(x);
    }
    if(n==1){
        cout<<0<<endl;return;
    }
    ll sum = 0;

    rep(i,0,n){
        bool f = 1;
        sum+=v[i];
        debug(sum)
        ll tempcount=i;
        debug(tempcount)
        ll tempsum=0;
        int start=i+1;
        for(int j=i+1; j<n; j++){
            tempsum+=v[j];
            if(tempsum>sum){
                f=0;
                break;
            }else if(sum==tempsum){
                tempsum=0;
                tempcount += j-start;
                start = j+1;
            }
        }
        debug(tempsum)
        if(sum==tempsum || tempsum==0)count = min(count, tempcount);
    }
    cout<<count<<endl;
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
