#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
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
#define endl '\n'


#define All(a) a.begin(),a.end()
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}


const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;
const ll N = 2e5 + 7;


//==============================CODE STARTS HERE==============================//

map<char,char>mp;
string s;
int n;

void preprocessing(){
    mp['R']='P';
    mp['P']='S';
    mp['S']='R';
}

ll dpp[N][2];

ll func(int ind, int chs){
    if(ind==n){
        return 0;
    }
    if(dpp[ind][chs]!=-1){
        debug(ind)
        debug(chs)
        debug(dpp[ind][chs])
        return dpp[ind][chs];
    }
    ll ans = inf;
    if(ind==0){
        // p.push_back(mp[s[ind]]);
        ans = func(ind+1, 0)+1;
        // p.pop_back();
        // p.push_back(s[ind]);
        ans = max(func(ind+1,1), ans);
        return dpp[ind][chs] = ans;
    }
    if(chs){
        if(s[ind-1]==mp[s[ind]]){
            ans = func(ind+1, 1);
        }else if(s[ind-1]==s[ind]){
            ans = func(ind+1,0)+1;
        }else{
            ans = func(ind+1, 0)+1;
            // p.pop_back();
            // p.push_back(s[ind]);
            ans = max(func(ind+1,1), ans);
        }
    }else{
        if(mp[s[ind-1]]==mp[s[ind]]){
            ans = func(ind+1, 1);
        }else if(mp[s[ind-1]]==s[ind]){
            ans = func(ind+1,0)+1;
        }else{
            ans = func(ind+1, 0)+1;
            // p.pop_back();
            // p.push_back(s[ind]);
            ans = max(func(ind+1,1), ans);
        }

    }
    debug(ind)
    debug(chs)
    debug(ans)
    return dpp[ind][chs] = ans;

}

void solve(){
    memset(dpp, -1, sizeof(dpp));
    cin>>n;
    // string s;
    cin>>s;
    // string p;
    // p.push_back(mp[s[0]]);
    // rep(i,1,n){
    //     if(mp[s[i]]==p[i-1]){
    //         p.push_back(s[i]);
    //     }else{
    //         p.push_back(mp[s[i]]);
    //     }
    // }
    // ll ans = 0;
    // rep(i,0,n){
    //     if(p[i]==mp[s[i]])ans++;
    // }
    // cout<<ans;
    cout<<func(0,0)<<endl;


}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
