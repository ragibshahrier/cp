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
#define debugcc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<'{'<<gp<<el.ff<<gp<<el.ss<<gp<<'}'<<gp;}cout<<']'<<endl;
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

// void solve(){
//     debug(1)
//     int n;cin>>n;
//     string s;cin>>s;
//     list<pi>l;
//     l.push_back({1,0});
//     rep(i,1,n){
//         debug(i)
        
//         for(auto it=l.begin(); it!=l.end();){
            
//             auto it2 = it;
//             it2++;
//             if(s[i]!=s[(i-(it->ff))]){
//                 if(it->ss==2)l.erase(it);
//                 else it->ss++;
//             }
//             it = it2;
//         }
//         debugcc(l);
       
//         if(s[i]==s[0]){
//             bool f=1;
//             for(auto it=l.begin(); it!=l.end();it++){
//                 if((i)%(it->ff)==0 && it->ss==0){
//                     f=0;break;
//                 }
//             }
//             if(f)l.push_back({i,0});
            

//         }
//     }
//     int ans = inf;
//     for(auto el:l){
//         if(n%el.ff==0){
//             ans = min(ans,el.ff); 
//         }
//     }
//     if(ans==inf)ans=n;
//     cout<<ans<<endl;

// }




void solve(){
    int n;cin>>n;
    string s;cin>>s;
    vi divs;
    int x = sqrt(n);
    for(int i=1;i<=x;i++){
        if(n%i==0){
            if(n/i==i){
                divs.push_back(i);
            }else{
                divs.push_back(i);
                divs.push_back(n/i);
            }
        }
    }
    vi ans;
    for(auto el:divs){
        debugc(ans)
        int diff=0;
        for(int i=0;i<n;i++){
            if(s[i]!=s[i%el]){
                diff++;
            }
        }
        if(diff<=1){
            ans.push_back(el);
            continue;

        }
        diff=0;
        for(int i=0;i<n;i++){
            if(s[n-1-i]!=s[n-1-(i%el)]){
                diff++;
            }
        }
        if(diff<=1){
            ans.push_back(el);
            continue;

        }
        
    }
    auto it = min_element(ans.begin(),ans.end());
    cout<<*it<<endl;
}





int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
