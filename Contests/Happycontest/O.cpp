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




void preprocessing(){

}

pi func(int x, int y, int l,  char c){
    // l-=1;
    if(c=='U'){
        y-=l;
    }
    if(c=='D'){
        y+=l;
    }
    if(c=='R'){
        x-=l;
    }
    if(c=='L'){
        x+=l;
    }
    return {x,y};
}



void solve(){
    int x,y,l;
    cin>>x>>y>>l;
    char ch1, ch2;
    cin>>ch1>>ch2;
    pi t = func(x,y,l, ch1);
    if(t.ff<1 || t.ff>1000 || t.ss<1 || t.ss>1000){
        cout<<"Invalid Initial Position";return;
    }
    t = func(x,y,l, ch2);
    if(t.ff<1 || t.ff>1000 || t.ss<1 || t.ss>1000){
        cout<<"Game Over";
    }else{
        cout<<t.ff<<gp<<t.ss;
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
