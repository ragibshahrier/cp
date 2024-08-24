#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define vi vector<int>
//#define rep(ii,n) for(int ii=0; i<n; i++)


ll lcm(ll LCM, ll a){
    return (LCM*a)/__gcd(LCM,a);
}


void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(n+m+1),b(n+m+1), ans(n+m+1), type(n+m+1);
    //cout<<"HH";
    for(auto& i:a)cin>>i;
    for(auto& i:b)cin>>i;
    int n1=n,m1=m, bad=-1;
    ll totSk=0;
    for(int i=0; i<n+m; i++){
        if(n1 && m1){
            if(a[i]>b[i]){
                totSk+=a[i];
                type[i]=1;
                n1--;
                //if(n1==0 && a[i+1]>b[i+1])bad=i+1;
            }else{
                totSk+=b[i];
                type[i]=2;
                m1--;
                //if(m1==0 && a[i+1]<b[i+1])bad=i+1;
            }
        }else if(!n1){
            totSk+=b[i];
            type[i]=2;
            m1--;
            if(a[i]>b[i] && bad<0)bad=i;
        }else if(!m1){
            totSk+=a[i];
            type[i]=1;
            n1--;
            if(a[i]<b[i] && bad<0)bad=i;
        }
    }
    ans[n+m]=totSk;
    //cout<<bad<<endl;

    for(int i=0; i<n+m; i++){
        totSk=ans[n+m];
        if(bad==-1){
            if(type[i]==1)totSk+=a[n+m]-a[i];
            else totSk+=b[m+n]-b[i];
        }
        else if(i>=bad){
            if(type[bad]==1)totSk+=a[n+m]-a[i];
            else totSk+=b[n+m]-b[i];
        }else{
            if(type[i]!=type[bad]){
                if(type[i]==1){
                    totSk+=b[m+n]-b[bad]-a[i]+a[bad];
                }else{
                    totSk+=a[m+n]-a[bad]-b[i]+b[bad];

                }
                
            }
            else{
                if(type[i]==1){
                    totSk+=a[m+n]-a[i];
                }else{
                    totSk+=b[m+n]-b[i];

                }
                
            }
        }
        



        ans[i]=totSk;

    }
    for(auto el:ans)cout<<el<<" ";
    cout<<endl;


}


int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
