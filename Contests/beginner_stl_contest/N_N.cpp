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
    int n,m;
    cin>>n>>m;
    vector<pair<ll,int>> v1(n),v2(m);
    map<ll,int> mp;
    rep(i,0,n){
        cin>>v1[i].first;
        v1[i].second = i;
    }
    rep(i,0,m){
        cin>>v2[i].first;
        v2[i].second = i;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int i=0,j=0;
    int cnt=0;
    bool f=1;
    while(i<n && j<m){
       cout<<v1[i].second<<" "<<v2[j].second<<endl;
       cnt++;
       if(cnt==n+m-1)break;
       if(i==n-1){
        j++;
       } else if(j==m-1){
        i++;
       }else{
            if(f){
                i++;
                f=0;
            }else{
                j++;
                f=1;
            }

       }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
