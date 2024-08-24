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


#define DEBG

#define debug(n)
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp; for(auto el:a){cout<<el<<" ";}cout<<endl;
#endif

//----------------------CODE STARTS HERE-------------------


void func(int n,vector<int>& a){
    debugc(a)
    if(n==3){
        a[0]=1;a[1]=3;a[2]=2;return;
    }
    if(n==2){
        a[0]=1;a[1]=2;return;
    }

    func((n+1)/2, a);
    debugc(a)
    for(int i=0, j=(n+1)/2; i<(n+1)/2; i++){
        if(a[i]*2<=n){
            a[j]=a[i]*2;
            j++;
            debugc(a)
        }
    }
    for(int i = 0; i<(n+1)/2; i++){
        a[i]=a[i]*2-1;
    }
    

}


void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    func(n, a);

    debugc(a)

    vector<vi>mat(n, vi(n));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            mat[i][j]=(a[i]-1)*n + a[j];
        }
        
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<mat[i][j]<<" ";
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
