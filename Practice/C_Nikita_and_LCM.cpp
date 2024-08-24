#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcm(ll LCM, ll a){
    return (LCM*a)/__gcd(LCM,a);
}




ll cnt(vector<pair<int,int>>& v, int i){
    ll LCM=0, count=0; 
    for(auto el:v){
        int j=el.first, k=el.second;
        if(i%j==0){
            if(LCM==0)LCM=j;
            else LCM=lcm(LCM, j);
            count+=k;
        }
    }
    if(LCM!=i)count=0;
    return count;

}

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto& i:v)cin>>i;
    int maxi=*max_element(v.begin(), v.end());
    map<int,int>m;
    for(auto i:v)m[i]++;
    vector<pair<int,int>>v2;
    for(auto& el:m)v2.push_back(el);
    ll ans=0, LCM=0;
    for(auto el:v2){
        if(LCM==0)LCM=el.first;
        else LCM=lcm(LCM, el.first);
        if(LCM>maxi){
            cout<<n<<endl;
            return;
        }
    }
    
    for(int i=1; i*i<=maxi; i++){
        if(maxi%i==0){
            if(m[i]==0)ans=max(ans,cnt(v2, i));
            if(m[maxi/i]==0)ans=max(ans,cnt(v2, maxi/i));
            //cout<<i<<" "<<ans<<endl;
        }
        
    }
    cout<<ans<<endl;


}


int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
