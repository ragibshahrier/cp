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

//#define DEBG

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

int n;
int ask(int a,int b){
    cout<<'?'<<gp<<a<<gp<<b<<endl;
    cout.flush();
    int aa;
    cin>>aa;
    return aa;
}
void tell(vi& a){
    cout<<'!'<<gp;
    
    rep(i,1,n){
        cout<<a[i]<<gp;
    }
    cout<<endl;
    cout.flush();
}

void preprocessing(){

}

void solve(){
    cin>>n;
    set<int>s;
    vi ans(n);
    s.insert(1);
    ans[1]= 0;
    int i = 2;
    while(ask(1,i)){
        s.insert(i);
        ans[i] = 0;
        i++;
    }
    ans[i] = 1;
    s.erase(1);
    s.insert(i);
    i++;
    while(i<n){

        for(auto it = s.begin();it!=s.end();){
            auto itt = it;
            it++;
            int el = *itt;
            s.erase(itt);
            if(!ask(i,el)){
                s.insert(i);
                ans[i] = el;
                i++;
                break;
            }
        }
    }
    tell(ans);


}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
