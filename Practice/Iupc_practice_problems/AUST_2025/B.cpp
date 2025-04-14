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

void solve(int testcases){
    int n;
    cin>>n;

    // vi a;
    // rep(i,1,n+1){
    //     a.push_back(i);
    // }
    // do{
    //     set<int>s;
    //     vi b;
    //     rep(i,0,n){
    //         int temp = abs(a[i]-(i+1));
    //         s.insert(temp);
    //         b.push_back(temp);
    //     }
    //     int mx;
    //     rep(i,0,n+2){
    //         if(s.find(i)==s.end()){
    //             mx = i;
    //             break;
    //         }
    //     }
    //     if(mx>=n-1){
    //         put_vector(a);
    //         put_vector(b);
    //         cout<<endl;
    //     }
        
    // }while(next_permutation(All(a)));


    if(n==1){
        cout<<"1"<<endl;
    }else if(n==2){
        cout<<"1 2"<<endl;
    }else if(n==3){
        cout<<"1 3 2"<<endl;
    }

    else{
        int f = 0;
        int res;
        vi ans(n);
        ans[0] = 1;
        int num = 2;
        for(int i = n-1; i>1; i--,num++){
            int ind = i+1;
            int temp = ind-num;
            if(temp>0){
                ans[i] = num;
            }else if(!f){
                f=1;
                res = num;
                i++;
            }else{
                ans[i] = num;
            }
        }
        ans[1] = res;
        put_vector(ans);

        // set<int>s;
        // vi b;
        // rep(i,0,n){
        //     int temp = abs(ans[i]-(i+1));
        //     s.insert(temp);
        //     b.push_back(temp);
        // }
        // int mx;
        // rep(i,0,n+2){
        //     if(s.find(i)==s.end()){
        //         mx = i;
        //         break;
        //     }
        // }
        // if(mx>=n-1){
        //     put_vector(ans);
        //     put_vector(b);
        //     cout<<endl;
        // }

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
