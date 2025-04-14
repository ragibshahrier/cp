#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
#define int long long
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

int func(list<int>& ans){
    int k = 0;
    int i = 0;
    for(auto el:ans){
        if(i&1){
            k|=el;
        }else{
            k&=el;
        }
        i++;
    }
    cout<<k<<endl;
    return k;
}

// void solve(){
//     int n;
//     cin>>n;
//     int nnn = n;
//     vi ans;
//     if(n&1){
//         n--;
//         // cout<<n<<endl;
//         // int nn = n, i=0;
//         // while(nn>0){
//         //     nn>>=1;
//         //     i++;
//         // }
//         // debug(i)
//         // int com = (1<<(i-1))-1;
//         // int com2 = n-1;
        
//         // int ii = 1;
//         // while(ans.size()<n-2){
//         //     if(ii!=com && ii!=n){
//         //         ans.push_back(ii);
//         //     }
//         //     ii++;
//         // }
//         // ans.push_back(com);
//         // ans.push_back(n);


//     }
//         int nn = n, i=0;
//         while(nn>0){
//             nn>>=1;
//             i++;
//         }
//         nn = ((1<<i))-1;
//         if(n&1)cout<<nnn<<endl;
//         else cout<<nn<<endl;
//         int com2 = 1<<(i-1);
//         int com = com2-1;
        
//         int ii = 1;
//         while(ans.size()<n-3){
//             if(ii!=com && ii!=com2){
//                 ans.push_back(ii);
//             }
//             ii++;
//         }
//         if(com2==ii){
//             ii++;
//         }
//         ans.push_back(com2);

//         if(com==ii){
//             ii++;
//         }
//         ans.push_back(ii);

//         ans.push_back(com);
        


    
//     if(nnn&1){
//         ans.push_back(nnn);
//     }
//     put_vector(ans);
//     func(ans);
//     vi a ={2,1,6,4,5,3,10,8,9,7,11,12,13,14,18,16,17,15};
//     func(a); 

// }

void solve2(){
    int n;
    cin>>n;
    list<int>l = {2,1,3,4,5};
    // auto it = l.end();it--;it--;it--;
    // l.insert(it,6);
    // debugc(l);
    int i = 6;
    bool f = 0;
    int xx = 3;
    while(l.size()<n){
        auto it = l.end();it--;it--;it--;

        int x = i-2;
        if((i&1)==0){
            if((i&(i-1))==0){
                f = 0;
                xx = i-1;
                l.push_back(i);
            }else if(f){
                it++;
                l.insert(it, i);
                l.erase(it);
                l.push_back(xx);

            }else{
                l.insert(it, i);
                l.erase(it);
                l.push_back(xx);
                f= 1;

            }
            // l.push_back(i-3);
        }
        else{
            l.push_back(i);
        }
        i++;
        // debugc(l);
    }
    func(l);
    // list<int>lll = {2, 1, 6, 4, 5, 3, 10, 8, 9, 12, 11, 14, 13, 7, 15, 16, 17};
    // func(lll);
    for(auto el:l){
        cout<<el<<" ";
    }
    cout<<endl;

}

int32_t main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    int i = 5;
    while(t--){
        
        solve2();
        i++;
    }
    return 0;
}
