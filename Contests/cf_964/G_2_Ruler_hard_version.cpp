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
    bool done = 0;
    ll hi = 1000;
    ll lo =1;
    ll mid1 = lo+(hi-lo)/3;
    ll mid2 = lo+((hi-lo)/3)*2;

    while(hi-lo>1){
        mid1 = lo+(hi-lo)/3;
        mid2 = lo+((hi-lo)/3)*2;
        cout<<"? "<<mid1<<gp<<mid2<<endl;
        cout.flush();
        int y;
        cin>>y;
        if(y==(mid1*mid2)){
            lo=mid2+1;
        }else if(y==(mid1*(mid2+1))){
            lo=mid1+1;
            hi = mid2;
        }else if(y==((mid1+1)*(mid2+1))){
            hi=mid1;
        }
    }
    cout<<"? "<<lo<<gp<<hi<<endl;
    cout.flush();
    int y;
    cin>>y;
    if(y==lo*hi)cout<<"! "<<lo-1<<endl;
    if(y==(lo*(hi+1)))cout<<"! "<<hi<<endl;
    if(y==((lo+1)*(hi+1)))cout<<"! "<<lo<<endl;
    // cout<<"! "<<lo<<endl;
    cout.flush();


}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
