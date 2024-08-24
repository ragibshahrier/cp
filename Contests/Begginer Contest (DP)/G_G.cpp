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

// #define DEBG

#define debug(n)
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#endif

#define fastcin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'


#define All(a) a.begin(),a.end()
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}


const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;
const ll N = 1e5 + 7;


//==============================CODE STARTS HERE==============================//



int n,m;
vi a;
vi ch;
ll cnt=0;

ll dpp[N][105];

void preprocessing(){

}

ll func(int ind, int mm){
    if(ind>=n){
        debugc(ch)
        // cnt++;
        return 1;
    }
    if(dpp[ind][mm]!=-1)return dpp[ind][mm];
    if(ind==0){
        debug(a[0])
        ll ans = 0;
        if(a[ind]!=0)return dpp[ind][mm]=func(ind+1, ch[ind]);
        else{
            rep(i,1,m+1){
                ch[ind]=i;
                ans+=func(ind+1, ch[ind]);
                ans%=M;
            }
            ch[ind]=0;
        }
        return dpp[ind][mm]=ans%M;
    }
    if(a[ind]!=0){
        if(abs(ch[ind]-ch[ind-1])>1){
            return 0;
        }
        else return dpp[ind][mm]=func(ind+1, ch[ind]);
    }else{
        ll ans = 0;
        ch[ind]=ch[ind-1];
        ans += func(ind+1, ch[ind]);
        ans%=M;
        if(ch[ind-1]<m){
            ch[ind]=ch[ind-1]+1;
            ans+=func(ind+1, ch[ind]);
            ans%=M;

        }
        // else{
        //     debug(ch[ind-1])
        //     debugc(ch)
        // }
        if(ch[ind-1]>1){
            ch[ind]=ch[ind-1]-1;
            ans+=func(ind+1, ch[ind]);
            ans%=M;

        }
        ch[ind]=0;
        return dpp[ind][mm]=ans%M;
    }
}


void solve(){
    memset(dpp, -1, sizeof(dpp));
    cin>>n>>m;
    a.resize(n);
    get_vector(a);
    ch = a;
    cnt = func(0,0);
    debug(a[0])
    cout<<cnt;
    

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
