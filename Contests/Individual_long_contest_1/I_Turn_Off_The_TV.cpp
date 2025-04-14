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

struct node{
    int ff=0;
    int ss=0;
    int id=0;
};


void preprocessing(){

}

bool comp1(node a, node b){
    if(a.ff<b.ff){
        return 1;
    }else if(a.ff>b.ff){
        return 0;
    }else{
        return (a.ss<b.ss);
    }
}
bool comp2(node a, node b){
    if(a.ss<b.ss){
        return 1;
    }else if(a.ss>b.ss){
        return 0;
    }else{
        return (a.ff<b.ff);
    }
}

void solve(int testcases){
    int n;
    cin>>n;
    vector<node> v(n);
    rep(i,0,n){
        cin>>v[i].ff>>v[i].ss;
        v[i].id = i+1;

    }
    // cout<<2/0<<endl;
    vector<node> v2(n);
    rep(i,0,n){
        v2[i] = v[i];
    }

    // rep(i,0,n){
    //     cout<<v[i].ff<<gp<<v[i].ss<<gp<<v[i].id<<endl;
    // }
    // cout<<endl;
    // rep(i,0,n){
    //     cout<<v2[i].ff<<gp<<v2[i].ss<<gp<<v2[i].id<<endl;
    // }
    // cout<<endl;
    sort(All(v), comp1);
    sort(All(v2), comp2);

    // rep(i,0,n){
    //     cout<<v[i].ff<<gp<<v[i].ss<<gp<<v[i].id<<endl;
    // }
    // cout<<endl;
    // rep(i,0,n){
    //     cout<<v2[i].ff<<gp<<v2[i].ss<<gp<<v2[i].id<<endl;
    // }

    rep(i,0,n){
        if(i>0){
            if(v[i].ss<=v[i-1].ss){
                cout<<v[i].id<<endl;return;
            }
            
        }
        if(i<n-1){
            if(v2[i].ff>=v2[i+1].ff){
                cout<<v2[i].id<<endl;return;
            }

        }
        if(i>0 && i<n-1){
            if((v[i+1].ff-v[i-1].ss)<=1){
                cout<<v[i].id<<endl;return;
            }
        }
        if(i>0 && i<n-1){
            if((v2[i+1].ff-v2[i-1].ss)<=1){
                cout<<v2[i].id<<endl;return;
            }
        }
    }

    
    cout<<-1<<endl;

}

int32_t main(){
    fastcin();
    srand(time(0));
    int t=1;
    // cin>>t;
    preprocessing();
    rep(i,1,t+1){
        try {
            solve(i);
        }
        catch (const out_of_range& e) {
            cout<<rand()<<endl;
        }
    }
    return 0;
}
