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

//#define DEBG

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


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(){
    int n;
    cin>>n;

    vector<vpi> pia(3, vpi(n));
    vpi& a = pia[0];
    vpi& b = pia[1];
    vpi& c = pia[2];
    rep(i,0,n){
        cin>>a[i].ff;
        a[i].ss = i;

    }
    rep(i,0,n){
        cin>>b[i].ff;
        b[i].ss = i;

    }
    rep(i,0,n){
        cin>>c[i].ff;
        c[i].ss = i;

    }
    sort(All(a),greater<pi>());
    sort(All(b),greater<pi>());
    sort(All(c),greater<pi>());

    vector<vector<int>>perms = {{0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,1,0}, {2,0,1}};
    ll ans  = 0;
    for(auto perm:perms){
        int i,j;
        ll tempans=0;
        i = pia[perm[0]][0].ss;
        tempans+=pia[perm[0]][0].ff;
        int k=0;
        while(pia[perm[1]][k].ss==i){
            k++;
            // continue;
        }
        j = pia[perm[1]][k].ss;
        tempans+=pia[perm[1]][k].ff;
        k=0;
        while(pia[perm[2]][k].ss==i||pia[perm[2]][k].ss==j){
            k++;
            // continue;
        }
        tempans+=pia[perm[2]][k].ff;
        ans = max(ans,tempans);

    }
    cout<<ans<<endl;




}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
