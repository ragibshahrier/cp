#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; i<n; i++)
#define gp <<" "<<
//#define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif


void solve(){
    int n,ans=0;
    cin>>n;

    string en;
    string gr;

    cin>>en>>gr;

    rep(i,0,n){
        if(gr[i]=='0')continue;
        if(en[i]=='0'){
            ans++;
            en[i]='2';
        }else{
            if(i==0){
                if(en[i+1]=='1'){
                    ans++;
                    en[i+1]='2';
                }
            }
            else if(i==n-1){
                if(en[i-1]=='1'){
                    ans++;
                    en[i-1]='2';
                }
            }else{
                if(en[i-1]=='1'){
                    ans++;
                    en[i-1]='2';
                }else if(en[i+1]=='1'){
                    ans++;
                    en[i+1]='2';
                }
            }

        }
    }
    cout<<ans<<endl;





}



 
int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
