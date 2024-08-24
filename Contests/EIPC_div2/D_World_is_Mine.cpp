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
    int n;
    cin>>n;
    vi a(n);
    map<int, int> m1;
    set<int> s;
    map<int, set<int>>m2;
    rep(i, 0, n){
        cin>>a[i];
        m1[a[i]]++;
        s.insert(a[i]);

    }
    for(auto el: m1){
        m2[el.second].insert(el.first);
    }
    int turn = 1;
    ll al = 0;
    int alp=1;
    int bobp=1;
    ll ans = s.size();
    for(auto el:s){
        if(m1[el]+bobp-1-alp > 0){
            bobp++;
            alp++;
            ans--;
        }else{
            bobp++;
            
        }

    }
    cout<<ans<<endl;

    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
