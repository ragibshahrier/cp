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
    vector<string>vs(n);
    int maxi=0;
    rep(i,0,n){
        cin>>vs[i];
        int x = vs[i].length();
        maxi = max(maxi,x);
    }
    vector<vector<char>>vs2(maxi, vector<char>(n, ' '));
    rep(i,0,n){
        rep(j,0,vs[i].length()){
            vs2[j][n-i-1]=vs[i][j];
        }
    }
    rep(i, 0, maxi){
        bool o =0;
        for(int j=n-1 ; j>=0; j--){
            if(o && vs2[i][j]==' '){
                vs2[i][j]='*';
            }
            if(vs2[i][j]!=' ')o=1;
            // cout<<vs2[i][j];
        }
        // cout<<endl;
    }
    rep(i, 0, maxi){
        for(int j=0 ; j<n; j++){
            
            cout<<vs2[i][j];
        }
        cout<<endl;
    }

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
