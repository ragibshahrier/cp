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
const int N = 1e6+5;

vi hp(N);




void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        return;

    }
    vi disprm;

    int n1 = n;
    while(n1>1){
        disprm.push_back(hp[n1]);
        int x = hp[n1];
        while((n1%x) ==0){
            n1/=x;
        }
    }
    n1 = n;
    ll tot = n1;
    for(auto el:disprm){
        tot /= el;
        tot*=(el-1);
    }
    cout<<tot<<endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;

    for(int i = 2; i<=N; i++){
        if(hp[i]==0){
            for(int j=i; j<=N; j+=i){
                hp[j]=i;
            }
        }
    }

    cin>>t;
    while(t--)solve();
    return 0;
}
