#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
 
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
#define pow2(i) (1LL<<i)

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


// struct Point{
//     int x;
//     int y;
//     void init(int a,int b){
//         x = a;
//         y = b;
//     }
// };

// struct tang{
//     int y;
//     int x;
//     void init(int a,int b){
//         y = a/__gcd(a,b);
//         x = b/__gcd(a,b);
//     }

// };

// struct cmp1{
//     bool operator()(Point a, Point b)const { 
//         if(a.x!=b.x)return a.x < b.x; 
//         else return a.y<b.y;
//     }
// };
// struct cmp2{
//     bool operator()(tang a, tang b) const { 
//         if(a.y!=b.y)return a.y < b.y; 
//         else return a.x<b.x;
//     }
// };


bool comp(pll a, pll b, pll c){
    ll dx1 = a.first-b.first, dy1 = a.second-b.second;
    ll dx2 = a.first-c.first, dy2 = a.second-c.second;
    ll g1 = __gcd(abs(dx1),abs(dy1)), g2 = __gcd(abs(dx2),abs(dy2));
    if(dx1 == 0){
        return (dx2 == 0 );
    }
    if(dy1 == 0){
        return (dy2 == 0);
    }
    int s1 = (dx1/abs(dx1))*(dy1/abs(dy1));
    int s2 = (dx2/abs(dx2))*(dy2/abs(dy2));
    return ((abs(dx1)/g1 == abs(dx2)/g2) && (abs(dy1)/g1 == abs(dy2)/g2) && (s1 == s2));
}

void preprocessing(){
    


}

pll tann(pll a , pll b){
    ll dx, dy;
    dx  = a.ff-b.ff;
    dy = a.ss-b.ss;
    if(dx==0){
        return {-1,0};
    }else if(dy==0){
        return {0,0};
    }
    int s1 = (dx/abs(dx))*(dy/abs(dy));
    ll g1 = __gcd(abs(dx),abs(dy));
    return {s1*abs(dy)/g1, abs(dx)/g1};


}

void solve(){
    int n;
    cin>>n;
    debug(n)
    set<pll>s;
    rep(i,0,n){
        pll p;
        ll x,y;
        cin>>x>>y;
        p = {x,y};
        s.insert(p);
    }
    if(n<=4){
        cout<<"YES";return;
    }
    map<pll, vector<pll>>tans;
    pll fr  = *s.begin();
    // s.erase(s.begin());
    ll mx = 0;
    for(auto pnt:s){
        if(fr == pnt){
            continue;
        }
        pll tan1 = tann(pnt,fr);
        tans[tan1].push_back(pnt);
        ll sz = tans[tan1].size();
        mx = max(mx, sz);
        
    }
    debug(mx)
    if(mx==1){
        tans.clear();
        auto it = s.begin();++it;
        pll fr2 = *it;

        for(auto pnt:s){
            if(fr2 == pnt || fr == pnt){
                continue;
            }
            pll tan1 = tann(pnt,fr);
            tans[tan1].push_back(pnt);
            ll sz = tans[tan1].size();
            mx = max(mx, sz);
            
        }

        if(mx == 1){
            s.erase(fr);
            s.erase(fr2);
        }else{
            s.erase(fr2);
        }
    }else{
        s.erase(fr);
    }
    if(mx>1){
        
        for(auto el:tans){
            ll sz = el.ss.size();
            if(sz==mx){
                for(auto ell:el.ss){
                    s.erase(ell);
                }
                break;
            }
        }

    }
    debugcc(s)
    if(s.size()<=2){
        cout<<"YES";return;
    }
    auto it = s.begin();it++;it++;
    for(;it!=s.end();){
        auto it3 = it;
        auto it2 = --it;
        auto it1 = --it;
        if(!comp(*it1, *it2, *it3)){
            cout<<"NO";return;
        }
        it = it3;
        it++;
    }
    cout<<"YES";return;


    

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
