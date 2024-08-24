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
    int n,q;
    cin>>n>>q;
    vector<string>vs(n);
    vvi nodes(4);
    map<string,int>mp;
    // BG, BR, BY, GR, GY, or RY
    mp["BG"]=0;
    mp["BR"]=1;
    mp["BY"]=2;
    mp["GR"]=3;
    mp["GY"]=4;
    mp["RY"]=5;
    map<char,vector<string>>mp2;
    mp2['B']={"BG","BR","BY"};
    mp2['R']={"BR","GR", "RY"};
    mp2['Y']={"BY", "GY", "RY"};
    mp2['G']={"BG", "GR", "GY"};
    get_vector(vs);
    vvll costr(n+2,vll(6,-INF));
    vvll costl(n+2,vll(6,INF));
    rep(i,0,n){
        
        costr[i+1][mp[vs[i]]]=0;
        // costr[i+1][mp[vs[i]]]=0;
        rep(j,0,6){
            costr[i+1][j]=max(costr[i][j]-1,costr[i+1][j]);

        }
    }
    for(int i = n; i>=1; i--){
        costl[i][mp[vs[i-1]]]=0;
        // costl[i][mp[vs[i-1][1]]]=0;
        rep(j,0,6){
            costl[i][j]=min(costl[i+1][j]+1,costl[i][j]);

        }

    }
    while(q--){
    ll ans = INF;
        int x,y;
        cin>>x>>y;
        debug(q)
        if(vs[x-1][0]==vs[y-1][0] || vs[x-1][0]==vs[y-1][1] || vs[x-1][1]==vs[y-1][0] || vs[x-1][1]==vs[y-1][1]){
            debug(vs[x-1][0])
            debug(vs[x-1][1])
            debug(vs[y-1][0])
            debug(vs[y-1][1])
            ans = abs(x-y);
            debug(ans)
            cout<<ans<<endl;
            continue;
        }
        debug(mp2[vs[y-1][0]][0])
    // debug(abs(costl[x][mp["RY"]]))
    debug(ans)
        for(auto ss:mp2[vs[y-1][0]])if(ss!=vs[y-1]) ans = min(ans, abs(costr[x][mp[ss]])+abs((y-x)-costr[x][mp[ss]]));
    debug(ans)
        for(auto ss:mp2[vs[y-1][1]])if(ss!=vs[y-1]) ans = min(ans, abs(costr[x][mp[ss]])+abs((y-x)-costr[x][mp[ss]]));
    debug(ans)
        for(auto ss:mp2[vs[y-1][0]])if(ss!=vs[y-1]) ans = min(ans, abs(costl[x][mp[ss]])+abs((y-x)-costl[x][mp[ss]]));
    debug(ans)
        for(auto ss:mp2[vs[y-1][1]])if(ss!=vs[y-1]) ans = min(ans, abs(costl[x][mp[ss]])+abs((y-x)-costl[x][mp[ss]]));
    debug(ans)
        if(ans>1e11 || ans<-1e11)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    
    

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
