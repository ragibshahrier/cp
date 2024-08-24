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

//#define DEBG

#define debug(n)
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#endif

#define fastcin() ios_base::sync_with_stdio(false); cin.tie(NULL);


#define All(a) a.begin(),a.end()
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}


const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(){
    string a,b,ans;
    cin>>a>>b;
    int i,j;
    for(i=0, j=0; i<a.length(); ){
        if((a[i]==b[j] || a[i]=='?') && j<b.length()){
            ans.push_back(b[j]);
            i++;
            j++;
        }else if(j<b.length()){
            ans.push_back(a[i]);
            i++;
        }
        else if(a[i]=='?'){
            ans.push_back('a');
            i++;
        }else{
            ans.push_back(a[i]);
            i++;
        }
    }
    if(j>=b.length()){
        cout<<"YES"<<endl;
        while(ans.length()<a.length()){
            ans.push_back('a');
        }
        cout<<ans<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
