#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define rep(ii,n) for(int ii=0; i<n; i++)
#define debug(n) cout<<n<<endl;

int fa(int a, int b, int c, int d){
    return (abs(a-d)+abs(b-d)+abs(c-d));
}


void solve(){
    int x1,x2,x3;
    cin>>x1>>x2>>x3;
    int mini=100;
    for(int i=0; i<=12; i++){
        mini=min(mini,fa(x1,x2,x3,i));
    }
    cout<<mini<<endl;
    
}



 
int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
