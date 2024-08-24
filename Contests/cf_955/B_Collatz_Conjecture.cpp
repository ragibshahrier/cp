#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; i<n; i++)
#define gp " "
//#define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif


void solve(){
    ll x,y,k;
    cin>>x>>y>>k;
    map<ll,pll>m;
    ll kin = k, xin=x, yin =y; 
    x++;k--;
    while(k>=0){
        if(x%y!=0 && k==0){
            break;
        }
        if(x%y==0){
            //if(k==kin)k--;
            x=x/y;
            
        }else if(k!=0){
            if(m[x].second>=2){
                k=k%m[x].first;
            }
            if(k>=y-(x%y)){
                k-=(y-(x%y));
                x+=(y-(x%y));
            }else{
                x+=k;
                k=0;
            }
        }
        debug(x)
        debug(k)
        debug(y)
        
        m[x].second++;
        m[x].first=k-m[x].first;
        
    }
    cout<<x<<endl;
    //cout<<(998244356/2);



}



 
int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
