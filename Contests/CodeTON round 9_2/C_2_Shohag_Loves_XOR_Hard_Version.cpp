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

#define DEBG

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

void solve(int x, int m){
    // int x = 7;
    
    // cout<<1<<endl;

    // int x,m;
    // cin>>x>>m;

    // int ans = 0;
    // rep(y,1,min(m+1,x)){
    //     if((x^y)%x==0 || (x^y)%y==0){
    //         ans++;
    //     }
    // }
    // if(m>=x){
    //     int st;
    //     // st = max(m-x+1,x);
    //     // ans += (m-x)/x;
    //     if(m-x*2<=x){
    //         st = x;
    //     }else{
    //         ans += (m-x*2)/x;
    //         st = ((m-x*2)/x)*x+1;
    //         st = max(st, x+1);
    //     }
    //     // debug(st)
    //     // m-=x;
    //     for(int y = st; y<=m; y++){
    //         if((x^y)%x==0 || (x^y)%y==0){
    //             if((x^y)>=(st)||((y%x==0 && y>=st)) || x==y){
    //                 ans++;
    //             }
    //         }
    //     }
    // }
    // cout<<ans<<endl;

    // int ans2 = 0;
    // rep(i, 1, m+1){
    //     // if((i^x)==0)continue;
    //     // if((i^x)%i==0){
    //     //     cout<<1<<gp<<x<<gp<<i<<gp<<(i^x)<<endl;
    //     // }if((i^x)%x==0){
    //     //     cout<<2<<gp<<x<<gp<<i<<gp<<(i^x)<<endl;
    //     // }
    //     if((i^x)%i==0 || (i^x)%x==0){
    //         ans2++;
    //     }
        
    // }
    // // cout<<ans2<<endl;
    // if(ans!=ans2){
    //     cout<<"nnnnn"<<endl;
    //     cout<<x<<gp<<m<<gp<<ans<<gp<<ans2<<endl;
    // }
    // else{
    //     // cout<<"y"<<endl;
    // }




    x = 5;

    rep(i, 1, 100){
        // if((i^x)==0)continue;
        if((i^x)%i==0){
            cout<<1<<gp<<x<<gp<<i<<gp<<(i^x)<<endl;
        }if((i^x)%x==0){
            cout<<2<<gp<<x<<gp<<i<<gp<<(i^x)<<endl;
        }
        // if((i^x)%i==0 || (i^x)%x==0){
        //     ans2++;
        // }
        
    }

}

int32_t main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1){
        int x,m;
        cin>>x>>m;
        solve(x,m);
        // for(int k = 1; k<=10*i; k++)
        // solve(i,k);
    }
    return 0;
}
