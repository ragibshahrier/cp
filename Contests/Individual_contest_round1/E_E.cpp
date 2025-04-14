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
map<char,string>mp;

string hextobin(char t){
    int a = 0;
    if('0'<=t && t<='9'){
        a = t-'0';
    }else{
        a = (t-'A')+10;
    }
    string ans = "0000";
    rep(i,0,4){
        int d = a%2;
        a/=2;
        ans[4-i-1] = '0'+d;
    }
    mp[t] = ans;
    return ans;

}

void solve(int testcases){
    int n;
    cin>>n;
    
    vector<string>vs(n);
    vector<string>vs2;

    rep(i,0,n){
        cin>>vs[i];
    }

    int col = 0;
    int temp=1;
    string temps = vs[0];
    
    rep(i,1,n){
        if(vs[i]==vs[i-1]){
            temp++;
        }else{
            col = __gcd(temp, col);
            debug(col)
            temp = 1;
            vs2.push_back(temps);
            temps = vs[i];
        }
    }
    col = __gcd(temp, col);
    debug(col)
    temp = 1;
    vs2.push_back(temps);
    debug(vs2[1])

    for(char i = '0'; i<='9'; i++){
        hextobin(i);
    }
    for(char i = 'A'; i<='F'; i++){
        hextobin(i);
    }   
    int row = 0;

    for(auto& el:vs2){
        string& s = el;
        string s2(n,'0');
        debug(mp['3'])
        rep(i, 0, n/4){
            string s3 = mp[s[i]];
            rep(j,0,4){
                s2[i*4+j] = s3[j];
            }
        }

        temp = 1;
        debug(s2)
        rep(i,1,n){
            if(s2[i]==s2[i-1]){
                temp++;
            }else{
                row = __gcd(row, temp);
                temp = 1;
            }
        }
        row = __gcd(row, temp);
    }

    ll ans = __gcd(row,col);
    cout<<ans<<endl;




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
