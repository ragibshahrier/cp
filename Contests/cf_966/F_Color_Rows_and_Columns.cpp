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

#define DEBG

#define debug(n)
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<'{'<<el.ff<<','<<el.ss<<'}'<<gp;}cout<<']'<<endl;
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

bool comp(pll a, pll b){
    if(1.0*a.ff/a.ss < 1.0*b.ff/b.ss){
        return 1;
    }return 0;
}

void solve(){
    int n,k;
    // int a,b;
    cin>>n>>k;
    vll ks(300,inf);
    // int aa=a;
    // int bb=b;
    int kk=k;
    vpi recs(n);
    double rate = 0;
    pi best;
    pi deal;
    multiset<pi>mm;
    rep(i,0,n){
        // cin>>recs[i].ff>>recs[i].ss;
        // if(rate<1.0*(recs[i].ff*recs[i].ss)/(recs[i].ff+recs[i].ss)){
        //     rate = 1.0*(recs[i].ff*recs[i].ss)/(recs[i].ff+recs[i].ss);
        //     best = recs[i];
        // }
        int x,y;
        cin>>x>>y;
        if(x<y){
            mm.insert({x,y});
        }
        else{
            mm.insert({y,x});
        }

    }
    // vector<ll>deals;
    // for(auto el:recs){
    //     int a = el.ff;
    //     int b = el.ss;
    //     int kk = 0;
    //     ll ops = 0;
    //     while(a>1 && b>1){
    //         if(a>b){
    //             a--;
    //             ops+=b;
    //             kk++;
    //             ks[kk]=min(ops,ks[kk]);
    //             deals.push_back(b);
    //         }else{
    //             b--;
    //             ops+=a;
    //             kk++;
    //             ks[kk]=min(ops,ks[kk]);
    //             deals.push_back(a);
    //         }
    //     }
    //     kk+=2;
    //     ks[k]=min(ops,ks[kk]);
    //     deals.push_back(1);
    // }
    // sort(All(deals), greater<ll>());
    // debugc(deals)
    ll ans = 0;
    while(k>0 && mm.size()!=0){
        debugc(mm)
        debug(ans)
        debug(k)
        auto it = mm.begin();
        if(it->ff==1 && it->ss==1){
            k-=2;
            ans+=1;
            mm.erase(it);
        }else{
            k--;
            ans+=it->ff;
            
            if(it->ff>it->ss-1){
                mm.insert({it->ss-1,it->ff});
            }else{
                mm.insert({it->ff,it->ss-1});
            }
            mm.erase(it);
        }
    }
    if(k>0)cout<<-1<<endl;
    else cout<<ans<<endl;


}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
