#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
 
typedef long long ll;
 
#define int long long
 
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
#define pow2(i) (1LL<<i)
#define bitcnt(x) ((sizeof(x) <= sizeof(int)) ? (32 - __builtin_clz(x)) : (64 - __builtin_clzll(x)))

// #define DEBG

#define debug(n)
#define debugc(a)
#define debugcc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<'{'<<gp<<el.ff<<','<<el.ss<<gp<<'}'<<gp;}cout<<']'<<endl;
#endif

#define fastcin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'


#define All(a) a.begin(),a.end()
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}


const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;
const ll N = 2e5 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

int absi(int x){
    if(x<0)return -x;
    return x;
}

pi getfrac(int xx, int yy){
    //x/y
    int dx = yy;
    int dy = xx; 
    if((dy>0 && dx<0) || (dx>0 && dy<0)){
        dx = absi(dx);
        dy = -absi(dy);
    }
    else{
        dx = absi(dx);
        dy = absi(dy);
    }
    int ddx = dx, ddy = dy;
    int x = __gcd(absi(ddx),absi(ddy));
    dx /= x;
    dy /= x;
    return {dy,dx};
}

pi  getm(pi a, pi b){
    int dy = -a.ss+b.ss;
    int dx = -a.ff+b.ff;
    // debug(dx)
    // debug(dy)
    if((dy>0 && dx<0) || (dx>0 && dy<0)){
        dx = absi(dx);
        dy = -absi(dy);
    }
    else{
        dx = absi(dx);
        dy = absi(dy);
    }
    int ddx = dx, ddy = dy;
    int x = __gcd(absi(ddx),absi(ddy));
    dx /= x;
    dy /= x;

    return {dy,dx};
}

void solve(int testcases){
    int n;
    cin>>n;
    int a[1007];
    rep(i,0,n){
        cin>>a[i];
    }  
    pi init = getm({1,a[0]}, {2, a[1]});
    int f = 1;
    rep(i,1,n-1){
        if(init!=getm({i+1, a[i]}, {i+2, a[i+1]})){
            f = 0;
            break;
        }
    }
    if(f){
        cout<<"No"<<endl;
        return;
    }
    // debug(1)
    map<pair<pi,pi>,set<int>>mp;
    map<pi,set<int>>mp2;

    rep(i,0,n){
        rep(j,i+1,n){
            pi mm = getm({i+1,a[i]}, {j+1, a[j]});
            // cout<<mm.ff<<" "<<mm.ss<<endl;
            pi nn = getfrac(mm.ss*(a[i])-mm.ff*(i+1) , mm.ss);
            auto& it = mp[{mm,nn}];
            auto& it2 = mp2[mm];

            
            it.insert(i+1);
            it.insert(j+1);
            
            it2.insert(i+1);
            it2.insert(j+1);
        }
    }
    // debug(mp.size());
    // map<pi,int>mp3;
    // for(auto& el:mp2){
    //     mp3[el.ff] = el.ss.size();
    // }

    for(auto& el:mp){
        // cout<<el.ff.ff<<" "<<el.ff.ss<<endl;
        int x = el.ss.size();
        // int y = mp3[el.ff];
        debugc(el.ss)
        if(x==n){
            // cout<<el.ff.ff<<" "<<el.ff.ss<<endl;
            cout<<"Yes"<<endl;
            return;
        }else if(x==n-1){
            cout<<"Yes"<<endl;
            return;

        }
    }
    cout<<"No"<<endl;


}

int32_t main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
