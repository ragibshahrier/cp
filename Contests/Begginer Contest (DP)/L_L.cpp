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



string s;

void preprocessing(){

}
const int N = 1e5+3;

vll dpp(N,-1);

ll func(int n){
    if(n>=s.length()-1)return 1;
    if(dpp[n]!=-1)return dpp[n];
    if(s[n]=='u'&&s[n+1]=='u'){
        return dpp[n]=(func(n+1)+func(n+2))%M;
    }
    if(s[n]=='n'&&s[n+1]=='n'){
        return dpp[n]=(func(n+1)+func(n+2))%M;
    }
    return dpp[n]=(func(n+1))%M;

}

void solve(){
    cin>>s;
    bool f=0;
    for(auto c:s){
        if(c=='w'||c=='m')f=1;
    }
    if(f){
        cout<<0<<endl;return;
    }
    cout<<func(0)<<endl;

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
