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
map<int, int>mp;
int fff=0;

int ist(string s1, string s2){
    int n = s1.length();
    int w = 0;
    rep(i,0,n){
        if(s1[i]!=s2[i]){
            w++;
        }
    }
    if(w==2)return 1;
    if(fff){
        if(w==0)return 1;
    }
    return 0;
}


int isvalid(vector<string>vs){
    int k  = vs.size();
    rep(i,0,k){
        sort(All(vs[i]));
    }
    
    
    
    int f = 0;
    rep(i,1,k){
        if(vs[i]!=vs[0]){
            debugc(vs[i])
            debugc(vs[0])
            return 0;
        }
    }
    
    return 1;
}



void solve(int testcases){
    int n,k;
    cin>>k>>n;
    vector<string>vs(k);
    random_shuffle(All(vs));
    
    
    rep(i,0,k){
        cin>>vs[i];
    }
    debug(1)
    if(!isvalid(vs)){
        cout<<-1<<endl;return;
    }
    debug(1)
    
    rep(i,0,n){
        mp[vs[0][i]]++;
        if(mp[vs[0][i]]>=2)fff=1;
    }
    debugcc(mp)
    
    if(k==1){
        swap(vs[0][0], vs[0][1]);
        cout<<vs[0]<<endl;return;
    }

    vi v;
    rep(j,1,k){
        vi temp;
        rep(i,0,n){
            if(vs[0][i]!=vs[j][i]){
                temp.push_back(i);
            }
        }
        if(v.size()<temp.size()){
            v = temp;
        }
    }

    debug(1)

    int sz = v.size();

    if(sz==0){
        swap(vs[0][0], vs[0][1]);
        cout<<vs[0]<<endl;return;
    }
    debugc(v)
    if(sz>4){
        cout<<-1<<endl;return;
    }
    debug(fff)
    int f = 1;
    rep(m,0,k){
        if(!ist(vs[m],vs[0])){
            f=0;
            break;
        }
    }
    if(f){
        cout<<vs[0]<<endl;return;
    }


    rep(i,0,sz){
        rep(j,i+1,sz){
            string tempv = vs[0];
            swap(tempv[v[i]], tempv[v[j]]);
            debug(vs[0])
            debug(tempv)
            int f = 1;
            rep(m,0,k){
                if(!ist(vs[m],tempv)){
                    f=0;
                    break;
                }
            }
            if(f){
                cout<<tempv<<endl;return;
            }
        }
    }

    cout<<-1<<endl;return;

}

int32_t main(){
    fastcin();
    srand(time(0));

    int t=1;
    // cin>>t;
    preprocessing();
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
