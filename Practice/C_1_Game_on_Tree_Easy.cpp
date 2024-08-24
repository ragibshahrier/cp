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


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(){
    int n,t;
    cin>>n>>t;
    vector<vi> hsh(n+1);
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        hsh[x].push_back(y);
        hsh[y].push_back(x);

    }
    vi leaf;
    rep(i,1,n+1){
        if(hsh[i].size()==1){
            leaf.push_back(i);
        }
    }
    vi hsh2(n+1);
    vi arr;
    arr.push_back(leaf[0]);
    int i=leaf[0];
    hsh2[i]=1;
    while(i!=leaf[1]){
        debug(i)
        if(hsh2[hsh[i][0]]==0){
            hsh2[hsh[i][0]]=1;
            i=hsh[i][0];
            arr.push_back(i);
        }else{
            hsh2[hsh[i][1]]=1;
            i=hsh[i][1];
            arr.push_back(i);

        }
    }
    // arr.push_back(leaf[1]);
    debugc(arr)
    map<int,int>mp;
    for(int i=0; i<arr.size();i++){
        mp[arr[i]]=i;
    }
    while(t--){
        int x;
        cin>>x;
        if((arr.size() & 1) ==0){
            cout<<"Ron"<<endl;
            continue;
        }
        if((mp[x] & 1)==0){
            cout<<"Hermione"<<endl;
        }else{
            cout<<"Ron"<<endl;
        }
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
