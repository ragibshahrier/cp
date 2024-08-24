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
//#define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------


int dp[10000000];

int func(int n, int price[]){
    if(n<=0)return 0;
    if(dp[n]!=-1)return dp[n];
    int ans=0;
    for(int i=0; i<n; i++){
        ans = max(ans, func(n-(i+1), price)+price[i]);
    }
    return dp[n]=ans;
}

int cutRod(int price[], int n) {
    memset(dp, -1, sizeof(dp));
    int ans;
    ans = func(n, price);
    return ans;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    int arr[]={3, 5, 8, 9, 10, 17, 17, 20};
    while(t--)cout<<cutRod(arr, 8);
    return 0;
}
