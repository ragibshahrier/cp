#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define int long long
#define vi vector<ll>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; ii<n; ii++)
#define gp " "
// #define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vi> arr(n+2, vi(m+2));
    vector<vi> arr2(n+2, vi(m+2));
    vector<vi> colsum(n+2, vi(m+2));
    vector<vi> matsum(n+2, vi(m+2));
    vi arrr(n+2);
    ll sum = 0;
    int mod = -1;
    int tip[2]={0,0};
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
            sum+=arr[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char x;
            cin>>x;
            arr2[i][j]=x-'0';
            tip[arr2[i][j]]+=arr[i][j];
    // debug(tip[0])
    // debug(tip[1])
        }
    }
    debug(tip[0])
    debug(tip[1])
    if(tip[0]==tip[1]){
        cout<<"YES\n";
        return;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            colsum[i][j]=colsum[i-1][j]+arr2[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            matsum[i][j]=matsum[i][j-1]+colsum[i][j];
            debug(i)
            debug(j)
            debug(matsum[i][j])
        }
    }
    for(int i = k; i<=n; i++){
        for(int j = k; j<=m; j++){
            int areasum = matsum[i][j]-matsum[i-k][j]-matsum[i][j-k]+matsum[i-k][j-k];
            debug(sum)
            debug(areasum)
            debug(k)
            //debug(sum%abs(k*k-2*areasum))
            if((k*k-2*areasum)!=0){
                if(abs(tip[0]-tip[1])%abs(k*k-2*areasum)==0){
                    debug(1)
                    cout<<"YES\n";
                    return;
                }
                // debug(mod)
                // int x = (abs(tip[0]-tip[1])%abs(k*k-2*areasum));
                // debug(x)
                // if(mod==-1){
                //     mod = abs(tip[0]-tip[1])%abs(k*k-2*areasum);
                // }
                // else{
                //     if((abs(tip[0]-tip[1])%abs(k*k-2*areasum))%mod == 0){
                //         mod = abs(tip[0]-tip[1])%abs(k*k-2*areasum);
                //     }
                //     else{
                //         debug(1)
                //         cout<<"YES\n";
                //         return;

                //     }
                // }
            }
            debug(1)
            arrr.push_back(abs(k*k-2*areasum));
        }
    }
    debug(1)
    vi gcdfrmbk(arrr.size()+2);
    for(int i = arrr.size(); i>=1; i--){
        gcdfrmbk[i]=__gcd(arrr[i-1],gcdfrmbk[i+1]);
    }
    vi gcdfrmfr(arrr.size()+2);
    for(int i = 1; i<=arrr.size(); i++){
        gcdfrmbk[i]=__gcd(arrr[i-1],gcdfrmbk[i-1]);
    }
    int hdiff= abs(tip[0]-tip[1]);
    for(int i = 1; i<=arrr.size(); i++){
        gcdfrmbk[i]=__gcd(arrr[i-1],gcdfrmbk[i-1]);
    }
    debug(1)
    for(int i = 1; i<=arrr.size(); i++){
    debug(1)
        int temp=__gcd(gcdfrmfr[i-1],gcdfrmbk[i+1]);
    debug(1)
    debug(temp)
    debug(arrr[i-1])
        if(temp!=0 && arrr[i-1]!=0 && (hdiff%arrr[i-1])%temp==0){
    debug(1)
            cout<<"YES\n";
            return;
        }
    debug(1)
    }


    cout<<"NO\n";


}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
