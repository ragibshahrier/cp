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

const ll N = 1e5+7;

vi stick(N);

void preprocessing(){

}

void query(int l, int r){
    list<int> rng;
    rep(i,l-1,r){
        rng.push_back(stick[i]);
    }
    rng.sort();
    debugc(rng)
    int n = rng.size();
    int cnt = 0;
    auto it=rng.begin();
    it++;
    it++;
    int f = 2;
    for(; it!=rng.end();){
        debug((*it))
        if(it==rng.begin() || it==next(rng.begin(),1)){
            f++;
            it++;
            continue;

        }
        // auto it1 = it;
        // auto it2 = it1;
        // it1--;
        // it2--;
        // it2--;
        if((*it)<(*(prev(it,1)))+(*(prev(it,2)))){
            auto it2 = prev(it,2);
            auto it0 = it;
            auto it1 = prev(it,1);
            it++;
            debug((*it0))
            debug((*it1))
            debug((*it2))
            rng.erase(it0);
            debugc(rng)
            rng.erase(it1);
            debugc(rng)
            rng.erase(it2);
            debugc(rng)
            cnt++;
            f=0;
            continue;
        }
        it++;

    }
    if(cnt>=2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

void solve(){
    int n,q;
    cin>>n>>q;
    rep(i,0,n){
        cin>>stick[i];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        if(r-l+1>49){
            cout<<"YES"<<endl;
            continue;
        }
        query(l,r);
    }

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
