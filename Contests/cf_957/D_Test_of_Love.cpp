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
    int n, m, k;
    cin>>n>>m>>k;
    string s;
    cin>>s;

    int swim=0;
    ll totswim=0;
    int i=0;
    bool croc = 0;
    bool can=1;
    for(i=0; i<s.length(); i++){
        debug(swim)
        debug(croc)
        if(s[i]=='C'){
            croc = 1;
            swim++;

        }if(s[i]=='W'){
            if(swim<m){
                croc=0;
            }
            swim++;
            if(m<=swim)totswim++;
            
        }if(s[i]=='L'){
            if(croc){
                if(swim>=m){
                    can = 0;
                    break;

                }
            }
            swim=0;
            croc = 0;
        }
        debug(swim)
        debug(croc)
        
    }
    // swim++;
    if(croc){
        if(swim>=m){
            can = 0;

        }
    }if(totswim>k){
        can=0;
    
    }
    if(can)cout<<"YES"<<endl;
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
