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
#define debugcc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto it=a.begin(); it!=a.end(); it++;){pi el=*it; cout<<'{'<<el.ff<<','<<el.ss<<'}'<<gp;}cout<<']'<<endl;
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

vector<pi> nodes;
vector<vi> visited(1005,vi(1005));



string ans;
int ansi=inf;

pi st,en;

queue<pi>q;

void preprocessing(){

}

bool bfs(pi& node, vector<vector<char>>&mat){
    q.push(node);
    pi n;
    while(!q.empty()){
        
        n = q.front();
        debug(n.ff);
        debug(n.ss);
        q.pop();
        if(n==en)break;
        int y = n.ff;
        int x = n.ss;
        if(visited[n.ff+1][n.ss]==0 && (mat[n.ff+1][n.ss]=='.'|| mat[n.ff+1][n.ss]=='B')){
            visited[n.ff+1][n.ss]=4;
            q.push({y+1, x});
        }
        if(visited[n.ff-1][n.ss]==0 && (mat[n.ff-1][n.ss]=='.'|| mat[n.ff-1][n.ss]=='B')){
            visited[n.ff-1][n.ss]=3;
            q.push({y-1, x});
        }
        if(visited[n.ff][n.ss+1]==0 && (mat[n.ff][n.ss+1]=='.'|| mat[n.ff][n.ss+1]=='B')){
            visited[n.ff][n.ss+1]=2;
            q.push({y, x+1});
        }
        if(visited[n.ff][n.ss-1]==0 && (mat[n.ff][n.ss-1]=='.'|| mat[n.ff][n.ss-1]=='B')){
            visited[n.ff][n.ss-1]=1;
            q.push({y, x-1});
        }
    }
    if(n!=en){
        return 0;
    }
    return 1;


}

int pathfind(pi n, string& path){
    debug(n.ff);
    debug(n.ss);
    if(n==st){
        return 0;
    }
    debug(path)
    int y= n.ff;
    int x = n.ss;
        if(visited[n.ff][n.ss]==4){
            path.push_back('D');
            return 1+pathfind({y-1,x}, path);
        }
        if(visited[n.ff][n.ss]==3){
            path.push_back('U');
            return 1+pathfind({y+1,x}, path);
        }
        if(visited[n.ff][n.ss]==2){
           
            path.push_back('R');
            return 1+pathfind({y,x-1}, path);
        }
        if(visited[n.ff][n.ss]==1){
            path.push_back('L');
            return 1+pathfind({y,x+1}, path);
        }
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
    bool xx = bfs(st, mat);
    debug(visited[2][2])
    if(!xx){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        ansi = pathfind(en, path);
        cout<<ansi<<endl;
        reverse(All(path));
        cout<<path<<endl;
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
