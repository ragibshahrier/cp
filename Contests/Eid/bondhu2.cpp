#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 

//#define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

void solve(){
    int n;
    cin>>n;
    vector<int> arr(200), arrb(200);
    for(int i=0; i<n; i++){
        char x;
        cin>>x;
        int y = x;
        arr[y]++;
        
    }
    int m;
    cin>>m;
    
    for(int i=0; i<m; i++){
        char x;
        cin>>x;
        int y = x;
        arrb[y]++;
        
    }
    // for(int i='a'; i<='z'; i++){
    //     cout<<arrb[i];
    // }
    // cout<<endl;
    int ans=INT_MAX;
    for(int i='a'; i<='z'; i++){
        if(arrb[i]){
            ans=min(ans, arr[i]/arrb[i]);
        }
    }
    cout<<ans<<"\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
