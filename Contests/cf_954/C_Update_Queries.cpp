#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define rep(ii,n) for(int ii=0; i<n; i++)
#define debug(n) cout<<n<<endl;

void solve(){
    int n,m;
    cin>>n>>m;

    string s, c,ans;
    cin>>s;
    map<int,int> mp;
    vi indi(m);
    rep(i,m){
        cin>>indi[i];
        mp[indi[i]-1]++;
    }
    cin>>c;
    sort(c.begin(), c.end());
    /*
    int ii=0, jj=0;
    for(auto ch:s){
        if(mp[ii]==0){
            ans.push_back(ch);
        }else{
            ans.push_back(c[jj]);
            jj++;
            mp[ii]--;
        }
        ii++;

    }
    cout<<ans<<endl;

    */
}



 
int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}