#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
 
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
#define pow2(i) (1LL<<i)

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




void preprocessing(){

}
vi st,en,ssv;

bool checksame(int i1, int i2){
    debug(*lower_bound(All(en), i1))
    if(upper_bound(All(en),i1)==en.begin()){
        return 1;
    }
    if(*(--upper_bound(All(st), i1))>*(--upper_bound(All(en),i1))){
        return 1;
    }
    return 0;
}

int func(vi& st, vi& en,vi& ssv, int ind, int val){
    int ans = 0;
    if(val==1){
        if(ssv[ind+1]==0){
            if(checksame(ind,ind+1)){
                ans++;
            }
        }
        if(ssv[ind-1]==1){
            if(checksame(ind-1,ind)){
                ans--;
            }
        }

    }
    if(val==0){
        if(ssv[ind+1]==0){
            if(checksame(ind,ind+1)){
                ans--;
            }
        }if(ssv[ind-1]==1){
            if(checksame(ind-1,ind)){
                ans++;
            }
        }
        
    }
    return ans;

}

void solve(){
    st.clear();
    en.clear();
    ssv.clear();
    int n,q;
    cin>>n>>q;
    vi a(n);
    get_vector(a);
    string s;cin>>s;
    vi sv;
    rep(i,0,n-1){
        if(s[i]=='L'){
            sv.push_back(i);
        }
        
    }
    ssv.resize(n);
    ssv[n-1] = 1;
    // st;
    // en;
    set<int>temp;
    rep(i,0,n){
        if(temp.size()==0){
            st.push_back(i);
        }
        temp.insert(a[i]);
        int mn = *temp.begin();
        int mx = *(--temp.end());
        // debugc(temp)

        if(mn==st.back()+1 &&mx==i+1 && temp.size()==i-st.back()+1){
            en.push_back(i);
            temp.clear();
        }
    }
    int prob = 0;
    for(auto el:sv){
        ssv[el]=1;
        prob += func(st,en,ssv,el,1);

    }
    debug(prob)
    while(q--){
        int x;cin>>x;
        x--;
        if(s[x]=='R'){
            s[x]='L';
            ssv[x]=1;
            prob += func(st,en,ssv,x,1);
        }
        else{
            s[x]='R';
            ssv[x]=0;
            prob += func(st,en,ssv,x,0);
        }
        if(prob==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    debugc(st)
    debugc(en)
    debug(checksame(1,2));


}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
