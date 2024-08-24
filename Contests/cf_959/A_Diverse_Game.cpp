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
    int n,m;
    cin>>n>>m;
    vector<vi> a(n , vi(m));
    vector<vi> b(n , vi(m));
    rep(i,0,n){
        rep(j,0,m){
            cin>>a[i][j];
            if(a[i][j]==n*m)b[i][j]=1;
            else b[i][j]= (a[i][j]+1);
        }
    }
    if(n==1 && m==1){
        cout<<-1<<endl;
        return;
    }
    
    rep(i,0,n){
        rep(j,0,m){
            cout<< b[i][j]<<" ";
            
        }
        cout<<endl;
    }
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
