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
#define checkbit(x,n) ((x&(1LL<<n))!=0)
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
int bitcnt(int n){
    int ans = 1;
    while(n>1){
        n/=2;
        ans++;
    }
    return ans;
}


void preprocessing(){

}
int ran(int lo, int hi){
    return lo+(rand())%(hi-lo+1);
}

int solve2(int l,int r){
    int anss = 0;
    rep(i,l,r+1){
        rep(j,i+1,r+1){
            rep(k,j+1,r+1){
                anss = max(anss, (i^j)+(j^k)+(k^i));
            }
        }
    }
    return anss;
}



int solve(int testcases,int l,int r){
    // int l,r;
    // cin>>l>>r;
    // l = 69;
    int a = 965321865 , b= 375544086 , c = 12551794;
    // debug((a^b)+(a^c)+(b^c))
    rep(i,l,r+1){
        if(((l^i) + (i^r) + (l^r)) == 17){
            cout<<i<<endl;
        }
    }

    int anss = 0;
    
    rep(i,l,r+1){
        rep(j,i+1,r+1){
            rep(k,j+1,r+1){
                if(anss < (i^j)+(j^k)+(k^i)){
                    anss = (i^j)+(j^k)+(k^i);
                    a = i;
                    b = j;
                    c = k;
                }
                
            }
        }
    }
    debug(anss)
    rep(i,l,r+1){
        rep(j,i+1,r+1){
            rep(k,j+1,r+1){
                if(anss == (i^j)+(j^k)+(k^l)){
                    cout<<i<<gp<<j<<gp<<k<<endl;
                }
                
            }
        }
    }
    
    cout<< anss<<endl;
    int i = 100;
    while(i--){
        int l= ran(0, 30);
        int r = ran(l+2,40);
        int anss = 0;
        rep(i,l,r+1){
            rep(j,i+1,r+1){
                rep(k,j+1,r+1){
                    if(anss < (i^j)+(j^k)+(k^i)){
                        anss = (i^j)+(j^k)+(k^i);
                        a = i;
                        b = j;
                        c = k;
                    }
                    
                }
            }
        }
        int f = 0;
        rep(i,l,r+1){
            rep(j,i+1,r+1){
                rep(k,j+1,r+1){
                    if(anss == (i^j)+(j^k)+(k^i)){
                        if(k==r && l==i)f=1;
                    }
                    
                }
            }
        }
        if(!f){
            cout<<"Wrong"<<endl;
            cout<<l<<gp<<r<<endl;
        }
        
    }

    ll mx  = 0;
    ll mn  = 0;
    // debug(r)
    int x = bitcnt(r);
    // debug(x)
    // rep(i,0,x){
    //     cout<<checkbit(r,i);

    // }
    // cout<<endl;
    // rep(i,0,x){
    //     cout<<checkbit(l,i);

    // }
    // cout<<endl;

    rep(i,0,x){
        if(checkbit(r,i) != checkbit(l,i)){
            setbit(mx, i);
            resetbit(mn,i);
        }else if(checkbit(r,i)){
            resetbit(mx,i);
            resetbit(mn,i);
        }else{
            setbit(mx,i);
            setbit(mn,i);
        }
    }
    ll ans = 0;
    // debug(mn)
    // debug(mx)

    // rep(i,0,30){
    //     cout<<checkbit(mn,i);
    // }
    // cout<<endl;

    // rep(i,0,30){
    //     cout<<checkbit(mx,i);
    // }
    // cout<<endl;
    if(l<mx && mx<r){
        ans= mx;
    }else if(l<mn && mn<r){
        ans = mn;
    }else{
        int i = x-1;
        while(!(l<mx && mx<r) && !(l<mn && mn<r) && i>=0){
            if(checkbit(mx,i)!=checkbit(mn,i)){
                resetbit(mx,i);
                setbit(mn,i);
            }
            i--;
        }
        i = x-1;
        while(!(l<mx && mx<r) && !(l<mn && mn<r) && i>=0){
            if(checkbit(mx,i)==checkbit(mn,i)){
                if(checkbit(mx,i)){
                    resetbit(mx,i);
                    resetbit(mn,i);
                }else{
                    setbit(mx,i);
                    setbit(mn,i);
                }
            }
            i--;
        }
    }
    if((l<mx && mx<r)){
        ans = mx;
    }else{
        ans = mn;
    }
    // ans = mx;
    // debug((r^l)+(ans^r)+(ans^l))
    cout<<l<<gp<<ans<<gp<<r<<endl;
    return ans;
}


void gen(){
    int x = 0, y=0;
    int i = 100;
    while(i--){
        
        int x= ran(0, 30);
        int y= ran(x+2,40);
        // debug(x)
        // debug(y)
        int ans = solve(0,x,y);
        int ans2 = solve2(x,y);
        if(ans2!= ((x^y)+ (x^ans)+(ans^y))){
            debug(ans2)
            debug(x)
            debug(y)
            debug(ans)
            debug((x^y)+ (x^ans)+(ans^y))
            debug("Wronnnggggg");
            return;
        }

    }
    debug(1)
}

int32_t main(){
    fastcin();
    srand(time(0));

    int t=1;
    cin>>t;
    preprocessing();
    gen();
    // rep(i,1,t+1){
    //     int l,r;
    //     cin>>l>>r;
    //     solve(i,l,r);
    // }
    return 0;
}
