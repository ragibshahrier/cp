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




void preprocessing(){

}

int check(vll& a, ll mon, ll m){
    ll bt = 0;
    for(auto el:a){
        if(el<=mon){
            bt++;
            mon-=el;
        }
    }
    if(bt>m)return 1;
    if(bt<m)return 0;
    return 0;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vll a(n);
    get_vector(a);
    ll sum = 0;
    rep(i,0,n)if(a[i]==0)sum++;
    if(m==n){
        cout<<"Richman"<<endl;return;
    }
    m-=sum;
    if(m<0){
        cout<<"Impossible"<<endl;return;
    }
    vll aa;
    rep(i,0,n){
        if(a[i]){
            aa.push_back(a[i]);
        }
    }

    ll ans = 0;
    rep(i,0,m){
        ans += aa[i];
    }
    ans += *min_element(aa.begin()+m, aa.end())-1;
    if(ans<0 || check(aa,ans,m)!=0){
        cout<<"Impossible"<<endl;
    }else{
        cout<<ans<<endl;
    }

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
