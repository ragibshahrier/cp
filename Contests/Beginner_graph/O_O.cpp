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

#define DEBG

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
    int n;cin>>n;
    string s;
    cin>>s;
    map<char,char>mp;
    set<char>s1;
    set<char>sov;
    set<char>sox;
    rep(i,0,26){
        char x = (char)('a'+i);
        s1.insert(x);
        sox.insert(x);
    }
    string ans="";
    char top = s[0];
    for(auto ch:s){
        // auto it = mp.find(ch);
        // if(ch=='y'){
        //     break;
        // }
        char x=mp[ch];
        debug(ch)
        debugc(sox)
        debug(top)
        debug(ans)
        if(x!=0){
            ans.push_back(x);
        }else{
            auto it=sox.begin();
            if(ch==*it || mp[*it]==ch){
                it++;
            }
            if(*it==top){
                if(sox.find(ch)==sox.end() && (sox.size()>1)){
                    it++;
                }else{
                    top = ch;
                }
            }
            mp[ch]=*it;
            ans.push_back(*it);
            sov.insert(*it);
            s1.erase(ch);
            sox.erase(it);
        }
    }
    // debug(ch)
    debug("end")
        debugc(sox)
        debug(top)
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
