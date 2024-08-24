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

const int N = 1e6+7;

// struct Node{
//     int x, y, num;
//     // vector<Node>nei;
// };
// vector<Node>nodes;


vector<pi> nodes;
vector<vi> visited(1005,vi(1005,inf));

void preprocessing(){

}

string ans;
int ansi=inf;

pi st,en;
ll cnttt=0;
void dfs(pi& node, vector<vector<char>>& mat, string& path){
    cnttt++;
    // debug(path)
    debug(mat[node.ff][node.ss])
    if(visited[node.ff][node.ss]<=path.length() || mat[node.ff][node.ss]=='#'){
        return;
    }
    visited[node.ff][node.ss]=path.length();
    if(node==en){
        // debug(ans)
        // debug(path)
        if(path.length()<ansi){
            ans=path;
            ansi=path.length();
            // visited[node.ff][node.ss]=0;
            return;
        }
        debug(ans)
    }
    path.push_back('U');
    pi co = {node.ff-1, node.ss};
    dfs(co, mat, path);
    path.pop_back();
    
    path.push_back('D');
    co = {node.ff+1, node.ss};
    dfs(co, mat, path);
    path.pop_back();

    path.push_back('L');
    co = {node.ff, node.ss-1};
    dfs(co, mat, path);
    path.pop_back();

    path.push_back('R');
    co = {node.ff, node.ss+1};
    dfs(co, mat, path);
    path.pop_back();
    
    // visited[node.ff][node.ss]=0;

    
    
}

void solve(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<char>>mat(n+7,vector<char>(m+7,'#'));
    // map<pi,int>mp;
    // Node nnn = {-2,-2,-2};
    // nodes.push_back(nnn);
    rep(i,1,n+1){
        rep(j,1,m+1){
            cin>>mat[i][j];
            if(mat[i][j]=='A'){
                st={i,j};

            }else if(mat[i][j]=='B'){
                en={i,j};
            }
        }
    }
    debug(st.ff)
    debug(st.ss)
    string path= "";
    dfs(st, mat, path);
    debug(cnttt)
    if(ansi==inf){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl<<ansi<<endl<<ans<<endl;
        
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
