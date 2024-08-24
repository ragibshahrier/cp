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

ll dfs(vector<vi>& tree, vll& val, int node){
    debug(node)
    debugc(val)
    ll mini = INF;
    for(auto el : tree[node]){
        mini = min(mini, dfs(tree, val, el));

    }
    if(tree[node].size() == 0){
        return val[node];
    }
    if(node == 1){
        return (val[1]+mini);
    }
    if(mini<val[node]){
        return val[node] = mini;
    } 
    return val[node] += (mini - val[node])/2; 
}

void solve(){
    int n;
    cin>>n;
    vll val(n+3);
    vector<vi> tree(n+3);
    rep(i,1,n+1){
        cin>>val[i];
    }
    debug(1)
    rep(i,2,n+1){
        int x;
        cin>>x;
        tree[x].push_back(i);
    }
    ll ans = dfs(tree, val, 1);
    cout<< ans<<endl;

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
