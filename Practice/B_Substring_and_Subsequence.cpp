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
    string a,b;
    cin>>a>>b;
    int ans = a.length()+b.length();
    for(int i=0; i<b.length(); i++){
        int j=i;    
        for(int k=0; k<a.length() && j<b.length();){
            if(b[j]!=a[k]){
                k++;
            }else{
                j++;k++;
            }
        }
        int temp = (i+a.length()+b.length()-j);
        ans = min(ans, temp);
    }
    cout<<ans<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
