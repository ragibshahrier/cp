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

map<tuple<int,int,int>, ll>m; 

void func(ll& sum, vector<ll> tt, int n, int x){
    debug(tt[0])
    debug(tt[1])
    debug(tt[2])
    debug(n)
    debug(x)
    if(tt[0]+tt[1]+tt[2]>x){
        return;
    }
    if(tt[0]*tt[1] + tt[1]*tt[2] + tt[2]*tt[0] > n){
        return;
    }
    auto it = m.find({tt[0], tt[1], tt[2]});
    if(it!=m.end()){
        return;
    }
    if(tt[0]==tt[1]==tt[2])sum++;
    else if(tt[0]==tt[1] && tt[1]!= tt[2])sum+=3;
    else if(tt[1]==tt[2] && tt[0]!= tt[2])sum+=3;
    else sum+=6;
    debug(sum)
    func(sum, {tt[0]+1, tt[1]+1, tt[2]+1}, n, x);
    func(sum, {tt[0], tt[1]+1, tt[2]+1}, n, x);
    func(sum, {tt[0], tt[1], tt[2]+1}, n, x);
    m[{tt[0], tt[1], tt[2]}]=1;

}

void solve(){
    int n,x;
    cin>>n>>x;
    ll sum = 0;
    for(int i = 1; i<n && i<x; i++){
        for(int j = 1; j<n/i && j<x; j++){
            debug(i)
            debug(j)
            if(x-i-j>0 && (n-i*j)/(i+j)>0)sum += min(x-i-j, (n-i*j)/(i+j));
            debug(sum)

        }
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
