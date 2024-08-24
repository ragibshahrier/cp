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
#define checkbit(x,n) ((x&(1LL<<n))>0)
#define setbit(x,n) (x=(x|(1LL<<n)))
#define resetbit(x,n) (x=(x&(~(1LL<<n))))

// #define DEBG

#define debug(n)
#define debugc(a)
#define debugcc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<"{ "<<el.ff<<','<<el.ss<<" }"<<gp;}cout<<']'<<endl;
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

void solve2(){
    int n;
    cin>>n;
    string s,s2;
    cin>>s>>s2;
    s.push_back('.');
    s.push_back('.');
    s2.push_back('.');
    s2.push_back('.');
    queue<pair<pair<string,ll>,int>>q;
    q.push({{s,0}, n});
    map<string,int>visited;
    ll ans = -1;
    bool dn = 0;
    ll cnt=0;
    while(!q.empty()){
        cnt++;

        string tp = q.front().ff.ff;
        ll dis = q.front().ff.ss;
        int dots = q.front().ss;
        debug(tp)
        debug(dis)
        if(tp==s2){
            dn=1;ans = dis; break;
        }
        q.pop();
        visited[tp]=1;
        rep(i,0,n+1){
            if(tp[i]!='.'&&tp[i+1]!='.'){
                swap(tp[i],tp[dots]);
                swap(tp[i+1],tp[dots+1]);
                if(!visited[tp]){
                    debug(tp)
                    debug(dis+1)
                    q.push({{tp,dis+1},i});
                }
                swap(tp[i],tp[dots]);
                swap(tp[i+1],tp[dots+1]);
            }
        }
    }
    cout<<cnt<<endl;
    cout<<ans<<endl;

}


void solve3(){
    int n;
    cin>>n;
    string s,s2;
    cin>>s>>s2;
    bitset<16>b1;
    bitset<16>b2;
    int ct1=0,ct2=0;
    rep(i,0,n){
        if(s[i]=='B'){
            b1.set(i);
            ct1++;
        }
        if(s2[i]=='B'){
            b2.set(i);
            ct2++;
        }
        
    }
    if(ct1!=ct2){
        cout<<-1<<endl;return;
    }
    queue<pair<pair<bitset<16>,ll>,int>>q;
    q.push({{b1,0}, n});
    map<pair<unsigned long,int>,int>visited;
    ll ans = -1;
    bool dn = 0;
    ll cnt=0;
    while(!q.empty()){
        // cnt++;

        auto tp = q.front().ff.ff;
        ll dis = q.front().ff.ss;
        int dots = q.front().ss;
        debug(tp)
        debug(dis)
        debug(dots)
        if(tp==b2 && dots==n){
            dn=1;ans = dis; break;
        }
        q.pop();
        visited[{tp.to_ulong(),dots}]=1;
        rep(i,0,n+1){
            if(i!=dots && i!=dots+1 && i+1!=dots){
                // swap(tp[i],tp[dots]);
                tp.set(dots,tp.test(i));
                tp.set(dots+1,tp.test(i+1));
                tp.set(i,0);
                tp.set(i+1,0);
                // swap(tp[i+1],tp[dots+1]);
                if(!visited[{tp.to_ulong(),i}]){
                    debug(tp)
                    debug(dis+1)
                    q.push({{tp,dis+1},i});
                }
                tp.set(i,tp.test(dots));
                tp.set(i+1,tp.test(dots+1));
                tp.set(dots,0);
                tp.set(dots+1,0);
                
                // swap(tp[i],tp[dots]);
                // swap(tp[i+1],tp[dots+1]);
            }
        }
    }
    // cout<<cnt<<endl;
    cout<<ans<<endl;

}

ll visited[70000][20];

void solve(){
    int n;
    cin>>n;
    string s,s2;
    cin>>s>>s2;
    int b1=0;
    int b2=0;
    int ct1=0,ct2=0;
    rep(i,0,n){
        if(s[i]=='B'){
            setbit(b1,i);
            ct1++;
        }
        if(s2[i]=='B'){
            setbit(b2,i);
            ct2++;
        }
        
    }
    if(ct1!=ct2){
        cout<<-1<<endl;return;
    }
    queue<pair<pair<int,ll>,int>>q;
    q.push({{b1,0}, n});
    memset(visited,-1,sizeof(visited));
    ll ans = -1;
    bool dn = 0;
    ll cnt=0;
    while(!q.empty()){
        // cnt++;

        auto tp = q.front().ff.ff;
        ll dis = q.front().ff.ss;
        int dots = q.front().ss;
        debug(tp)
        debug(dis)
        debug(dots)
        if(tp==b2 && dots==n){
            dn=1;ans = dis; break;
        }
        q.pop();
        visited[tp][dots]=1;
        rep(i,0,n+1){
            if(i!=dots && i!=dots+1 && i+1!=dots){
                // swap(tp[i],tp[dots]);
                // tp.set(dots,tp.test(i));
                debug(tp)
                if(checkbit(tp,i))setbit(tp,dots);
                else resetbit(tp,dots);
                // tp.set(dots+1,tp.test(i+1));
                // setbit(tp,dots+1,checkbit(tp,i+1));
                if(checkbit(tp,i+1))setbit(tp,dots+1);
                else resetbit(tp,dots+1);
                // tp.set(i,0);
                resetbit(tp,i);
                // tp.set(i+1,0);
                resetbit(tp,i+1);


                debug(tp)
                // swap(tp[i+1],tp[dots+1]);
                if(visited[tp][i]==-1){
                    debug(tp)
                    debug(dis+1)
                    q.push({{tp,dis+1},i});
                }
                // tp.set(i,tp.test(dots));
                // tp.set(i+1,tp.test(dots+1));
                // tp.set(dots,0);
                // tp.set(dots+1,0);
                debug(tp)
                debug(dots)
                debug(i)

                if(checkbit(tp,dots)){
                    debug(tp)
                    setbit(tp,i);
                }
                else resetbit(tp,i);
                // tp.set(dots+1,tp.test(i+1));
                if(checkbit(tp,dots+1))setbit(tp,i+1);
                else resetbit(tp,i+1);
                // setbit(tp,i+1,checkbit(tp,dots+1));
                // tp.set(i,0);
                debug(tp)
                resetbit(tp,dots);
                // tp.set(i+1,0);
                resetbit(tp,dots+1);

                debug(tp)
                
                // swap(tp[i],tp[dots]);
                // swap(tp[i+1],tp[dots+1]);
            }
        }
    }
    // cout<<cnt<<endl;
    cout<<ans<<endl;

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
