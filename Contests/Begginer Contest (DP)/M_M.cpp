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


//==============================CODE STARTS HERE==============================//


int n;
vll c;
vector<vll> dpp(100004+3, vll(2,-2));
vll order;

void preprocessing(){

}

void revrs(int nn){
    swap(order[nn], order[nn+n]);
}

// bool cmp(pair<string,int>sp1, pair<string,int>sp2){
//     int x = min(sp1.ff.length(), sp2.ff.length());
//     rep(i,0,)
// }


ll func(int nn, vector<string>& vs, int i){
    if(nn==n){
        return 0;
    }
    debugc(order)
    
    if(dpp[nn][i]!=-2)return dpp[nn][i];
    
    ll ans = 1e15;
    if(nn==0){
        ll x = func(nn+1,vs,0);
        if(x!=-1){
            ans = min(ans, x);
        }
        debug(ans)
        // reverse(All(vs[nn+1]));
        revrs(nn+1);

        x = func(nn+1,vs,1);
        if(x!=-1){
            ans = min(ans,x+c[nn]);
        }
        debug(ans)
        // reverse(All(vs[nn+1]));
        revrs(nn+1);
        if(ans!=1e15)return dpp[nn][i]=ans;
        return -1;
    }
    debug(vs[nn])
    debug(vs[nn+1])
    if(order[nn]<=order[nn+1]){
        debug(nn)
        debug(i)
        ll x = func(nn+1,vs,0);
        if(x!=-1)ans = min(ans, x);
    }
    // reverse(All(vs[nn+1]));
    revrs(nn+1);
    if(order[nn]<=order[nn+1]){
        ll x = func(nn+1,vs,1);
        if(x!=-1)ans = min(ans,x+c[nn]);
    }
    // reverse(All(vs[nn+1]));
    revrs(nn+1);
    if(ans!=1e15)return dpp[nn][i]=ans;
    return -1;
}

void solve(){
    cin>>n;
    c.resize(n);
    get_vector(c);
    vector<string> vs(n+1);
    vector<pair<string,int>> vsr(n+1);
    rep(i,1,n+1){
        cin>>vs[i];
        vsr[i].ff = vs[i];
        vsr[i].ss = i;

    }
    rep(i,1,n+1){
        reverse(All(vs[i]));
        vsr.push_back({vs[i],-i});
        reverse(All(vs[i]));
        
    }
    sort(All(vsr));
    order.resize(2*n+1);
    map<int,int>mp;
    for(int i = 0; i<=2*n; i++){
        mp[vsr[i].ss]=i;
        debug(vsr[i].ff)
        debug(i)
    }
    for(int i = 0; i<=2*n; i++){
        if(vsr[i].ss>0){
            order[vsr[i].ss]=mp[vsr[i].ss];
        }else{
            order[-vsr[i].ss+n]=mp[vsr[i].ss];
        }
    }
    cout<<func(0, vs,0)<<endl;

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
