#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
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
    ll x,y,m;
    cin>>x>>y>>m;
    if(m<max(x,y)){
        cout<<0;return;
    }
    if((x)<(y)){
        x^=y;
        y=x^y;
        x^=y;
    }
    debug(x)
    debug(y)

    if(x<=0 && m>x){
        cout<<-1;return;
    }
    ll cnt=0;
    while(max(x,y)<m){
        if(y<0){
            cnt+= (-y)/x + (y%x!=0);
            y = (x - ((-y)%x))%x;

        }else{
            y=x+y;
            cnt++;
        }
        
        if((x)<(y)){
            x^=y;
            y=x^y;
            x^=y;
        }


    }
    cout<<cnt;


    

    



}



 
int main(){
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}
