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
//#define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

void solve(){
    int n, m;
    cin>>n>>m;
    multiset<int>h;
    rep(i, 0, n){
        int x;cin>>x;
        h.insert(x);
    }
    vi t(m);
    rep(i, 0, m){
        cin>>t[i];
    }
    rep(i, 0, m){
        auto it = h.upper_bound(t[i]);
        if(it==h.begin()){
            cout<<-1<<endl;
        }
        else{
            it--;
            cout<<*it<<endl;
            h.erase(it);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
