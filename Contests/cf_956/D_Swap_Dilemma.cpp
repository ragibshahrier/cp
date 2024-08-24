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

void solve(){
    int n;
    cin>>n;
    vi a(n),b(n);
    map<int,int>m;
    rep(i,0,n){
        cin>>a[i];
        m[a[i]]=i;

    }
    rep(i,0,n){
        cin>>b[i];
    }
    vi ad = a;
    vi bd = b;
    sort(ad.begin(), ad.end());
    sort(bd.begin(), bd.end());

    rep(i,0,n){
        if(ad[i]!=bd[i]){
            cout<<"NO"<<endl;return;
        }
    }
    int cnt=0;
    rep(i,0,n){
        if(a[i]!=b[i]){
            debug(a[i])
            debug(b[i])
            debug(m[a[i]])
            debug(m[b[i]])
            debug(a[m[b[i]]])
            m[a[i]]=m[b[i]];
            m[b[i]]=i;
            debug(a[i])
            debug(b[i])
            debug(a[m[b[i]]])

            debug(m[a[i]])
            debug(m[b[i]])
            swap(a[m[a[i]]],a[i]);
            cnt++;
        }
    }
    rep(i,0,n){
        if(a[i]!=b[i]){
            cout<<"NO"<<endl;return;
        }
    }
    if(cnt&1){
        cout<<"NO"<<endl;return;
    }
    cout<<"YES"<<endl;

    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
