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

int par[N];
int sz[N];

int find_set(int ver){
    if(ver == par[ver]){
        return par[ver];
    }
    return par[ver] = find_set(par[ver]);
}

void unite(int a, int b){
    if(find_set(a)==find_set(b)){
        return;
    }

    int x = find_set(a);
    int y = find_set(b);

    if(sz[x]<sz[y]){
        swap(x,y);
    }
    par[y] = x;
    sz[x] += sz[y];


}

void solve(int testcases){
    int n;
    string s;
    cin>>s;
    int q;
    cin>>q;

    vpi qur(q);
    stack<char> st;
    rep(i,0,q){

        int x,y;
        cin>>x>>y;

        qur[i].ff = x;
        qur[i].ss = y;

        if(x==2){
            st.push(s[y]);
            s[y] = '#';
        }

        
    }
    n = s.length();

    debug(s)
    
    rep(i,0,n){
        par[i] = i;
        sz[i] = 1;
    }

    rep(i,0,n-1){
        if(s[i] == '#')continue;
        if(s[i]==s[i+1]){
            unite(i,i+1);
        }
    }
    // rep(i,0,n){cout<<sz[i]<<" ";}cout<<endl;

    stack<int>ans;

    for(int i = q-1; i>=0; i--){

        if(qur[i].ff==1){
            int p  = find_set(qur[i].ss);
            ans.push(sz[p]);
        }else{
            char x  = st.top();
            st.pop();

            int ii = qur[i].ss;

            s[ii] = x;
            sz[ii] = 1;
            par[ii] = ii;
            debug(ii)

            if(ii>0 && s[ii-1]==s[ii]){
                unite(ii,ii-1);
            }
            if(ii<n-1 && s[ii]==s[ii+1]){
                unite(ii,ii+1);
            }
        }
        debug(qur[i].ff);
        debug(s)
        // rep(i,0,n){cout<<sz[i]<<" ";}cout<<endl;
    }

    cout<<"Case "<<testcases<<": "<<endl;

    while(!ans.empty()){
        int x= ans.top();
        cout<<x<<endl;
        ans.pop();
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
