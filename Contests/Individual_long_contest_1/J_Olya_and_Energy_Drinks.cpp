#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
 
typedef long long ll;
 
#define int long long
 
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
#define bitcnt(x) ((sizeof(x) <= sizeof(int)) ? (32 - __builtin_clz(x)) : (64 - __builtin_clzll(x)))

// #define DEBG

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

struct node{
    int x;
    int y;
    int dirs;
};


void preprocessing(){

}

void solve(int testcases){
    int n,m,k;

    cin>>n>>m>>k;

    vvi grid(n+4,vi(m+4));
    vvi dist1(n+4,vi(m+4, inf));
    vvi dist2(n+4,vi(m+4, inf));
    vvi dist3(n+4,vi(m+4, inf));
    vvi dist4(n+4,vi(m+4, inf));

    vector<vvi>dists = {dist1, dist2, dist3, dist4};
    debug(1)
    rep(i,0,n){
        string s;
        cin>>s;

        rep(j,0,m){
            if(s[j]=='.'){
                grid[i+1][j+1]=1;
            }
        }
    }

    int x,y,a,b;
    cin>>x>>y>>a>>b;

    queue<node>q;
    node st = {x,y,0};
    q.push(st);
    st.dirs =1;
    q.push(st);
    st.dirs =2;
    q.push(st);
    st.dirs =3;
    q.push(st);

    dists[0][x][y] = 0;
    dists[1][x][y] = 0;
    dists[2][x][y] = 0;
    dists[3][x][y] = 0;

    pi dirs[4] = {{0,1}, {1,0}, {0,-1},{-1,0}};
    int iii = 1;
    int cnt = 0;
    int cnt2 = 0;
    int visited[n+1][m+1][4];
    memset(visited, 0, sizeof(visited));

    while(!q.empty()){
        node now = q.front();
        q.pop();
        int i = now.dirs;
        

        pi dir = dirs[i];
        pi cell = {now.x,now.y};
        int tonow = dists[i][now.x][now.y];
        rep(kk,0,4){
            tonow = min(tonow, dists[kk][now.x][now.y]);

        }
        vi newdd(2);
        if(dir.ff==0){
            newdd[0] = 1;
            newdd[1] = 3;
        }
        if(dir.ss==0){
            newdd[0] = 0;
            newdd[1] = 2;
        }

        rep(j,0,k){
            cnt++;
            cell.ff+=dir.ff;
            cell.ss+=dir.ss;
            // debug(now.x)
            // debug(now.y)
            debug(i)
            // debug(j)
            debug(cell.ff)
            debug(cell.ss)
            // debug(grid[1][2])
            if(cell.ff<=0 || cell.ss<=0 || cell.ff>n || cell.ss>m || !grid[cell.ff][cell.ss])break;
            // debug(1)
            if(dists[i][cell.ff][cell.ss]!=inf)break;
            dists[i][cell.ff][cell.ss] = tonow+1;
            // debug(now.x)
            // debug(now.y)
            // debug(i)
            // debug(j)
            // debug(cell.ff)
            // debug(cell.ss)
            // debug(tonow)
            debug(dists[i][cell.ff][cell.ss])
            node temp;
            temp.x = cell.ff;
            temp.y = cell.ss;
            temp.dirs = newdd[0];
            if(!visited[temp.x][temp.y][temp.dirs]){
                q.push(temp);
                cnt2++;
            }
            visited[temp.x][temp.y][temp.dirs]=1;
            
            temp.dirs = newdd[1];
            if(!visited[temp.x][temp.y][temp.dirs]){
                q.push(temp);
                cnt2++;
            }
            visited[temp.x][temp.y][temp.dirs]=1;
            
            
            
        } 
        if(!(cell.ff<=0 || cell.ss<=0 || cell.ff>n || cell.ss>m || !grid[cell.ff][cell.ss])){
            node temp;
            temp.x = cell.ff;
            temp.y = cell.ss;
            temp.dirs = i;
            
            if(!visited[temp.x][temp.y][temp.dirs]){
                q.push(temp);
                cnt2++;
            }
            visited[temp.x][temp.y][temp.dirs]=1;

        }
        // for(auto i:dd){
        // }
    }

    // cout<<cnt<<endl;
    // cout<<cnt2<<endl;

    // rep(k,0,4){
    //     rep(i,1,n+1){
    //         rep(j,1,m+1){
    //             cout<<dists[k][i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl<<endl;

    // }

    int ans = inf;
    rep(i,0,4){
        ans = min(ans,dists[i][a][b]);
    }

    if(ans==inf){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }


}

int32_t main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
