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
#define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

/*

ll func(int remaining, int n, vi& h, int x, int y){
    if(remaining<=0)return 0;
    int ii = n-remaining;
    ll ans = n*x;
    int jj=0;
    for(int i=ii+1; i<n; i++){
        debug(i)
        debug(ii)
        debug(h[i])
        debug(h[ii])
        if(h[i]>=h[ii]){

            ll tempans = func(n-i-1, n, h, x, y);
            debug(tempans)
            tempans+=y+jj*x;
            debug(ii)
            debug(jj)
            jj++;
            ans = min(ans,tempans);
            debug(ii)
            debug(n-i-1)
            debug(jj)
            debug(tempans)
            debug(ans)
            debug(i)
            debug(remaining)
        }
    }
    ll tempans = func(remaining-1, n, h, x, y)+x;
    ans = min(ans,tempans);
    debug(ii)
    debug(ans)
    return ans;
}


*/

map<int,int>mp, mn;
vector<vi> obs(507, vi(507));
vector<vi>dp(507,vi(507,-1));


ll func(int start, int end, int n, vi& h, int x, int y){
    
    debug(start)
    debug(end)


    if(start>=n)return 0;
    if(start>end)return 0;
    if(start==end)return dp[start][end]=x;

    if(dp[start][end]!=-1)return dp[start][end];
    
    ll ans = (end-start+1)*x;
    
    debug(start)
    debug(end)
    
    ll temp1 = func(start, end-1, n, h, x, y)+x;
    
    
    debug(start)
    debug(end)
    debug(temp1)
    
    ll temp2 = func(start+1, end, n, h, x, y)+x;
    
    
    debug(start)
    debug(end)
    
    ll temp4 = func(start+1, end-1, n, h, x, y)+x+x;
    
    
    debug(start)
    debug(end)
    
    ll temp3=1e15, temp5=1e15;
    if(mn[start]==end){
        temp3=y;
    }
    else if(mn[start]<=mp[end]){
        temp3 = func(mn[start], mp[end], n, h, x, y)+y;
    }
    
    
    debug(start)
    debug(end)
    
    if(start<end) temp5 = obs[start][end]*x+y;
    ll temp6= func(start, mn[start], n, h, x, y) + func(mn[start]+1, end, n, h, x, y);
    
    
    debug(start)
    debug(end)
    

    //ll tempans = func(remaining-1, n, h, x, y)+x;
    ans = min({ans,temp1,temp2,temp3,temp4,temp5, temp6});
    debug(ans)
    debug(1111111111111111)
    debug(" ")
    debug(start)
    debug(end)
    debug(ans)
    debug(" ")
    debug(111111111111111111)
    return dp[start][end] = ans;
}






void solve(){
    int n;
    int x,y;
    cin>>n>>x>>y;
    vi h(n);
    rep(i,0,n){
        cin>>h[i];
    }
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(h[i]<=h[j]){
                mn[i]=j;
                break;
            }
        }
    }
    for(int i=n-1; i>=0; i--){
        for(int j=i-1; j>=0; j--){
            if(h[i]<=h[j]){
                mp[i]=j;
                break;
            }
        }
    }
    for(int i=0; i<n; i++){
        rep(j,i+2,n){
            obs[i][j]=obs[i][j-1];
            if(h[j-1]>=h[i]){
                obs[i][j]++;
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     rep(j,0,n){
    //         debug(i)
    //         debug(j)
    //         debug(obs[i][j])
    //     }
    // }


    ll ans = func(0, n-1,n,h,x,y);

    cout<<ans<<endl;

    mp.clear();
    mn.clear();

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
