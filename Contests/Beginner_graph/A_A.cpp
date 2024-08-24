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

struct Node{
    int x, y, num;
    // vector<Node>nei;
};
vector<Node>nodes;

vi visited(N);

void preprocessing(){

}


void dfs(Node& node, vector<vector<char>>& mat, map<pi,int>&mp){
    visited[node.num]=1;
    debug(node.num)
    int num1 = mp[{node.x,node.y+1}];
    int num2 = mp[{node.x,node.y-1}];
    int num3 = mp[{node.x-1,node.y}];
    int num4 = mp[{node.x+1,node.y}];
    debug(num1)
    debug(num2)
    debug(num3)
    debug(num4)
    if(num1>0 && visited[num1]!=1){
        dfs(nodes[num1], mat, mp);
    }
    if(num2>0 && visited[num2]!=1){
        dfs(nodes[num2], mat, mp);
    }
    if(num3>0 && visited[num3]!=1){
        dfs(nodes[num3], mat, mp);
    }
    if(num4>0 && visited[num4]!=1){
        dfs(nodes[num4], mat, mp);
    }
    
}

void solve(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<char>>mat(n+2,vector<char>('#',m+2));
    map<pi,int>mp;
    int num=1;
    Node nnn = {-2,-2,-2};
    nodes.push_back(nnn);
    rep(i,1,n+1){
        rep(j,1,m+1){
            cin>>mat[i][j];
            if(mat[i][j]=='.'){
                Node nn={i,j,num};
                mp[{i,j}]=num;
                // debug(i)
                // debug(j)
                // debug(num)
                num++;
                nodes.push_back(nn);
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
        if(visited[el.num]==0){
            debug(el.num)
            debug(cnt)
            dfs(el,mat,mp);
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
