#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; i<n; i++)
#define gp <<" "
// #define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__ gp<< #n gp<< n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

void solve(){
    int n;
    cin>>n;
    vi a(n), b(n);
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        cin>>b[i];
    }

    ll rta=0, rtb=0;
    ll nm = 0, np=0;
    ll ans;
    rep(i,0,n){
        //debug(i)
        if(a[i]>b[i]){
            rta+=a[i];
        }else if(a[i]<b[i]){
            rtb+=b[i];
        }else{
            if(a[i]<0){
                nm++;
            }
            if(a[i]>0){
                np++;
            }
        }
    }
    ll maxi = max(rta, rtb);
    ll mini = min(rta, rtb);

    if(np<= maxi-mini){
        mini+=np;
        np=0;
    }else{
        np-= maxi-mini;
        mini=maxi;
    }
    
    debug(maxi)
    debug(mini)
    debug(nm)
    if(nm <=maxi-mini){
        maxi-=nm;
        nm=0;
    }else{
        nm-=maxi-mini;
        maxi=mini;
    }
    

    if(np == nm){
        ans=min(maxi,mini);
    }
    if(np>nm){
        ans=mini+(np-nm)/2;
    }
    if(nm>np){
        ans=mini-(nm-np+1)/2;
    }

    cout<<ans<<endl;







    

}

int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
