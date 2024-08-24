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
    vector<vi>mat1(n,vi(m));
    vector<vi>mat2(n,vi(m));
    vector<vi>matdiff(n,vi(m));

    rep(i,0,n){
        rep(j,0,m){
            char x;
            int y;
            cin>>x;
            y = x-'0';
            mat1[i][j]=y;
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            char x;
            int y;
            cin>>x;
            y = x-'0';
            mat2[i][j]=y;
            matdiff[i][j]=((mat2[i][j]+3)-mat1[i][j])%3;
        }
    }
    // rep(i,0,n){
    //     rep(j,0,m){
    //         cout<<matdiff[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<ll>rowsum(n);
    vector<ll>colsum(m);
    rep(i,0,n){
        rep(j,0,m){
            
            rowsum[i]+=matdiff[i][j];
            colsum[j]+=matdiff[i][j];
        }
    }
    rep(i,0,n){
        if(rowsum[i]%3!=0){
            cout<<"NO"<<endl;return;
        }
    }
    rep(j,0,m){
        if(colsum[j]%3!=0){
            cout<<"NO"<<endl;return;
        }
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
