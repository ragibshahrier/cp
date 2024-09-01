#include<bits/stdc++.h>
using namespace std;
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
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<'{'<<gp<<el.ff<<','<<el.ff<<gp<<'}'<<gp;}cout<<']'<<endl;
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


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    if(n&1){
        vvi odds(n, vi(26));
        vvi evens(n, vi(26));
        vvi oddsb(n, vi(26));
        vvi evensb(n, vi(26));
        // odds[0][s[0]-'a']=1;
        rep(i,1,n){
            rep(j,0,26){
                if((i&1) ==0){
                    if(s[i-1]-'a'==j)evens[i][j]=evens[i-1][j]+1;
                    else evens[i][j]=evens[i-1][j];
                    odds[i][j]=odds[i-1][j];
                }else{
                    if(s[i-1]-'a'==j)odds[i][j]=odds[i-1][j]+1;
                    else odds[i][j]=odds[i-1][j];
                    evens[i][j]=evens[i-1][j];

                }
            }
        }
        // oddsb[n-1][s[n-1]-'a']=1;

        for(int i = n-2; i>=0; i--){
            rep(j,0,26){
                if((i&1) ==0){
                    if(s[i+1]-'a'==j)evensb[i][j]=evensb[i+1][j]+1;
                    else evensb[i][j]=evensb[i+1][j];
                    oddsb[i][j]=oddsb[i+1][j];
                }else{

                    if(s[i+1]-'a'==j)oddsb[i][j]=oddsb[i+1][j]+1;
                    else {
                        debug(i)
                        debug(j)
                        if(i==0 && j==1){
                            debug(oddsb[i][j])
                            debug(oddsb[i+1][j])
                        }
                        oddsb[i][j]=oddsb[i+1][j];
                    }
                    evensb[i][j]=evensb[i+1][j];

                }
            }
        }
        debug(s[2]-'a')
        debug(oddsb[0][1])
        debugc(evens[0])
        debugc(odds[0])
        debugc(evensb[0])
        debugc(oddsb[0])
        int ans = inf;
        rep(i,0,n){
            int mxe =0;
            int mxo = 0;
            rep(j,0,26){
                mxe = max(mxe, odds[i][j]+evensb[i][j]);
                mxo = max(mxo, evens[i][j]+oddsb[i][j]);
                debug(mxe)
                debug(mxo)
                debug(i)
                debug(j)
            }
            debug(mxe)
            debug(mxo)
            ans = min(ans, n/2-mxe+n/2-mxo);
        }
        ans++;
        cout<<ans;

        cout<<endl;
        return;
    }
    vi odd(26);
    vi even(26);
    rep(i,0,n){
        if(i&1){
            even[s[i]-'a']++;
        }else{
            odd[s[i]-'a']++;
        }
    }
    int mxe = *max_element(All(even));
    int mxo = *max_element(All(odd));
    
    cout<<n/2-mxe+n/2-mxo<<endl;
    
}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
