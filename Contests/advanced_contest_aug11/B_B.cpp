#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vvi vector<vi>
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


vvi mat(1027,vi(1027));


void constr(int n){
    if(n==4){
        mat[0][0]=1;mat[0][1]=2;mat[0][2]=3;mat[0][3]=4;
        mat[1][0]=2;mat[1][1]=1;mat[1][2]=4;mat[1][3]=3;
        mat[2][0]=3;mat[2][1]=4;mat[2][2]=1;mat[2][3]=2;
        mat[3][0]=4;mat[3][1]=3;mat[3][2]=2;mat[3][3]=1;
        return;
    }
    constr(n/2);
    rep(i,0,n/2){
        rep(j,n/2,n){
            mat[i][j]=n/2+mat[i][j-n/2];
        }
    }
    rep(i,n/2,n){
        rep(j,0,n/2){
            mat[i][j]=mat[i-n/2][j+n/2];
        }
    }
    rep(i,n/2,n){
        rep(j,n/2,n){
            mat[i][j]=mat[i-n/2][j-n/2];
        }
    }

}


void preprocessing(){
    constr(1024);
}

void solve(int t){
    if(t)cout<<endl;
    int n,k;
    cin>>n>>k;
    if(k>=n){
        cout<<"Impossible";return;
    }
    vi tobe;
    rep(i,1,n){
        bool b=1;
        rep(j,0,n){
            if(mat[i][j]>n){
                b=0;
                break;
            }
        }
        if(b)tobe.push_back(i);
    }
    debugc(tobe)
    if(tobe.size()<k){
        cout<<"Impossible";return;
    }
    int m = k;
    rep(kk,0,m){
        int i = tobe[kk];
        rep(j,0,n-1){
            cout<<mat[i][j]<<gp;
        }
        cout<<mat[i][n-1];
        if(kk!=m-1)cout<<endl;
    }


}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,0,t)solve(i);
    return 0;
}
