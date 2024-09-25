#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
 
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


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(){
    int n;
    cin>>n;
    vector<string>vs(n);
    rep(i,0,n){
        cin>>vs[i];
    }
    list<char>l;
    rep(i,0,6){
        l.push_back('a'+i);
    }
    rep(i,0,n-1){
        int k = 0;
        while(k<vs[i].length() && k<vs[i+1].length()){
            if(vs[i][k]!=vs[i+1][k]){
                break;
            }
            k++;
        }
        if(k>=vs[i].length() || k>=vs[i+1].length()){
            if(vs[i].length()>vs[i+1].length()){
                cout<<"Impossible";return;
            }
            continue;
        }
        char x = vs[i][k];
        char y = vs[i+1][k];
        int x0 = 0,y0 = 0;
        for(auto it = l.begin(); it!=l.end();){
            auto el = *it;
            auto itt = it;
            it++;
            if(el==x){
                x0=1;
                if(y0==1){
                    l.insert(it, y);
                }else{
                    break;
                }
            }
            else if(el==y){
                y0=1;
                if(x0==0){
                    l.erase(itt);

                }else{
                    break;
                }
            }
            debugc(l)
            
        }
    }
    map<char,int>mp;
    int i  = 0;
    for(auto el:l){
        mp[el] = i;
        i++;
    }
    rep(i,0,n-1){
        int k = 0;
        while(k<vs[i].length() && k<vs[i+1].length()){
            if(vs[i][k]!=vs[i+1][k]){
                if(mp[vs[i][k]] > mp[vs[i+1][k]]){
                    cout<<"Impossible";return;
                }
                break;
            }
            k++;
        }
    }

    for(auto el:l){
        cout<<el;
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
