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

int mcount2(int x, multiset<int>ms){
    auto it = ms.find(x);
    if(it!=ms.end() && (++it)!= ms.end()){
        
        if(*it==x)return 1;
    }return 0;
}

ll poss(int init, int x, multiset<int>&ma, multiset<int>&mb){
    debug(x)
    debugc(ma)
    if(mb.find(x)!=mb.end()){
        ma.erase(ma.find(x));
        mb.erase(mb.find(x));
        return 1;
    }
    if(ma.find(x+1)!=ma.end()){
        ma.erase(ma.find(x+1));
        ma.erase(ma.find(x));
        ma.insert(x+x+1);
        if(poss(init, x+x+1, ma, mb)){
            return 1;
        }
        ma.erase(ma.find(x+x+1));
        ma.insert(x+1);
        ma.insert(x);
    }
    if(mcount2(x,ma)){
        ma.erase(ma.find(x));
        ma.erase(ma.find(x));
        ma.insert(x+x);
        if(poss(init,x+x, ma, mb)){
            return 1;
        }
        ma.erase(ma.find(x+x));
        ma.insert(x);
        ma.insert(x);
    }
    if(ma.find(x-1)!=ma.end()){
        ma.erase(ma.find(x-1));
        ma.erase(ma.find(x));
        ma.insert(x+x-1);
        if(poss(init, x+x-1, ma, mb)){
            return 1;
        }
        ma.erase(ma.find(x+x-1));
        ma.insert(x-1);
        ma.insert(x);
    }
    return 0;
}

void solve(int testcases){
    int n,m;
    cin>>n>>m;
    vi a(n);
    vi b(m);

    get_vector(a);
    get_vector(b);
    
    

    multiset<int>mb(All(b));
    // rep(i,0,m){
    //     bm[b[i]]++;

    // }
    multiset<int>ma(All(a));
    // debugc(ma)
    // debugcc(bm)
    // debug(bm.size())

    int i = 0;
    while(ma.size()>mb.size() && mb.size()>0){
        int y = *mb.begin();
        debugc(mb)
        if(ma.find(y)!=ma.end()){
            ma.erase(ma.find(y));
            mb.erase(mb.find(y));
            i++;
            continue;
        }
        if((y&1)&&y>1){
            int u = y/2;
            int v = y/2+1;
            mb.erase(mb.find(y));
            mb.insert(u);
            mb.insert(v);
        }else if(!(y&1)){
            int u = y/2;
            int v = y/2;
            mb.erase(mb.find(y));
            mb.insert(u);
            mb.insert(v);
            
        }else{
            break;
        }

        i++;



    }



    if(ma==mb){
        cout<< "Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }





}

int32_t main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
