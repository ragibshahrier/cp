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

void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll>p(n+7), x(m+2), pacc(n+2);
    vector<double> near(n+7);
    x[0]=INT_MIN;
    rep(i,0,n){
        cin>>p[i];
    }
    rep(i,1,m+1){
        cin>>x[i];
    }
    debug(x[1])
    x[m+1]=1e15;
    sort(x.begin(),x.end());

    int ii=0, jj=1;
    int loch = 0;
    for(int i=0; i<n;){
        if(loch<=x[jj]){
            near[i]=min(abs(loch-x[jj]), abs(loch-x[jj-1]));
            debug(near[i])
            debug(x[jj])
            i++;
            loch=i*100;
        }else{
            jj++;
        }
    }

    rep(i,0,n+1){
        pacc[i]=p[i-1]+pacc[i-1];
    }

    int left=0, right=0;
    ll tempans=0, ans=0;
    double my=0;
    

    while(right<n && left<n){
        debug(left)
        debug(right)
        debug(near[left])
        debug(near[right])
        debug(my)
        if(near[left]>abs(left*100-my) && near[right]>abs(right*100-my)){
            debug(1)
            tempans = pacc[left+1]-pacc[right];
            left++;
        }
        else if(near[left]<=abs(left*100-my)){
            if(near[left]==0){
                right=left+1;
                left=right;
                my=right*100;
            }else{
                my=left*100-near[left]+0.1;
            }
        }
        else if(near[right]<abs(right*100-my)){
            right++;
        }
        ans = max(ans,tempans);
        debug(ans)

        


    }
    cout<<ans;



/*

    int ii = 0, jj=0;
    ll ans=0, tempans=0;
    while(ii<n){
        if(x[jj]==ii*100){
            ii++;
            jj++;
            tempans=0;
            debug(tempans)
        }
        else if(x[jj]<ii*100){
            tempans=0;
            jj++;
            debug(tempans)
        }
        else{
            tempans+=p[ii];
            ii++;
            debug(tempans)
        }
        ans = max(tempans,ans);

    }
    cout<<ans;*/

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
