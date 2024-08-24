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


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}


ll func(int a,int b, int c, vll& rv, vll& gv, vll& bv, vector<vector<vll>>&dpp){
    // if(a==rv.size()||b==gv.size()||c==bv.size()){
    //     return 0;

    // }
    if(dpp[a][b][c]!=-1)return dpp[a][b][c];

    if(a==rv.size()){
        ll sum=0;
        for(int i = b, j=c; i<gv.size()&&j<bv.size();i++,j++){
            sum+=gv[i]*bv[j];
        }
        debug(sum)
        return  dpp[a][b][c] = sum;
    }
    if(b==gv.size()){
        ll sum=0;
        for(int i = a, j=c; i<rv.size()&&j<bv.size();i++,j++){
            sum+=rv[i]*bv[j];
        }
        return dpp[a][b][c] = sum;
    }
    if(c==bv.size()){
        ll sum=0;
        for(int i = a, j=b; i<rv.size()&&j<gv.size();i++,j++){
            sum+=rv[i]*gv[j];
        }
        return dpp[a][b][c] = sum;
    }

    ll ans1=0,ans2=0,ans3=0;
    ans1 = rv[a]*gv[b]+func(a+1,b+1,c, rv, gv, bv,dpp);
    ans2 = rv[a]*bv[c]+func(a+1,b,c+1, rv, gv, bv,dpp);
    ans3 = gv[b]*bv[c]+func(a,b+1,c+1, rv, gv, bv,dpp);
    ll ans = max({ans1,ans2,ans3});
    debug(a)
    debug(b)
    debug(c)
    debug(ans)
    debug(ans1)
    debug(ans2)
    debug(ans3)
    return dpp[a][b][c]=ans;
}

void solve(){
    vector<vector<vll>>dpp(201, vector<vll>(201, vll(201,-1)));
    int r,g,b;
    cin>>r>>g>>b;
    vll rv(r),gv(g),bv(b);
    get_vector(rv);
    get_vector(gv);
    get_vector(bv);

    sort(All(rv),greater<ll>());
    sort(All(gv),greater<ll>());
    sort(All(bv),greater<ll>());

    cout<<func(0,0,0,rv,gv,bv,dpp)<<endl;
    

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
