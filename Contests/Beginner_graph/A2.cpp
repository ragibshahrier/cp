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

const int N = 1e6+7;

// struct Node{
//     int x, y, num;
//     // vector<Node>nei;
// };
// vector<Node>nodes;


vector<pi> nodes;
vector<vi> visited(1005,vi(1005));

void preprocessing(){

}


void dfs(pi& node, vector<vector<char>>& mat){
    visited[node.ff][node.ss]=1;
    // debug(node.num)
    int x= node.ff;
    int y= node.ss;
    
    
    if(mat[x][y+1]=='.' && visited[x][y+1]==0){
        pi co = {x,y+1};
        dfs(co,mat);
    }
    if(mat[x][y-1]=='.' && visited[x][y-1]==0){
        pi co = {x,y-1};
        dfs(co, mat);
    }
    if(mat[x-1][y]=='.' && visited[x-1][y]==0){
        pi co = {x-1,y};
        dfs(co, mat);
    }
    if(mat[x+1][y]=='.' && visited[x+1][y]==0){
        pi co = {x+1,y};
        dfs(co, mat);
    }
    
    
}

void solve(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<char>>mat(n+7,vector<char>(m+7,'#'));
    // map<pi,int>mp;
    int num=1;
    // Node nnn = {-2,-2,-2};
    // nodes.push_back(nnn);
    rep(i,1,n+1){
        rep(j,1,m+1){
            cin>>mat[i][j];
            if(mat[i][j]=='.'){
                nodes.push_back({i,j});

            }
        }
    }
    num=1;
    // rep(i,1,n+1){
    //     rep(j,1,m+1){
    //         cin>>mat[i][j];
    //         if(mat[i][j]=='.'){
    //             Node nn=nodes[num];
    //             num++;
    //             if()
    //         }
    //     }
    // }
    int cnt=0;
    for(auto& el:nodes){
        if(visited[el.ff][el.ss]==0){
            debug(el.ff)
            debug(cnt)
            dfs(el,mat);
            cnt++;
        }
    }
    cout<<cnt<<endl;

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
