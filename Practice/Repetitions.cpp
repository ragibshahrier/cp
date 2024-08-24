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

//----------------------CODE STARTS HERE-------------------

void solve(){
    map<char,int> m;
    int ans=0;
    string s;
    cin>>s;

    rep(i, 0, s.length()){
        auto ch = s[i];
        if(m[ch]==0 || s[i-1]==ch){
            m[ch]++;
        }else{
            m[ch]=1;
        }
        ans=max(ans, m[ch]);

    }
    cout<<ans<<endl;


}

int main(){
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}
