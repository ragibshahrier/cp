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


void decToBinary(int n)
{
    // Array to store binary number
    int binaryNum[32];
 
    // Counter for binary array
    int i = 0;
    while (n > 0) {
        // Storing remainder in binary
        // array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    // Printing binary array in reverse
    // order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}

void preprocessing(){

}

void solve(int testcases){
    int n1=0,n2=0;
    // n1 = 101010101010101010101010101010;
    // n2 =  10101010101010101010101010101;

    for(int i =1; i<=29; i+=2){
        setbit(n1,i);
    }


    for(int i =0; i<=28; i+=2){
        setbit(n2,i);
    }
    // decToBinary(n1);
    // cout<<endl;
    // decToBinary(n2);
    // cout<<endl;
    
    cout<<n1<<endl;
    cout.flush();
    
    int x1,x2;
    cin>>x1;
    
    cout<<n2<<endl;
    cout.flush();

    cin>>x2;


    int x=0,y=0;

    n1 = x1;n2 = x2;

    rep(i,0,15){
        int temp = n1&3;
        
        if(i!=0)temp--;
        if(temp==1){
            setbit(x,i*2);
        }else if(temp==2){
            setbit(x,i*2);
            setbit(y,i*2);

        }
        n1>>=2;
    }
    
    n2>>=1;
    debug(x)
    debug(y)
    
    rep(i,0,15){
        int temp = n2&3;
        temp--;
        if(temp==1){
            setbit(x,i*2+1);
        }else if(temp==2){
            setbit(x,i*2+1);
            setbit(y,i*2+1);
            
        }
        n2>>=2;
    }

    cout<<"!"<<endl;
    cout.flush();

    int m;
    cin>>m;

    ll ans = (m|x)+(m|y);

    debug(x)
    debug(y)

    cout<<ans<<endl;
    cout.flush();





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
