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
    int n,z;
    cin>>n>>z;
    ll totst = 0;
    multiset<int>s;
    rep(i,0,n){
        int x;
        cin>>x;
        s.insert(x);
        totst+=x*2;
    }
    if(totst<z){
        cout<<"Evacuate"<<endl;return;
    }
    // cout<<totst;
    auto it = s.end();
    it--;
    ll cnt=0;
    while(*it!=0 && z>0){
        z-=*it;
        cnt++;
        int temp = (*it)/2;
        s.erase(it);
        s.insert(temp);
        it = s.end();
        it--;
    }
    if(z>0){
        cout<<"Evacuate"<<endl;
    }
    else{
        cout<<cnt<<endl;
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
