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
    unordered_map<ll,pair<int,int>, custom_hash>m;
    vi v(n);
    rep(i,0,n){
        int t;
        cin>>t;
        v[i]=t;
        

    }
    rep(i,0,n){
        rep(j,i+1,n){
            
            m[x-v[i]-v[j]].first=i+1;
            m[x-v[i]-v[j]].second=j+1;
        }
    }
    rep(i,0,n){
        rep(j,i+1,n){
            int k = m[v[i]+v[j]].first;
            int l = m[v[i]+v[j]].second;
            if(m[v[i]+v[j]].first!=0 && (i+1)!= k && (j+1)!=k && (i+1)!=l && (j+1)!=l){
                cout<<i+1<<" "<<j+1<<" "<<k<<" "<<l;
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}
    // rep(i,0,n){
    //     rep(j,i+1,n){
    //         if(m[v[i]+v[j]]!=0 && m[v[i]+v[j]]!=i+1 && m[v[i]+v[j]]!=j+1){
    //             cout<<i+1<<" "<<j+1<<" "<<m[v[i]+v[j]];
    //             return;
    //         }
    //     }
    // }



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
