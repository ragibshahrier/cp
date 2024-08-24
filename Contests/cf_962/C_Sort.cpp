#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
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

const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;


//----------------------CODE STARTS HERE-------------------




void preprocessing(){

}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<vi> as(n+1, vi(26,0));
    vector<vi> bs(n+1, vi(26,0));
    string a,b;
    cin>>a>>b;

    rep(i, 1, n+1){
        char x = a[i-1];
        char y = b[i-1];
        // debug(i)
        // debug(as[2][0])
        // debug(as[1][0])
        // debug(as[i][x-'a'])
        // debug(as[i-1][x-'a'])
        rep(j, 0 ,26){
            as[i][j]=as[i-1][j];
        }
        as[i][x-'a']++;
        // debug(i)
        // debug(as[i][x-'a'])
        // debug(as[i-1][x-'a'])
        rep(j, 0 ,26){
            bs[i][j]=bs[i-1][j];
        }
        bs[i][y-'a']++;
        




    }


    while(q--){
        int l,r;
        cin>>l>>r;
        ll op=0;
        rep(j, 0 ,26){
            debug(as[r][j])
            debug(bs[r][j])
            if(as[r][j]-as[l-1][j] > bs[r][j]-bs[l-1][j]){
                op += (as[r][j]-as[l-1][j]) - (bs[r][j]-bs[l-1][j]);
            }
        }
        cout<<op<<endl;

    }



}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
