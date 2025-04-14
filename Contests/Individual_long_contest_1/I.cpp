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

#define DEBG

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

struct node{
    int f = 0;
    int s = 0;
    int id = 0;
};


bool comp1(node a, node b){
    if(a.f<b.f){
        return 1;
    }else if(a.f>b.f){
        return 0;
    }else{
        return a.s<b.s;
    }
}
bool comp2(node a, node b){
    if(a.s<b.s){
        return 1;
    }else if(a.s>b.s){
        return 0;
    }else{
        return a.f<b.f;
    }
}

void solve(int testcases){
    int n;
    cin>>n;

    vector<node>vn(n);
    vector<node>vn2(n);

    rep(i,0,n){
        int x,y;

        cin>>x>>y;

        vn[i].f = x;
        vn2[i].f = x;

        vn[i].s = y;
        vn2[i].s = y;

        vn[i].id = i+1;
        vn2[i].id = i+1;
    }

    sort(All(vn), comp1);
    sort(All(vn2), comp2);


    rep(i,0,n){
        if(i>0){
            if(vn[i].s<=vn[i-1].s){
                cout<<vn[i].id<<endl;return;
            }
        }
        if(i<n-1){
            if(vn2[i].f>=vn2[i+1].f){
                cout<<vn2[i].id<<endl;return;
            }
            
        }
        if((i>0) && (i<n-1)){
            if(vn[i+1].f-vn[i-1].s<=1){
                cout<<vn[i].id<<endl;return;
            }else if(vn2[i+1].f-vn2[i-1].s<=1){
                cout<<vn2[i].id<<endl;return;
            }
        }
    }

    cout<<-1<<endl;


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
