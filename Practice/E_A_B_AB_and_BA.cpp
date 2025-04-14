#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
 
typedef long long ll;
 
#define int long long
 
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
#define pow2(i) (1LL<<i)
#define bitcnt(x) ((sizeof(x) <= sizeof(int)) ? (32 - __builtin_clz(x)) : (64 - __builtin_clzll(x)))

#define DEBG

#define debug(n)
#define debugc(a)
#define debugcc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<'{'<<gp<<el.ff<<','<<el.ss<<gp<<'}'<<gp;}cout<<']'<<endl;
#endif

#define fastcin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'


#define All(a) a.begin(),a.end()
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}


#define no cout<<"NO"<<endl;
#define yes cout<<"YES"<<endl;

const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;
const ll N = 2e5 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}

void solve(int testcases){
    string s;
    cin>>s;

    int a,b,ab,ba;

    cin>>a>>b>>ab>>ba;

    int i = 0, j=1;
    int n = s.length();

    int cmnab = 0;

    vi AB, BA;
    string temp = "";

    vector<string>subv;
    while(j<n){
        temp.push_back(s[i]);
        
        if(s[i]==s[j]){
            subv.push_back(temp);
            temp = "";
        }

        i++;
        j++;

    }
    temp.push_back(s[i]);
    subv.push_back(temp);

    int abcnt = 0, bacnt = 0;

    for(auto& el:subv){
        debug(el)
        if(el.length()&1){
            cmnab = el.length()/2;
            if(el[0]=='A'){
                a--;
            }else{
                b--;
            }
        }else{
            
            if(el[0]=='A'){
                AB.push_back(el.length()/2);
                abcnt += el.length()/2;
            }else{
                BA.push_back(el.length()/2);
                bacnt += el.length()/2;
            }

        }
    }

    if(a<0 || b<0){
        no;return;
    }

    sort(All(AB), greater<int>());
    sort(All(BA), greater<int>());
    int i = 0;
    while(abcnt>ab){
        if(i>AB.size())break;

        if(AB[i]>=(abcnt-ab)){
            a--;b--;
            ba-=(abcnt-ab-1);
            abcnt=ab;
        }else{
            a--;b--;
            ba-=(AB[i]-1);
            abcnt-=AB[i];

        }
        i++;
    }
    
    if(a<0 || b<0 || ba<0){
        no;return;
    }
    
    i=0;
    while(bacnt>ba){
        if(i>BA.size())break;

        if(BA[i]>=(bacnt-ba)){
            a--;b--;
            ab-=(bacnt-ba-1);
            bacnt = ba;
        }else{
            a--;b--;
            ab-=(BA[i]-1);
            bacnt -= BA[i];

        }
        i++;
    }





    if(a<0 ||b<0 || abcnt<0 || bacnt<0){
        no;return;
    }

    if(abcnt<ab){
        
    }

    yes;




    

}

int32_t main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
