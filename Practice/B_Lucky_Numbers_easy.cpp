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


ll stringtonum(string s){
    ll n=0;
    int p10 = 1;
    for(int i=s.length()-1; i>=0; i--){
        debug(s[i])
        n+= (s[i]-'0')*p10;
        debug(n)
        debug(p10)
        p10*=10;
    }
    return n;
}

void fillstr(int st,  int left4, int left7, string& s){

}

void solve(){
    string s;
    int n=0;
    cin>>s;
    
    if((s.length()&1)==1){
        int x = s.length();
        rep(i,0,(x+1)/2){
            cout<<4;
        }
        rep(i,(x+1)/2, x+1){
            cout<<7;
        }
        return;
    }
    int x = s.length();
    string maxs;
    rep(i,0,(x)/2){
        maxs.push_back('7');
    }
    rep(i,(x)/2, x){
        maxs.push_back('4');
    }
    debug(stringtonum(maxs))
    debug(stringtonum(s))
    if(stringtonum(maxs)<stringtonum(s)){
        int x = s.length();
        rep(i,0,(x+2)/2){
            cout<<4;
        }
        rep(i,(x+2)/2, x+2){
            cout<<7;
        }
        return;
    }
    string ansstr;
    int left4=x/2;
    int left7 = x/2;
    for(int i=0; i<x; i++){
        if(s[i]<'4'){
            ansstr[i] = '4';
        }
        if(s[i]>'4')
    }



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}
