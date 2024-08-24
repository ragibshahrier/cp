#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; i<n; i++)
#define gp <<" "
//#define DEBG
const double PI=3.14159;

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

double cosd(int a){
    return cos(a*(PI/180));
}
double sind(int a){
    return sin(a*(PI/180));
}
double tand(int a){
    return tan(a*(PI/180));
}

void solve(){
    int v,r, t1,t2;
    cin>>v>>r>>t1>>t2;
    int g=32;
    
    double dis = ((v*1.0)/g)*sind(2*t2)*v*1.0;
    if(dis*cosd(t1)<36){
        cout<<"Oh No!\n";
        return;
    }
    if(abs(tand(t1))>=(12*1.0/36)){
        cout<<"Oh No!\n";
        return;
    }
    double gs = 36/cosd(t1);

    double x = abs(36*tand(t1));
    double y = 1.0*gs*tand(t2)*(1-gs/dis);

    if(y>=8){
        cout<<"Oh No!\n";
        return;
    }
    if(x*x+(y-4)*(y-4)>r*r){
        cout<<"Goal!\n";
    }
    else{
        cout<<"Oh No!\n";
        return;
    }



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
