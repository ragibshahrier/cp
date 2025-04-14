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

void solve(int testcases){
    int n;
    cin>>n;
    string s;
    cin>>s;

    vpi vp(3);
    vp[0].ss = 'L';
    vp[1].ss = 'I';
    vp[2].ss = 'T';
    rep(i,0,n){
        if(s[i]=='L')vp[0].ff++;
        if(s[i]=='I')vp[1].ff++;
        if(s[i]=='T')vp[2].ff++;
    }

    sort(All(vp));

    list<char>ls(All(s));

    char lo = vp[0].ss; 
    char mid = vp[1].ss; 
    char hi = vp[2].ss; 


    int loc = vp[0].ff; 
    int midc = vp[1].ff; 
    int hic = vp[2].ff; 
    int ind = 1;
    vi ans;
    debug(loc)
    debug(midc)
    for(auto it=ls.begin();it!=ls.end() && loc<midc;it++){
        auto itt = it;
        itt++;
        if(itt==ls.end())continue;
        if(*itt!=*it && *it!=lo && *itt!=lo){
            ls.insert(itt, lo);
            ans.push_back(ind);
            loc++;
        }
        debugc(ls)

        ind++;
    }
    if(loc!=midc){
        cout<<-1<<endl;return;
    }

    ind  = 1;

    int ops = hic-midc;
    debug(ops)
    debug((char)(hi))
    for(auto it=ls.begin();it!=ls.end() && ops>0;it++){
        auto itt = it;
        itt++;
        if(itt==ls.end())continue;
        debug(*it)
        debug(*itt)
        if(*it==hi && *itt!=hi){
            while(ops--){
                ans.push_back(ind);
                ans.push_back(ind);
            }
            debug(ops)
            ops = 0;
            break;
        }else if(*it!=hi && *itt==hi){
            rep(j,0,ops*2){
                ans.push_back(ind+j);
            }
            ops=0;
            break;
        }
        ind++;
    }

    if(ops!=0){
        cout<<-1<<endl;return;
    }

    cout<<ans.size()<<endl;

    for(auto el:ans){
        cout<<el<<endl;
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
