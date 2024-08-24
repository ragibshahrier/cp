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

void solve(){
    int x,y,k;
    cin>>x>>y>>k;
    vi ansx;
    vi ansy;
    int nn=1e9-7;
    if(k&1){
        rep(i,0,k/2){
            ansx.push_back(nn-i);
            ansx.push_back(-nn+i);
            ansy.push_back(nn-i);
            ansy.push_back(-nn+i);
            
        }
        ansx.push_back(k*x);
        ansy.push_back(k*y);
    }else{
        int nnn=(k-2)/2;
        rep(i,0,nnn){
            ansx.push_back(nn-i);
            ansx.push_back(-nn+i);
            ansy.push_back(nn-i);
            ansy.push_back(-nn+i);
            
        }
        if(k*x-1==1){
            ansx.push_back(k*x-2);
            ansx.push_back(2);
        }else{
            ansx.push_back(k*x-1);
            ansx.push_back(1);

        }
        if(k*y-1==1){
            ansy.push_back(k*y-2);
            ansy.push_back(2);
        }else{
            ansy.push_back(k*y-1);
            ansy.push_back(1);

        }
        
    }
    rep(i,0,k){
        cout<<ansx[i]<<gp<<ansy[i]<<endl;
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
