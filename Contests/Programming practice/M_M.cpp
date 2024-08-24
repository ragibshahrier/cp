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


//==============================CODE STARTS HERE==============================//

bitset<20> keys;
int n,m,k;
ll cnt = 0;
vector<bitset<20>>tests;
vector<bool>testr;

void preprocessing(){

}


void func(int nn){

    if(nn<=n){
        keys.set(nn);
        func(nn+1);
        keys.reset(nn);
        func(nn+1);
        return;
    }
    rep(i,0,m){
        auto andd = tests[i]&keys;
        if(andd.count()>=k){
            if(testr[i]==0)return;
        }else{
            if(testr[i])return;
        }

    }
    cnt++;

}

void solve(){
    cin>>n>>m>>k;
    tests.resize(m);
    testr.resize(m);
    
    rep(i,0,m){
        int c;cin>>c;
        rep(j,0,c){
            int x;cin>>x;
            tests[i].set(x);
        }
        char y;cin>>y;
        if(y=='o'){
            testr[i]=1;
        }
    }
    func(1);
    cout<<cnt;



}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
