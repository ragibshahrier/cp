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



vector<vi>visitedm(1003, vi(1003, inf));
vector<vpi>visited(1003, vpi(1003, {-1,inf}));
pi st;

ll cnt=0;


void preprocessing(){

}

void bfs(vpi& mons,vector<vector<char>>&mat){
    // debug(node.ff)
    // debug(node.ss)
    queue<pi>q;
    for(auto el:mons){
        // cnt++;
        visitedm[el.ff][el.ss]=0;
        q.push(el);
    }
    pi nd;
    while(!q.empty()){
        // cnt++;
        debug(cnt)
        
        nd = q.front();
        int a = nd.ff;
        int b = nd.ss;
        q.pop();
        if(visitedm[a+1][b]>visitedm[a][b]+1 && mat[a+1][b]!='#'){
            visitedm[a+1][b] = visitedm[a][b]+1;
            q.push({a+1,b});
        }
        if(visitedm[a-1][b]>visitedm[a][b]+1 && mat[a-1][b]!='#'){
            visitedm[a-1][b] = visitedm[a][b]+1;
            q.push({a-1,b});
        }
        if(visitedm[a][b+1]>visitedm[a][b]+1 && mat[a][b+1]!='#'){
            visitedm[a][b+1] = visitedm[a][b]+1;
            q.push({a,b+1});
        }
        if(visitedm[a][b-1]>visitedm[a][b]+1 && mat[a][b-1]!='#'){
            visitedm[a][b-1] = visitedm[a][b]+1;
            q.push({a,b-1});
        }

    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    // vector<vector<char>>mat(n+5, vector<char>(m+5,'#'));
    vector<vector<char>>mat(n+2,vector<char>(m+2,'#'));
    debug(1)
    vpi mons;
    

    rep(i,1,n+1){
        rep(j,1,m+1){
            // cnt++;
            // debug(i)
            // debug(j)
            cin>>mat[i][j];
            if(mat[i][j]=='M'){
                mons.push_back({i,j});

            }else if(mat[i][j]=='A'){
                st = {i,j};
            }
            if((i==1||i==n||j==1||j==m)&&mat[i][j]!='#'&&mat[i][j]!='M'){
                mat[i][j]='B';
            }
        }
        
    }
    // rep(i,1,n+1){
    //     rep(j,1,m+1){
            
    //         cout<<mat[i][j];
    //     }
    //     cout<<endl;
    // }
debug(cnt)
    bfs(mons, mat);
debug(cnt)
    debug(st.ff)
    debug(st.ss)
    pi node = st;
    visited[node.ff][node.ss].ss=0;
    queue<pi>q;
    q.push(node);
    string ans = "";
    pi nd;
    bool r = 0;
    while(!q.empty()){
        // rep(i,1,n+1){
        // rep(j,1,m+1){
        //     if(visited[i][j].ff>0)cout<<gp;
        //     cout<<visited[i][j].ff;
        // }
        // cout<<endl;
    // }
        // cout<<endl;
        // cnt++;
        // debug(cnt)
        nd = q.front();
        int a = nd.ff;
        int b = nd.ss;
        // debug(a)
        // debug(b)
        q.pop();
        if(mat[a][b]=='B'){
            r=1;
            break;
        }
        if(visitedm[a+1][b]>visited[a][b].ss+1 && visited[a+1][b].ss>visited[a][b].ss && mat[a+1][b]!='#'){

            visited[a+1][b].ss = visited[a][b].ss+1;
            visited[a+1][b].ff = 4;
            q.push({a+1,b});
        }
        if(visitedm[a-1][b]>visited[a][b].ss+1 && visited[a-1][b].ss>visited[a][b].ss && mat[a-1][b]!='#'){
            visited[a-1][b].ss = visited[a][b].ss+1;
            visited[a-1][b].ff = 3;
            q.push({a-1,b});
        }
        // if(visitedm[a][b+1]>visited[a][b].ss+1 && mat[a][b+1]!='#'){
        //     visited[a][b+1].ss = visited[a][b].ss+1;
        //     visited[a][b+1].ff = 2;
        //     q.push({a,b+1});
        // }
        if(visitedm[a][b-1]>visited[a][b].ss+1 && visited[a][b-1].ss>visited[a][b].ss && mat[a][b-1]!='#'){
            visited[a][b-1].ss = visited[a][b].ss+1;
            visited[a][b-1].ff = 1;
            q.push({a,b-1});
        }
        if(visitedm[a][b+1]>visited[a][b].ss+1 && visited[a][b+1].ss>visited[a][b].ss && mat[a][b+1]!='#'){
            visited[a][b+1].ss = visited[a][b].ss+1;
            visited[a][b+1].ff = 2;
            q.push({a,b+1});
        }

    }
    if(!r){
        debug(cnt)
        cout<<"NO"<<endl;return;
    }
    pi i = nd;
    while(i!=st){
        // cnt++;
        debug(cnt)
        int a = i.ff;
        int b = i.ss;
        debug(a)
        debug(b)
        debug(ans)
        
        if(visited[a][b].ff==1){
            i.ss+=1;
            ans.push_back('L');
        }
        else if(visited[a][b].ff==2){
            i.ss-=1;
            ans.push_back('R');
        }
        else if(visited[a][b].ff==3){
            i.ff+=1;
            ans.push_back('U');
        }
        else if(visited[a][b].ff==4){
            i.ff-=1;
            ans.push_back('D');
        }
    }
    debug(n)
    debug(m)
    // rep(i,1,n+1){
    //     rep(j,1,m+1){
    //         if(visited[i][j].ff>0)cout<<gp;
    //         cout<<visited[i][j].ff;
    //     }
    //     cout<<endl;
    // }

    reverse(All(ans));
    // cnt+=ans.size();
    debug(cnt)
    cout<<"YES"<<endl<<ans.size()<<endl<<ans;







}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
