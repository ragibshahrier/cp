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

string longest;

string var="";

string a,b;

bool checksub(string& x, string& y){
    int j=0,k=0;
    for(; j<x.length()&& k<y.length(); ){
        if(x[j]==y[k]){
            j++;
        }
        k++;
    }
    if(j==x.length()){
        return 1;
    }return 0;
}

string func(int st, int len){
    if(st>=a.length())return var;
    if(!checksub(var, b)){
        return "";
    }
    debug(var)
    string temp1 = func(st+1, len);
    var.push_back(a[st]);
    debug(var)
    string temp2 = func(st+1, len+1);
    var.pop_back();
    debug(temp1)
    debug(temp2)
    if(temp1.length()>temp2.length()){
        return temp1;
    }else{
        return temp2;
    }
    // if(checksub(temp, b)){
    //     return temp;
    // }
    // return y;

}


void solve(){
    cin>>a>>b;
    if(a.length()>b.length()){
        string temp = b;
        b=a;
        a = temp;
    }
    string ans = func(0, 0);
    cout<<ans<<endl;

    //cout<<longest<<endl;
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
