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

const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;


//----------------------CODE STARTS HERE-------------------




void preprocessing(){

}

void dfs(vector<vi>& nbr, vi& visited, int curr, int& a, int col, set<int>& blue, set<int>& green){
    debug(curr)
    debugc((nbr[curr]))
    visited[curr]=col;
    if(col==1){
        blue.insert(curr);
    }
    if(col==2){
        green.insert(curr);
    }
    for(auto el: nbr[curr]){
        if(visited[el]==0){
            dfs(nbr, visited, el, a, 3-col, blue, green);
        }else{
            if(visited[el]==col){
                a=1;
            }
        }
    }
}

void solve(){
    int n, m;
    cin>>n>>m;
    vector<vi> nbr(n+1);
    set<int> blue;
    set<int> green;
    vi visited(n+1);
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        nbr[x].push_back(y);
        nbr[y].push_back(x);

    }
    int a = 0;
    debug(1)
    dfs(nbr, visited, 1, a, 1, blue, green);
    debug(1)

    if(a){
        cout<<"Alice"<<endl;
        while(n--){
            cout<<1<<" "<<2<<endl;
            cout.flush();

            int w,z;

            cin>>w>>z;
        }
    }else{
        cout<<"Bob"<<endl;
        while(n--){
            int w,z;
            cin>>w>>z;
            if((w==1 || z==1)&& blue.size()>0){
                auto it = blue.begin();
                cout<<*it<<gp<<1<<endl;
                cout.flush();
                blue.erase(it);
                continue;
            }
            if((w==2 || z==2)&& green.size()>0){
                auto it = green.begin();
                cout<<*it<<gp<<2<<endl;
                cout.flush();
                green.erase(it);
                continue;

            }
            if(blue.size()==0){
                auto it = green.begin();
                cout<<*it<<gp<<3<<endl;
                cout.flush();
                green.erase(it);
                // continue;
            }else{
                auto it = blue.begin();
                cout<<*it<<gp<<3<<endl;
                cout.flush();
                blue.erase(it);
                // continue;
            }

        }
    }




}

int main(){
    // fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
