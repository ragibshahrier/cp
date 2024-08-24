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
// #define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


void solve(){
    int n, x;
    cin>>n>>x;
    unordered_map<ll,int, custom_hash>m;
    vector<pair<int,int>> v;
    rep(i,0,n){
        int t;
        cin>>t;
        if(t<x){
            v.push_back({t,i});
            m[x-t]=i+1;
            
        }

    }
    if(v.size()<3){
        cout<<"IMPOSSIBLE";return;
    }
    sort(v.begin(), v.end());
    auto it = v.end();
    it--;
    int maxi1 = it->first;
    debug(maxi1)
    it--;
    int maxi2 = it->first;

    ll cnt = 0;
    debug(v.size())
    for(int i = 0; i<v.size(); i++){
        cnt++;
        debug(v[i].first)
        for(int j=i+1; j<v.size() && x-(v[i].first+v[j].first) >=v[j].first && x-(v[i].first+v[j].first) <=maxi1; j++){

            cnt++;
            debug(cnt)
            debug(i)
            debug(j)
            int k=v[i].second+1;
            int l=v[j].second+1;
            debug(k)
            debug(l)
            if(m[1LL*v[i].first+v[j].first]!=0 && m[1LL*v[i].first+v[j].first]!=k && m[1LL*v[i].first+v[j].first]!=l){
                cout<<k<<" "<<l<<" "<<m[1LL*v[i].first+v[j].first];
                return;
            }
        }


        


















    }
    cout<<"IMPOSSIBLE";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
