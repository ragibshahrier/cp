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
    string s;
    cin>>s;
    int cnt1=0;
    int cnt0=0;
    bool f=1;
    for(int i = 0; i<n; i++){
        if(s[i]=='1'){
            cnt1++;
            f=1;
        }else{
            if(f){
                cnt0++;
                f=0;
            }
        }
    }
    if(cnt0>=cnt1)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
