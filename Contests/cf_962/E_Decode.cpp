#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; ii<n; ii++)
#define gp " "

//bit_manupulation
#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define resetbit(x,n) (x=(x&(~(1LL<<n))))

// #define DEBG

#define debug(n)
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#endif

#define fastcin() ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;


//----------------------CODE STARTS HERE-------------------




void preprocessing(){

}

void solve(){
    // int n;
    // cin>>n;
    string s;
    cin>>s;
    unordered_map<ll, vector<int>> mp;
    unordered_map<ll, vector<ll>> mp2;
    ll sum = 0;

    vll psum(s.length()+1);
    mp[0].push_back(0);
    mp2[0].push_back(0);
    rep(i,0 , s.length()){
        if(s[i] == '1'){
            psum[i+1]= psum[i]+1;
        }else{
            psum[i+1]= psum[i]-1;
        }
        mp[psum[i+1]].push_back(i+1); 
        mp2[psum[i+1]].push_back(i+1); 
    }
    for(auto& el:mp2){
        debugc(el.ss)
        vll& v = el.ss;
        int n = s.length();
        int nn = v.size();
        for(int i = v.size()-1; i>0; i--){
            if(i!=nn-1){

                debug(n)
                v[i] = n - v[i] + 1;
                v[i]+=v[i+1];
                v[i] %=M;
                debug(v[i])
            }else{
                v[i] = n - v[i] + 1;
                v[i] %=M;
            }
        }
        debug(el.ff)
        debugc(el.ss)
    }
    debugc(psum)
    rep(i, 0, s.length()){
        auto it = mp.find(psum[i]);
        auto it2 = mp2.find(psum[i]);
        vll& vv = it2->ss;
        debugc(vv)
        if(it==mp.end())continue;
    debug(i)
        auto itt = lower_bound((it->ss).begin(), (it->ss).end(), i);
        int x_1 = itt - (it->ss).begin();
        int vsize = (it->ss).size();
        vi& v = it->ss;

        // rep(j, x_1 + 1, vsize){
        //     debug(vsize)
        //     debug(v[j])
        //     debug(v[x_1])
        // }
        debug(x_1)
        debug(vv[x_1+1])
        if(x_1 + 1 >= vv.size())continue;
        sum += ((i+1)*(vv[x_1+1]))%M;
        sum%=M;


    }
    cout<<sum<<endl;


}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
