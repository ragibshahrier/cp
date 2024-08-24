#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define int ll 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; i<n; i++)
#define gp <<" "

// #define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__ gp<<#n gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------


bool cmp(pi a, pi b){
    if((a.first-a.second) != (b.first-b.second)){
        return (a.first-a.second) < (b.first-b.second);
    }
    return a.first < b.first;
}
bool cmp2(int a, int b){
    return b<a;
}

void solve(){
    int n, m;
    cin>>n>>m;
    vpi ab(n);
    rep(i, 0, n){
        cin>>ab[i].first;
    }
    rep(i, 0, n){
        cin>>ab[i].second;
    }
    

    sort(ab.begin(), ab.end(), cmp);
    
    map<int, int> mp;
    vi met(m);
    rep(i, 0, m){
        int x;
        cin>>x;
        
        mp[-x]++;
    }
    //sort(met.begin(),met.end(), cmp2);
    int j=0, i=0;
    ll exp=0;
    
    while(i<n){
        debug(ab[i].first)
        debug(ab[i].second)
        int x = -(mp.begin()->first);
        ll y = (mp.begin()->second);
        debug(x)
        if(ab[i].first> x){
            i++;
        }
        else{
            int diff = ab[i].first-ab[i].second;
            exp+=(((x-ab[i].first)/diff+1)*2LL)*(y);
            x-= (((x-ab[i].first)/diff)+1)*diff;
            //i++;
            
            mp.erase(mp.begin());
            if(mp.find(-x)!=mp.end())mp[-x]+=y;
            else mp[-x]=y;
        }
        debug(exp)
    }

    cout<<exp<<endl;




}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}
