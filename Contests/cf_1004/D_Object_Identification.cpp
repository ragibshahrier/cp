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


int ask(int i, int j){
    cout<<"? "<<i<<" "<<j<<endl;
    cout.flush();
    int x;
    cin>>x;
    return x;
}

void tell(int i){
    if(i==1){
        cout<<"! A"<<endl;
    }else{
        cout<<"! B"<<endl;
    }
    cout.flush();
}

void solve(int testcases){
    int n;
    cin>>n;
    vi a(n);
    get_vector(a);
    set<int>s;
    rep(i,1,n+1){
        s.insert(i);
    }
    int i1 = 0, in = 0, in_1;

    vi hsh(n+1);
    rep(i,0,n){
        s.erase(a[i]);
        hsh[a[i]]=i+1;
        if(a[i]==1){
            i1 = i+1;
        }else if(a[i]==n-1){
            in_1 = i+1;
        }else if(a[i]==n){
            in = i+1;
        }

    }

    if(s.empty()){
        int x = ask(i1,in);
        if(x<n-1){
            tell(1);
        }else if(x>n-1){
            tell(2);
        }
        else{
            int y = ask(in,i1);
            if(y<n-1){
                tell(1);
            }else{
                tell(2);
            }
        }
        
    }else{
        int nn = *s.begin();
        int x;
        if(nn==1)x = ask(nn,2);
        else x = ask(nn,1);

        if(x==0){
            tell(1);
        }else{
            tell(2);
        }

    }

}

int32_t main(){
    // fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
