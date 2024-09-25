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

//#define DEBG

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

void printl(list<int>&l ){
    for(auto el:l){
        cout<<el;
    }
}

void solve(){
    int n;
    cin>>n;
    int x,y;

    cout<<"? 0"<<endl;
    cout.flush();
    cin>>x;
    if(x==0){
        cout<<"! ";
        rep(i,0,n){
            cout<<1;
        }
        cout<<endl;
        cout.flush();
        return;

    }
    list<int>l = {0};
    bool b= 0;
    while(l.size()<n-1 || (b==0 && l.size()<n)){
        if(b==0){
            cout<<"? ";printl(l);
            cout<<0;cout<<endl;
            cout.flush();
            cin>>x;
            if(x){
                l.push_back(0);
                continue;
            }
            cout<<"? ";printl(l);
            cout<<1;cout<<endl;
            cout.flush();
            cin>>x;
            if(x){
                l.push_back(1);
                continue;
            }
            else{
                b=1;
            }

        }else{
            cout<<"? ";cout<<0;printl(l);cout<<endl;
            cout.flush();
            cin>>x;
            if(x){
                l.push_front(0);
                continue;
            }
            cout<<"? ";cout<<1;printl(l);cout<<endl;
            cout.flush();
            cin>>x;
            if(x){
                l.push_front(1);
                continue;
            }
            
        }
    }
    if(l.size()==n){
        cout<<"! ";printl(l);cout<<endl;
        cout.flush();
    }else{
        cout<<"? ";cout<<0;printl(l);cout<<endl;
        cout.flush();
        cin>>x;
        if(x){
            l.push_front(0);
                
        }
        else{
            l.push_front(1);
        }
        cout<<"! ";printl(l);cout<<endl;
        cout.flush();
    }

}

int main(){
    // fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
