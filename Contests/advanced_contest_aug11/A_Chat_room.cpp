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

void solve(){
    string s;
    cin>>s;
    int ct = 0;
    int n = s.length();
    bool H = false, E = false, L = false, O = false;
    for(int i = 0; i<n; i++){
        if(!H){
            if(s[i]=='h'){
                H = true;
                continue;
            }
            s[i] = '.';
            continue;
        }
        if(!E){
            if(s[i]=='e'){
                E = true;
                continue;
            }
            s[i] = '.';
            continue;
        }
        if(!L){
            if(s[i]=='l'){
                ct++;
                if(ct==2){
                    L = true;
                    continue;
                }
                continue;
            }
            s[i] = '.';
            continue;
        }
        if(!O){
            if(s[i]=='o'){
                O = true;
                continue;
            }
            s[i]='.';
            continue;
        }
        s[i] ='.';
    }
    debug(s);
    string sp;
    for(int i = 0; i<n; i++){
        if(s[i]!='.'){
            sp.push_back(s[i]);
        }
    }
    if(sp=="hello"){
        cout<<"YES";
    }
    else cout<<"NO";

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
