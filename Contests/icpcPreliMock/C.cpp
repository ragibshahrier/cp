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




vvi ans;
void preprocessing(){
    vpi aaa = {{3,0}, {0,3}, {1,1}};
    vi temp(3);
    rep(i,0,3){
        temp[0] += aaa[i].ff;
        temp[1] += aaa[i].ss;
        rep(j,0,3){
            temp[0] += aaa[j].ff;
            temp[2] += aaa[j].ss;
            rep(k,0,3){
                temp[1] += aaa[k].ff;
                temp[2] += aaa[k].ss;
                ans.push_back(temp);
                temp[1] -= aaa[k].ff;
                temp[2] -= aaa[k].ss;
            }
            temp[0] -= aaa[j].ff;
            temp[2] -= aaa[j].ss;
        }
        temp[0] -= aaa[i].ff;
        temp[1] -= aaa[i].ss;
    }
}

void solve(int cases){
    // if(cases!=1)cout<<endl;
    int a,b,c;
    // vvi ans;
    // ans.push_back({6,3,0});
    // ans.push_back({6,1,1});
    // ans.push_back({4,3,1});
    // ans.push_back({4,2,1});
    // ans.push_back({4,4,0});
    // ans.push_back({3,3,3});
    // ans.push_back({2,2,2});
    
    vi aa;
    cin>>a>>b>>c;
    aa.push_back(a);
    aa.push_back(b);
    aa.push_back(c);

    // for(auto el:ans){
    //     debugc(el)
    // }

    // sort(All(aa), greater<int>());
    // debugc(aa)

    cout<<"Case "<<cases<<": ";
    if(find(All(ans), aa)!= ans.end()){
        cout<<"perfectus";
    }else{
        cout<<"invalidum";
    }
    cout<<endl;



}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1)solve(i);
    return 0;
}
