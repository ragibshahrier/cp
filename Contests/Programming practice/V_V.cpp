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

//#define DEBG

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
    int h,w,t;
    cin>>h>>w>>t;
    vvll mat(h+4, vll(w+4,inf));
    vvll matmin(h+4, vll(w+4,inf));
    rep(i,2,h+2){
        rep(j,2,w+2){
            cin>>matmin[i][j];
        }
    }
    // rep(i,2,h+2){
    //     rep(j,2,w+2){
    //         matmin[i][j] = mat[i][j];
    //     }
    // }
    queue<pi>q;
    rep(i,1,h+3){
        matmin[i][1]=inf;
        mat[i][1]=0;
        q.push({i,1});
        matmin[i][w+2]=inf;
        mat[i][w+2]=0;
        q.push({i,w+2});
    }
    rep(j,2,w+2){
        matmin[1][j]=inf;
        mat[1][j]=0;
        q.push({1,j});
        matmin[h+2][j]=inf;
        mat[h+2][j]=0;
        q.push({h+2,j});
    }
    
    while(!q.empty()){
        pi nd = q.front();
        q.pop();

        if(mat[nd.ff-1][nd.ss]>mat[nd.ff][nd.ss] && matmin[nd.ff-1][nd.ss]<mat[nd.ff][nd.ss]){
            mat[nd.ff-1][nd.ss]=mat[nd.ff][nd.ss];
            q.push({nd.ff-1,nd.ss});
        }
        if(mat[nd.ff+1][nd.ss]>mat[nd.ff][nd.ss] && matmin[nd.ff+1][nd.ss]<mat[nd.ff][nd.ss]){
            mat[nd.ff+1][nd.ss]=mat[nd.ff][nd.ss];
            q.push({nd.ff+1,nd.ss});
        }
        if(mat[nd.ff][nd.ss-1]>mat[nd.ff][nd.ss] && matmin[nd.ff][nd.ss-1]<mat[nd.ff][nd.ss]){
            mat[nd.ff][nd.ss-1]=mat[nd.ff][nd.ss];
            q.push({nd.ff,nd.ss-1});
        }
        if(mat[nd.ff][nd.ss+1]>mat[nd.ff][nd.ss] && matmin[nd.ff][nd.ss+1]<mat[nd.ff][nd.ss]){
            mat[nd.ff][nd.ss+1]=mat[nd.ff][nd.ss];
            q.push({nd.ff,nd.ss+1});
        }
    }
    rep(i,2,h+2){
        rep(j,2,w+2){
            cout<<mat[i][j]<<gp;
        }
        cout<<endl;
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
