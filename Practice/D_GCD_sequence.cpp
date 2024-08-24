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


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

int checknondecreasing(vi& b){
    int n = b.size();
    for(int i =0; i<n-1; i++){
        if(b[i]>b[i+1])return i;
    }
    return -1;
}

void solve(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    vi b(n-1);
    rep(i,0,n-1){
        b[i]=__gcd(a[i],a[i+1]);

    }
    
    debugc(b)


    int check = checknondecreasing(b);
    if(check==-1){
        cout<<"YES"<<endl;
        return;
    }
    
    int ii = check;
    
    debug(check)

    vi bb1;
    vi bb2;
    vi bb3;

    int i = 0;
    int j = 1;
    for(;i<n-1&& j<n; i++ ,  j++){
        if(i==ii ){
            i++;
        }
        if(j==ii || i==j){
            j++;
        }
        if(i<n-1 && j<n){
            bb1.push_back(__gcd(a[i], a[j]));
        }
    }
    debugc(bb1)
    check = checknondecreasing(bb1);
    debug(check)
    if(check==-1){
        cout<<"YES"<<endl;
        return;
    }
    ii++;


    i = 0;
    j = 1;
    for(;i<n-1&& j<n; i++ ,  j++){
        if(i==ii ){
            i++;
        }
        if(j==ii || i==j){
            j++;
        }
        if(i<n-1 && j<n){
            bb2.push_back(__gcd(a[i], a[j]));
        }
    }
    check = checknondecreasing(bb2);
    debugc(bb2)
    if(check==-1){
        cout<<"YES"<<endl;
        return;
    }

    // ii--;ii--;
    ii++;
    if(ii>=0){
        i = 0;
        j = 1;
        for(;i<n-1&& j<n; i++ ,  j++){
            if(i==ii ){
                i++;
            }
            if(j==ii || i==j){
                j++;
            }
            if(i<n-1 && j<n){
                bb3.push_back(__gcd(a[i], a[j]));
            }
        }
        debugc(bb3)
        check = checknondecreasing(bb3);
        if(check==-1){
            cout<<"YES"<<endl;
            return;
        }

    }

    cout<<"NO"<<endl;




    




}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
