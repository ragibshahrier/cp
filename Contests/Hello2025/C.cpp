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

int bitcnt(int n){
    int ans = 1;
    while(n>1){
        n/=2;
        ans++;
    }
    return ans;
}

int strtoint(string str){
    ll ans  = 0;
    int x = 1;
    for(int i = str.length()-1; i>=0; i--){
        ans += x*(str[i]-'0');
        x *= 2;
    }
    return ans;
}

string inttobin(int i){
    // int x = bitcnt(i);
    string ans = "";
    rep(ii, 0, 32){
        if(checkbit(i , ii)){
            ans.push_back('1');
        }else{
            ans.push_back('0');
        }

    }
    reverse(All(ans));
    return ans;
}

void solve(int testcases, int l, int r, int fff){
    // int l,r;
    // cin>>l>>r;
    if(testcases == 1275){
        fff = 1;
    }

    ll up=r;
    ll down=l;
    // cout<<1<<endl;

    
    if(r-l==2){
        if(fff)cout<<l<<gp<<l+1<<gp<<r<<endl;
        return;
    }
    
    string upp= inttobin(up);
    string downn = inttobin(down);

    int x = bitcnt(up);
    string ans = "";
    int f = 0;
    debug(x)
    debug(up)
    debug(upp)
    debug(downn)
    
    for(int i = 32-x; i<32; i++){
        if(upp[i]=='0' && downn[i]=='0'){
            debug(i)
            debug(f)
            if(!f)ans.push_back('0');
            else ans.push_back('1');
        }
        else if(upp[i]=='1' && downn[i]=='1'){
            if(!f)ans.push_back('1');
            else ans.push_back('0');
        }
        else if(upp[i]=='1' && downn[i]=='0'){
            if(i==31 || f){
                ans.push_back('0');
            }else{
                int j = 1;
                while(upp[i+j]=='0'&& downn[i+j]=='1'){
                    j++;
                }
                if(upp[i+j]=='0'){
                    rep(ii,0,j){
                        ans.push_back(downn[i+ii]);
                    }
                }else{
                    rep(ii,0,j){
                        ans.push_back(upp[i+ii]);
                    }
                }
                i+=j-1;
                f=1;
                // if(upp[i+1]=='0' && downn[i+1]=='0'){
                //     ans.push_back('0');
                //     ans.push_back('1');
                //     f= 1;
                //     i++;
                // }else if(upp[i+1]=='1' && downn[i+1]=='1'){
                //     ans.push_back('1');
                //     ans.push_back('0');
                //     f = 1;
                //     i++;
                // }else if(upp[i+1]=='0' && downn[i+1]=='1'){
                //     if(upp[i+2]=='0'){
                //         ans.push_back('0');
                //         ans.push_back('1');
                //         ans.push_back('1');

                //     }
                //     f = 1;
                //     i++;

                // }else if(upp[i+1]=='1' && downn[i+1]=='0'){
                //     ans.push_back('1');
                //     ans.push_back('0');
                //     f = 1;
                //     i++;

                // }
            }
        }else{
            ans.push_back('1');
        }
    }
    debug(ans)

    int ansiint = strtoint(ans);

    if(fff)cout<<l<<gp<<ansiint<<gp<<r<<endl;

    if(l==ansiint || r==ansiint){
        // cout<<1<<endl;
        // cout<<l<<gp<<ansiint<<gp<<r<<endl;
        // debug(l)
        // debug(ansiint)
        // debug(r)
    }
    debug((l^r)+(l^ansiint)+(r^ansiint))

    int a = 98   , b= 85 , c = 76;
    debug((a^b)+(a^c)+(b^c))
    

}

int ran(int lo, int hi){
    return lo+(rand())%(hi-lo+1);
}


int32_t main(){
    fastcin();
    srand(time(0));
    int t=1;
    cin>>t;
    preprocessing();
    int f = 1;
    rep(i,1,t+1){

        int l,r;
        cin>>l>>r;
        // if(l==1 && r==1073741823){
        //     f = 0;
        // }
        solve(i,l,r,f);

        // int l = ran(0,5000000);
        // int r = ran(l+2, 600000);
        // solve(i,l,r,f);

    }
    // rep(i,1,t+1)solve(i);
    return 0;
}
