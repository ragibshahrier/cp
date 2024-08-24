#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; i<n; i++)
#define gp " ";
#define debug(n) cout<<__LINE__<<gp<<n<<endl;


void solve(){
    int a[2], b[2];
    cin>>a[0]>>a[1]>>b[0]>>b[1];
    int maxsi=0, maxei;
    if(a[0]<a[1]){
        maxsi=1;
    }
    if(b[0]<b[1]){
        maxei=1;
    }

    if(b[1-maxsi]>=b[maxsi]){
        cout<<"NO"<<endl;
    }else cout<<"YES"<<endl;

    //cout<<endl;



}



 
int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
