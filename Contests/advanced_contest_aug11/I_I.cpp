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
#define endl '\n'


#define All(a) a.begin(),a.end()
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}


const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

int mp(char a){
    if(a>='0'&&a<='9'){
        return a-'0';
    }
    if(a>='A'&&a<='Z'){
        return a-'A'+10;
    }
    
    if(a>='a'&&a<='z'){
        return a-'a'+36;
    }

}

char cmp(int a){
    if(a>=0 && a<=9){
        return '0'+a;
    }
    if(a>=10 && a<=35){
        return 'A'+a-10;
    }
    if(a>=36 && a<=61){
        return 'a'+a-36;
    }
}

int divi(string& z, int x, int y){
    debug(z)
    string ans = "";
    ll b=0;
    for(auto d:z){
        debug(1)
        b=b*x + mp(d);
        debug(b)
        ans.push_back(cmp(b/y));
        b%=y;

    }
    debug(ans)
    if(ans==""){
        z=ans;
        return b;
    }
    reverse(ans.begin(),ans.end());
    while(ans.back()=='0'){
        ans.pop_back();
    }
    reverse(ans.begin(),ans.end());
    z= ans;
    return b;
}

void solve(){
    int x,y;
    string z;
    cin>>x>>y>>z;
    string ans;
    int i = 0;
    while(z!=""){
        ans.push_back(cmp(divi(z,x,y)));
        i++;
        debug(z)
        // z= divi(z,y);
    }
    reverse(All(ans));
    cout<<ans<<endl;

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
