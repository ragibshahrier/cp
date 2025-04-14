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




void preprocessing(){

}

void solve(){
    int n;
    string s;
    cin>>s;
    cin>>n;
    vi a(n);
    get_vector(a);
    sort(All(a),greater<int>());
    int len = s.length();
    int flag = 0;
    rep(i,0,len){
        // if(s[i]=='a')continue;
        pi best = {1000, 0};
        rep(j,0,n){
            if(a[j]+i<len){
                if(s[a[j]+i]==s[i])flag = 1;
                if(s[a[j]+i]<s[i]){
                    if(best.ff>s[a[j]+i]){
                        best = {s[a[j]+i], a[j]+i};
                    }else if(best.ff==s[a[j]+i] && best.ss<a[j]+i){
                        best.ss = a[j]+i;
                    }
                }
            }

        }
        debug(i)
        debug(best.ff)
        debug(best.ss)
        if(best.ff!=1000){
            swap(s[i], s[best.ss]);
            cout<<s;return;
        }
    }
    if(flag){
        cout<<s;return;
    }
    int x = a.back();
    swap(s[len-1], s[len-1-x]);
    cout<<s;


}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
