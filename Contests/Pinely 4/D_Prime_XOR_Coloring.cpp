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

#define DEBG

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

// const int N = 2e5 + 7;
const int N = 100;

vi primes(N);
vll colors(N);


void preprocessing(){
    vi err(N,-1);
    rep(i,2,N){
        if(err[i]!=-1)continue;
        for(int j = i+i; j<N; j+=i){
            err[j]=1;
        }
    }
    rep(i,2,N){
        if(err[i]==-1)primes.push_back(i);
    }

    ll xors = 0;
    rep(i,1,N){
        xors^=i;

    }
    debug(xors)
    rep(i,0,N){
        
        colors[i] = xors;

    }

    for(auto prime : primes){
        //int arr[N];
        rep(i,1,10){
            if((prime^i) <N)colors[(prime^i)]^=i;
            // debug((prime^i))
        }
    }
    
}

void solve(){
    int n;
    cin>>n;
    int k = 1;
    map<ll, int>m;
    vi ans;
    rep(i,1,n+1){
        int x = m[colors[i]];
        debug(colors[i])
        debug(x)
        if(x==0){
            ans.push_back(k);
            m[colors[k]]=k;
            k++;
        }else{
            ans.push_back(x);
        }
    }
    cout<<k-1<<endl;
    for(auto el:ans){
        cout<<el<<" ";
    }
    cout<<endl;

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
