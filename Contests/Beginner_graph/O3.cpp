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
#define endl '\n'


#define All(a) a.begin(),a.end()
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}


const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;


//==============================CODE STARTS HERE==============================//


bool b;
int cnt;

void preprocessing(){

}


void cyclechk(char ch, map<char,pair<char,char>>& mp, vi& visited){
    if(visited[ch-'a']){
        b=1;return;
    }
    visited[ch-'a']=1;
    cnt++;
    if(mp[ch].ss!=0)cyclechk(mp[ch].ss,mp,visited);
}

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    
    vi hsh(26,-1);
    int i,j;
    string un;
    for(i=0; i<s.length();i++){
        if(hsh[s[i]-'a']==-1){
            hsh[s[i]-'a']=1;
            un.push_back(s[i]);
        }

    }
    int xx= un.size();
    // rep(i,0,26){
    //     if(hsh[i]==-1){
    //         un.push_back(i+'a');
    //         hsh[i]=1;
    //     }
    // }
    map<char,pair<char,char>>mp;
    for(int i=0; i<26; i++){
        mp['a'+i]={0,0};
    }
    debug(un)
    for(auto& ch:un){
        for(auto& el:mp){
            debug(el.ff)
            debug(el.ss.ff)
            if(el.ff!=ch && el.ss.ff==0 && el.ss.ss!=ch){
                debug(ch)
                mp[ch].ss=el.ff;
                el.ss.ff=ch;
                vi visited(26);
                b=0;
                cnt=0;
                cyclechk(ch,mp,visited);
                if(!b || cnt==26){
                    debug("breaked");
                    break;
                }else{
                    debug("not")
                    el.ss.ff=0;
                    mp[ch].ss=0;
                }
            }
        }
    }
    for(auto el:s){
        cout<<mp[el].ss;
    }
    cout<<endl;

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
