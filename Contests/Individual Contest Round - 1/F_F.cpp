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
#define pow2(i) (1LL<<i)

// #define DEBG

#define debug(n)
#define debugc(a)
#define debugcc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<'{'<<gp<<el.ff<<','<<el.ff<<gp<<'}'<<gp;}cout<<']'<<endl;
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


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(int cse){
    vll a(12);
    get_vector(a);
    multiset<ll>ms(All(a));
    vvll ans;
    while(ms.size()>=3){
        debugc(ms);
        auto itf = ms.begin();
        ll f = *itf;
        itf++;
        ms.erase(ms.find(f));
        ll s = *itf;itf++;
        ms.erase(ms.find(s));

        auto it = ms.lower_bound(f+s);
        if(it!=ms.begin()){
            it--;
            ll t = *it;
            vll v = {f,s,t};
            debugc(v);
            ans.push_back(v);
            ms.erase(it);
            
        }else{
           
            ms.insert(s);
        }
    }
    cout<<"Case #"<<cse<<": "<<ans.size()<<endl;
    if(ans.size()>0){

        rep(i,0,ans.size()){
            rep(j,0,2){
                cout<<ans[i][j]<<gp;
            }

            cout<<ans[i][2]<<endl;
        }

    }


    

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1)solve(i);
    // cout<<endl;
    return 0;
}
