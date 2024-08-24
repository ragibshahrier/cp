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



bool cmp(pair<int,string>p1, pair<int,string>p2){
    if(p1.first==p2.first){
        return p1.second<p2.second;
    }
    return p1.first>p2.first;
}

void solve(){
    int n,m;
    cin>>n>>m;
    map<string, int>chef, con;
    map<string,string> chcon;
    rep(i,0,n){
        string s1,s2;
        cin>>s1>>s2;
        chcon[s1]=s2;
    }
    rep(i,0,m){
        string s1;
        cin>>s1;
        chef[s1]++;
        con[chcon[s1]]++;
    }
    vector<pair<int,string>>v1,v2;
    pair<int,string>ansp1={0,""},ansp2={0,""};
    for(auto el:chef){
        pair<int,string> temp = {el.second,el.first};
        if(cmp(temp,ansp1)){
            ansp1=temp;
        }
    }
    for(auto el:con){
        pair<int,string> temp = {el.second,el.first};
        if(cmp(temp,ansp2)){
            ansp2=temp;
        }
    }
    


    cout<<ansp2.second<<endl<<ansp1.second<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
