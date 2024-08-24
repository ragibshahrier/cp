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

//#define DEBG

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
const ll N = 1e5 + 7;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

int n, a,b;

ll func(int ind, int prev, vi& pil, vvll& dpp){

    if(ind==n+1){
        return (prev+1)*b*1LL;

    }
    if(dpp[ind][prev]!=-1)return dpp[ind][prev];

    ll ans = 0;
    if(prev){
        if(pil[ind]){
            ans = b*2+a+func(ind+1, 1, pil,dpp);
        }else if(ind==n){
            ans = b*2+a*2+func(ind+1,0, pil,dpp);
        }
        else{
            ans = min(b*2+a+func(ind+1,1, pil,dpp), b*2+a*2+func(ind+1,0, pil,dpp));
        }
    }else{
        if(pil[ind]){
            ans = b*1+a*2+func(ind+1,1, pil,dpp);
        }else if(ind==n){
            ans = b*1+a+func(ind+1,0, pil,dpp);
        }
        else{
            ans = min(b*1+a*2+func(ind+1,1, pil,dpp),b*1+a+func(ind+1,0, pil,dpp));
        }
    }
    return dpp[ind][prev]=ans;
    

}

void solve(){
    
    cin>>n>>a>>b;

    vvll dpp(n+5, vll(2,-1));
    string s;cin>>s;
    vi pil(n+1);
    rep(i,0,n){
        if(s[i]=='1'){
            pil[i]=1;
            pil[i+1]=1;
        }
    }
    ll ans = 0;
    ans = func(1,0,pil,dpp);
    // if(pil[0]==1){
    //     ans=func(1,1, pil,dpp);
    // }else{
    //     ans = min(func(1,0,pil,dpp),func(1,1,pil,dpp));
    // }
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
