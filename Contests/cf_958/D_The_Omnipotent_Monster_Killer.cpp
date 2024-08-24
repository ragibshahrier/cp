#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; ii<n; ii++)
#define gp " "
// #define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------


void mark(int n, int x, vector<vi>&connections, vll& sumv, vll& nodes, vi& visited){
    //team[n]=x;
    sumv[x]+=nodes[n];
    visited[n]=1;

    debug(n)
    for(auto el:connections[n]){
        if(visited[el]==0)mark(el, 1-x, connections, sumv, nodes, visited);
    }
}

void solve(){
    int n;
    cin>>n;
    vll nodes(n+1);
    ll sum = 0;
    rep(i,1,n+1){
        cin>>nodes[i];
        sum+=nodes[i];
    }
    vector<vi>connections(n+1);
    rep(i,0,n-1){
        int n1,n2;
        cin>>n1>>n2;
        connections[n1].push_back(n2);
        connections[n2].push_back(n1);
    }
    vll sumv(2);
    vi team(n+1);
    team[1]=1;
    int i=1;
    vi visited(n+1);
    
    mark(1, 0, connections, sumv, nodes, visited);
    debug(sumv[0])
    debug(sumv[1])
    
    ll ans = sumv[0]+sumv[1]+min(sumv[0],sumv[1]);
    cout<<ans<<endl;
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
