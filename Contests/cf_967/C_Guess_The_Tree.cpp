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
#define debugcc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el.ff<<','<<el.ss<<gp<<gp;}cout<<']'<<endl;
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
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

// void func(){
//     for()
// }

void solve(){
    int n;cin>>n;
    vvi sub(n+1);
    vpi edges;
    vi par(n+1);
    vvi level(n+1);
    rep(i,2,n+1){
        sub[1].push_back(i);
    }
    set<int>st;
    rep(i,2,n+1){
        st.insert(i);
    }
    int maxl=0;
    rep(i,2,n+1){
        cout<<"? "<<1<<gp<<i<<endl;
        cout.flush();
        int x;
        cin>>x;
        
        level[x].push_back(i);
        if(x==1){
            edges.push_back({1,i});
            st.erase(i);
        }
        else{
            par[i]=x;
        }

    }
    while(edges.size()!=n-1){
        debugc(edges)
        debugcc(st)
        vll temp;
        for(auto el:st){
            temp.push_back(el);
        }
        for(auto el:temp){
            cout<<"? "<<el<<gp<<par[el]<<endl;
            cout.flush();
            int x;
            cin>>x;
            if(x==el || x==par[el]){
                edges.push_back({el,par[el]});
                st.erase(el);
                st.erase(par[el]);
            }else{
                par[el]=x;

            }
            debugc(edges)
        }
    }
    // level[1].push_back(1);
    
    // rep(i,1,maxl){
    // debug(maxl)
    //     list<int>lvl(level[i+1].begin(),level[i+1].end());
    //     for(int j=0; i<level[i].size(); i++){
    //         for(auto it = lvl.begin(); it!=lvl.end(); ){
    //             auto itt = it++;
    //             cout<<"? "<<level[i][j]<<gp<<*itt<<endl;
    //             cout.flush();
    //             int x;
    //             cin>>x;
    //             if(i==1){
    //                 edges.push_back({level[i][j],*itt});
    //                 lvl.erase(it);
    //             }
    //         }
    //     }
    // }
    cout<<"! ";
    cout.flush();
    for(auto el :edges){
        cout<<el.ff<<gp<<el.ss<<gp;
    }
    cout<<endl;
    cout.flush();


}

int main(){
    // fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
