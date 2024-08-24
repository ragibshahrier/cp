#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5000+7, C=5000+7;

vector<vector<int>>dp(N, vector<int>(C,-1));

int func(int amount, int coinind, vector<int>& coins){
    
    int ans=0;
    if(amount<0)return 0;
    if(amount==0)return 1;
    // cout<<dp[amount][coinind]<<endl;
    if(dp[amount][coinind]>=0)return dp[amount][coinind];
    for(int i=coinind; i<coins.size(); i++){
        int coin = coins[i];
        ans+=func(amount-coin, i, coins);
        
    }

    return dp[amount][coinind]=ans;
}


int change(int amount, vector<int>& coins) {
    
    int ans = 0;
    // for(auto coin:coins){
    // }
    ans=func(amount, 0, coins);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<int>coins = {3,5,7,8,9,10,11};
    vector<int>coins = {99,1};

    int amount = 100;
    int ans = change(amount, coins);
    cout<<ans<<endl;

    return 0;
}
