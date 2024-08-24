#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; ii<n; ii++)
#define gp " "

//bit_manupulation
#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define resetbit(x,n) (x=(x&(~(1LL<<n))))

// #define DEBG

#define debug(n)
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#endif

#define fastcin() ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;


//----------------------CODE STARTS HERE-------------------




void preprocessing(){

}

void solve(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    debug(n)
    debug(a)
    debug(b)
    ll ans = 0;
    int ch1=1,ch2=0, ch3=0;
    a.push_back('2');
    string anss;
    anss.push_back(a[0]);
    rep(i,0,n){
        debug(ch1)
        debug(ch2)
        debug(ch3)
        if(ch1==1){
            ans=0;
            if(a[i+1]==b[i]){
                ch2=ch1=0;
                ch3=1;
                ans+=1;
                anss.push_back(b[i]);
            }
            else if(a[i+1]>b[i]){
                ch1=0;ch3=0;
                ch2=1;ans++;anss.push_back(b[i]);
            }else{
                ch1=1;
                ch2=ch3=0;
                anss.push_back(a[i+1]);
            }
        }
        else if(ch2==1){
            ch1=ch3=0;
            anss.push_back(b[i]);
        }else if(ch3==1){
            if(a[i+1]==b[i]){
                ch2=ch1=0;
                ch3=1;
                ans+=1;
                anss.push_back(b[i]);
            }
            else if(a[i+1]>b[i]){
                ch1=0;ch3=0;
                ch2=1;ans++;anss.push_back(b[i]);
            }else{
                ch1=1;
                ch2=ch3=0;
                anss.push_back(a[i+1]);
            }

        }
        debug(anss)
    }
        cout<<anss<<endl<<ans<<endl;
        debug(1)




}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    debug(t)
    while(t--)solve();
    return 0;
}
