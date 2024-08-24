#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define rep(ii,n) for(int ii=0; i<n; i++)
#define debug(n) cout<<n<<endl;


void solve(){
    string s;
    int n;
    
    
    cin>>n>>s;
    int mini = 100, minii=0;
    ll ans=INT_MAX;
    for(int j=0; j<n-1; j++){
        /*if(mini>((s[i]-'0')*10+((s[i+1])-'0'))){
            mini = (s[i]-'0')*10+((s[i+1])-'0');
            minii = i;
        }*/
        mini = (s[j]-'0')*10+((s[j+1])-'0');
        minii = j;
        vi nums;
        for(int i=0; i<n; i++) {
            if(i==minii){
                nums.push_back(mini);
                i++;
            }
            else{
                nums.push_back(s[i]-'0');
            }

        }
        
        /*for(auto el: nums){
            cout<<el<<" ";
        }
        cout<<endl;*/
        for(auto el: nums){
            if(el==0){
                cout<<0<<endl;
                return;
            }
        }


        ll tempans=0;
        bool hasone=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                hasone=1;

            }else tempans+=nums[i];
        }
        if(hasone && tempans==0) tempans=1;
        ans = min(ans, tempans);

    }/*
    vi nums;
    for(int i=0; i<n; i++) {
        if(i==minii){
            nums.push_back(mini);
            i++;
        }
        else{
            nums.push_back(s[i]-'0');
        }
    }
    cout<<minii<<"    ";
    for(auto el:nums){
        cout<<el<<" ";
    }
    cout<<endl;*/
    cout<<ans<<endl;

    
    
}



 
int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
