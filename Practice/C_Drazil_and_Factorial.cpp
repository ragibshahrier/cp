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

const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(){
    int n;
    cin>>n;
    string aa;
    cin>>aa;
    vector<char> a;
    for(int i=0; i<n; i++){
        if(aa[i]=='1' || aa[i]=='0')continue;
        if(aa[i]=='2' || aa[i]=='3' || aa[i]=='5' || aa[i]=='7'){
            a.push_back(aa[i]);
        }
        else if(aa[i]=='4'){
            a.push_back('3');
            a.push_back('2');
            a.push_back('2');
        }
        else if(aa[i]=='6'){
            a.push_back('3');
            a.push_back('5');
        }
        else if(aa[i]=='8'){
            a.push_back('2');
            a.push_back('2');
            a.push_back('2');
            a.push_back('7');
        }
        else if(aa[i]=='9'){
            a.push_back('3');
            a.push_back('3');
            a.push_back('2');
            a.push_back('7');
        }
    }
    sort(a.begin(),a.end(),greater<char>());
    for(auto el:a){
        cout<<el;
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
