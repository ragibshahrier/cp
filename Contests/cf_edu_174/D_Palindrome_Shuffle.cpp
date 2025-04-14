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

// #define DEBG

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


const ll INF = 2e18;
const ll inf = INT_MAX;
const ll M = 1e9 + 7;
const ll N = 2e5 + 7;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//


int checkv(vi& v1, vi& v2){
    int f = 0;
    int n = 26;
    rep(i,0,n){
        if(v1[i]<v2[i]){
            return 0;
        }
    }

    return 1 ;
}

void preprocessing(){

}

void solve(int testcases){
    string s;
    cin>>s;

    int len = s.length();

    int ans = 0;
    int i = 0, j=len-1;
    while(i<j){
        if(s[i]==s[j]){
            i++;j--;
        }else{
            break;
        }
    }

    int ii = i;
    int jj = j;
    int walk = 0;
    int flag = 0;
    int msk1 = 0, msk2 = 0;

    // debug(i)
    // debug(j)

    vi msk11(26);
    vi msk22(26);
    
    while(i<len && j>=0){
        walk++;
        int char1 = s[i]-'a';
        int char2 = s[j]-'a';
        // msk1^=(1<<char1);
        // msk2^=(1<<char2);

        msk11[char1]++;
        msk22[char2]++;
        
        if(i>j){
            // msk1^=(1<<char2);
            // msk2^=(1<<char1);
            // msk11[char2]--;
            // msk22[char1]--;
            msk22[char2]--;
            msk22[char1]--;

        }

        debugc(msk11)
        debugc(msk22)

        if(checkv(msk11,msk22)){
            if(flag){
                ans=walk;
            }
            flag=0;
            debug(ans)
            // if(i>=j-1){
            //     break;
            // }
        }else{
            flag=1;
            ans = walk;
        }
        i++;j--;


    }

    ll ans1 = ans;

    ans = 0;

    i = ii;
    j = jj;
    debug("second")

    msk11.clear();
    msk22.clear();
    msk11.resize(26,0);
    msk22.resize(26,0);
    walk = 0;
    flag = 0;


    while(i<len && j>=0){
        walk++;
        int char1 = s[i]-'a';
        int char2 = s[j]-'a';
        // msk1^=(1<<char1);
        // msk2^=(1<<char2);

        msk11[char1]++;
        msk22[char2]++;
        
        if(i>j){
            // msk1^=(1<<char2);
            // msk2^=(1<<char1);
            // msk11[char2]--;
            // msk22[char1]--;
            msk11[char2]--;
            msk11[char1]--;

        }

        debugc(msk11)
        debugc(msk22)

        if(checkv(msk22,msk11)){
            if(flag){
                ans=walk;
            }
            flag=0;
            debug(ans)
            // if(i>=j-1){
            //     break;
            // }
        }else{
            flag=1;
            ans = walk;
        }
        i++;j--;


    }

    ans = min(ans,ans1);


    cout<<ans<<endl;

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
