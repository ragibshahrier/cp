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
    string s1,s2;
    cin>>s1>>s2;
    bool f=1, ans = 1;

    rep(i,0,n){
        if(s1[i]=='0' && s2[i]=='1' && f==1){
            ans = 0;
            break;
        }if(s1[i]=='1'){
            break;
        }
    }
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
