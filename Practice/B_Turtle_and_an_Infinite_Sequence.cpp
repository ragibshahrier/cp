#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define vi vector<int>
//#define rep(ii,n) for(int ii=0; i<n; i++)


ll lcm(ll LCM, ll a){
    return (LCM*a)/__gcd(LCM,a);
}

void binarr(vector<int>& a, ll m){
    for(int i=0; i<=37; i++){
        a.push_back(m&1);
        m>>=1;

    }
}



void solve(){
    ll n, m, n1=0, a1=0, b1=0;
    cin>>n>>m;
    ll a=(n>m)?(n-m):0, b=n+m;
    vector<int>bina, binn, binb, binans(40);
    binarr(bina, a);
    binarr(binn, n);
    binarr(binb, b);
    for(int i=0; i<=35; i++){
        if(binn[i] || bina[i] || binb[i]){
            binans[i]=1;
        }else{
            if(n1-a1!=n-a || b1-n1!=b-n){
                binans[i]=1;
            }
        }
        n1+=binn[i]<<i;
        a1+=bina[i]<<i;
        b1+=binb[i]<<i;
    }
    ll ans=0;
    for(int i=0; i<=34; i++){
        ans+=binans[i]<<i;
    }
    cout<<ans<<endl;



}


int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
