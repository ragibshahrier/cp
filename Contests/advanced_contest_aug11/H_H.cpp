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
#define endl '\n'


#define All(a) a.begin(),a.end()
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}


const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;


//==============================CODE STARTS HERE==============================//

map<char,int>mp;


void preprocessing(){
    mp['0']=1;
    mp['1']=0;
    mp['2']=0;
    mp['3']=0;
    mp['4']=1;
    mp['5']=0;
    mp['6']=1;
    mp['7']=0;
    mp['8']=2;
    mp['9']=1;

}

string func(string s){
    ll ansi=0;
    for(auto ch:s){
        ansi+=mp[ch];
    }
    if(ansi==0)return "0";
    string ans="";
    while(ansi>0){
        ans.push_back((ansi%10)+'0');
        ansi/=10;
    }
    reverse(All(ans));
    return ans;
}

void solve(){
    string s;
    int k;
    cin>>s>>k;
    rep(i,0,min(k,6)){
        s=func(s);
    }
    if(k<=6){
        cout<<s<<endl;
    }else{
        if(k&1){
            if(s=="0")cout<<1<<endl;
            else cout<<"0"<<endl;
        }else{
            cout<<s<<endl;
        }
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
