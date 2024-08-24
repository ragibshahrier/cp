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
#define endl '\n'


#define All(a) a.begin(),a.end()
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}


const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;


//==============================CODE STARTS HERE==============================//



bool check(ll mid, vi& newi, vi& ons, int k){
    int n = newi.size();
    int y = upper_bound(All(newi),mid)-newi.begin();
    y=n-y;
    if(y>n/2)return 0;
    auto it = lower_bound(All(newi),mid);
    int x = it-newi.begin();
    // int x = 1;
    debug(1)
    if(x<=(n-1)/2)return 1;
    int xx = x-(n-1)/2;
    auto it2 = lower_bound(All(ons),mid);
    int xxx = it2-ons.begin();
    debug(1)
    if(xxx<xx)return 0;
    int cnt=0;
    ll sum=0;
    while(cnt<xx){
        if(it2==ons.end()){
            it2--;continue;
        }
        if(*it2<mid){
            sum+=*it2;
            cnt++;
        }
        
        it2--;
    }
    debug(sum)
    if(mid*xx<=sum+k){
        return 1;
    }else{
    debug(1)
        return 0;
    }



}


void preprocessing(){

}

void solve(){
    debug(1)
    int n,k;
    cin>>n>>k;
    vi a(n);
    vi b(n);
    get_vector(a);
    get_vector(b);
    ll maxi=0;
    bool used=0;
    int maxin;
    rep(i,0,n){
        if(b[i]){
            if(a[i]+k>maxi){
                maxi = a[i]+k;
                maxin=i;
                used=1;
            }
        }else{
            if(a[i]>=maxi){
                maxi=a[i];
                maxin=i;
                used=0;
            }
        }
    }
    if(used)k=0;
    vi newi;
    vi ons;
    rep(i,0,n){
        if(i==maxin)continue;
        newi.push_back(a[i]);
        if(b[i])ons.push_back(a[i]);
    }
    sort(All(newi));
    sort(All(ons));
    int med=(newi.size()-1)/2;
    if(k==0 || ons.size()==0){
        cout<<maxi+newi[med]<<endl;return;
    }
    // int xx = ons.size()-1;
    debugc(ons)
    ll hi=max(ons[ons.size()-1]+k, newi[newi.size()-1]);
    ll lo = newi[med];
    ll mid = (lo+hi)/2;
    while(hi-lo>1){
        debug(mid)
        mid = (lo+hi)/2;
        if(check(mid, newi,ons,k)){
            lo=mid;
        }else{
            hi=mid-1;
            debug(hi)
        }
    }
    if(check(hi, newi,ons,k)){
        cout<<hi+maxi<<endl;
    }else{
        cout<<lo+maxi<<endl;
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
