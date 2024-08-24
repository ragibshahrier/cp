#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; i<n; i++)
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
    vi a(n), b(n);
    rep(i,0,n){
        cin>>a[i];
    }
    
    rep(i,0,n){
        cin>>b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i=0, j=0;
    int pa=0, pb=0;
    while(i<n && j<n){
        
        debug(a[i])
        debug(b[j])
        if(a[i]>b[j]){
            j++;
            pa++;
        }else{
            pb++;
            i++;j++;
        }
        debug(pa);
        debug(pb);
    }
    if(pa==pb)cout<<"Draw\n";
    else if(pa>pb)cout<<"Shihan\n";
    else cout<<"Sazid\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
