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

vvll dpp(5050, vll(5050,-1));
int n,m;
vvi v1,v2;
int func(int intt, int str){
    if(intt+str>=v1.size()){
        return 0;
    }
    if(dpp[intt][str]!=-1){
        return dpp[intt][str];
    }
    
    int r1 = upper_bound(All(v1[intt+str]), intt) - v1[intt+str].begin();
    int r2 = upper_bound(All(v2[intt+str]), str) - v2[intt+str].begin();
    if(intt+str>m){
        return dpp[intt][str]=r1+r2;
    }

    ll maxi = max(func(intt+1,str), func(intt,str+1));
    return dpp[intt][str]=maxi+r1+r2;

}


void preprocessing(){

}

void solve(){
    
    cin>>n>>m;;
    vi a(n);
    get_vector(a);
    
    

    vi temp1;
    vi temp2;

    rep(i,0,n){
        if(a[i]!=0){
            if(a[i]<0){
                temp2.push_back(-a[i]);
            }else{
                temp1.push_back(a[i]);

            }
        }else{
            sort(All(temp1));
            sort(All(temp2));
            v1.push_back(temp1);
            v2.push_back(temp2);
            debugc(temp1)
            debugc(temp2)
            temp1.clear();
            temp2.clear();
        }
    }
    sort(All(temp1));
    sort(All(temp2));
    debugc(temp1)
    debugc(temp2)
    v1.push_back(temp1);
    v2.push_back(temp2);
    
    ll ans = func(0,0);
    cout<<ans;

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
