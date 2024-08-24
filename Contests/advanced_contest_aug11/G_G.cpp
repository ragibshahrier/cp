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




void preprocessing(){

}

void solve(){
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    vi bin(n);
    rep(i,0,n){
        if(s1[i]==s2[i])bin[i]=0;
        else bin[i]=1;
    }
    ll ans = 0;
    ll tempans=0;

    bool f = 0;
    ll phase = 0;
    ll st0 = 0;
    ll md1 = 0;
    ll en0 = 0;

    rep(i,0,n){
        if(phase==0){
            if(bin[i]){
                phase=1;
                md1++;
            }else{
                st0++;
            }
        }else if(phase==1){
            if(bin[i]){
                md1++;
            }else{
                phase=2;
                en0++;
            }
        }else if(phase==2){
            if(bin[i]){
                f=1;
            }else{
                en0++;
            }
        }
    }
    if(!f){
        if(phase==0){
            tempans = st0*(st0+1)/2;
        }else{
            ans+=st0;
            ans+=md1-1;
            ans+=en0;
        }
    }


    f = 0;
    phase = 0;
    ll st1 = 0;
    ll md0 = 0;
    ll en1 = 0;

    rep(i,0,n){
        if(phase==0){
            if(bin[i]){
                phase=1;
                st1++;
            }
        }else if(phase==1){
            if(bin[i]){
                st1++;
            }else{
                phase=2;
                md0++;
            }
        }else if(phase==2){
            if(bin[i]){
                phase=3;
                en1++;
            }else{
                md0++;
            }
        }else if(phase==3){
            if(bin[i]){
                en1++;
            }
            else{
                phase=4;
            }
        }else if(phase == 4){
            if(bin[i])f=1;
        }
    }
    if(!f && phase>=3){
        ans+=3;
    }
    ans = ans*2+tempans;
    cout<<ans<<endl;


}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
