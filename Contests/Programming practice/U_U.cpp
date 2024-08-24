#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
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

long long power(long long a, long long b)
{
    long long result = 1;
    while (b) {
        if (b & 1)
            result = (result * a);
        a = (a * a);
        b >>= 1;
    }
    return result;
}

string numtstr(ll x){
    string ans="";
    while(x!=0){
        ans.push_back(x%10 + '0');
        x/=10;
    }
    reverse(All(ans));
    return ans;
}

void solve(){
    ll n;
    cin>>n;
    if(n==1){
        cout<<0;return;
    }
    --n;
    int i=0;
    ll x;
    ll s = 0;
    // map<int,ll>mp;
    // mp[1]=0;
    // mp[2]=9;
    // mp[3]=99;
    // mp[4]=999;
    // mp[5]=9999;
    // mp[6]=99999;
    // mp[7]=999999;
    // mp[8]=9999999;
    // mp[9]=99999999;
    // mp[10]=999999999;
    while(1){
        if(s+9*power(10,i/2)<n){
            debug(i)
            debug(s)
            s+=9*power(10,i/2);
            i++;
            debug(s)
        }else{
            // x = mp[i/2+1]+n-s;
            x = power(10, i/2)-1+n-s;
            break;
        }
    }
    debug(x)
    debug(i)
    if(i&1){
        string ss = numtstr(x);
        string ss2=ss;
        reverse(All(ss2));
        cout<<ss+ss2;return;

    }else{
        string ss = numtstr(x);
        string ss2=ss;
        ss2.pop_back();
        reverse(All(ss2));
        cout<<ss+ss2;return;
    }

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
