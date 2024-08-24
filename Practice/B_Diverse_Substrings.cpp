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
#define debugcc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<(n)<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:(a)){cout<<el<<gp;}cout<<']'<<endl;
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:(a)){cout<<el.ff<<gp<<el.ss<<gp<<gp<<gp;}cout<<']'<<endl;
#endif

#define fastcin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'


#define All(a) a.begin(),a.end()
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}


const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

ll count (string& s, int n){
    
    vi occ(10);
    int nn= s.length();
    if(n>nn){
        return 0;
    }
    int maxi=0;
    int ans=0;
    int disct=0;
    unordered_map<int,int> mp;
    rep(i,0,n){
        mp[occ[s[i]-'0']]--;
        occ[s[i]-'0']++;
        if(occ[s[i]-'0']==1){
            disct++;
        }
        debug(disct)
        debug(s[i])
        mp[occ[s[i]-'0']]++;
        maxi=max(maxi,occ[s[i]-'0']);
    
    }
    if(maxi<=disct){
        ans++;
    }
    debug(maxi)
    debug(disct)
    
    rep(i,n,nn){
        debug("")
        debug("")
        debug("")
        debug(i)
        debugcc(mp)
        debugc(occ)
        debug(s[i-n])
        debug(s[i])

        mp[occ[s[i-n]-'0']]--;
        debug(mp[occ[s[i-n]-'0']])

        occ[s[i-n]-'0']--;
        mp[occ[s[i-n]-'0']]++;
        debugcc(mp)
        debugc(occ)

        if(occ[s[i-n]-'0']==0){
            disct--;
        }
        mp[occ[s[i]-'0']]--;
        
        occ[s[i]-'0']++;
        mp[occ[s[i]-'0']]++;
        debugcc(mp)
        debugc(occ)

        if(occ[s[i]-'0']==1){
            disct++;
        }
        debug(disct)
        
        // mp[occ[s[i-n]-'0']]--;
        maxi=max(maxi,occ[s[i]-'0']);
        
        if(mp[maxi]<=0){
            maxi--;
        }
        debug(maxi)
        if(maxi<=disct){
            ans++;
        }
        
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll ans = 0;
    rep(i,1,min(n+1,101)){
        ans+=count(s,i);
    }
    cout<<ans<<endl;

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
