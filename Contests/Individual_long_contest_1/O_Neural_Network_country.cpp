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
const ll N = 1e5 + 7;
const ll N2 = 1e6 + 3;
const ll modinvof2 = 500000004;


//==============================CODE STARTS HERE==============================//




void preprocessing(){

}
int n,m,l;
// vvi net;
// vvi net2;
int net[3][N2];
int net2[3][101];

int func(int lvl, int sum){
    if(lvl == l){
        if(sum==0)return 1;
        else return 0;
    }

    
    ll ans = 0;
    if(lvl==0){
        rep(i,0,100){
            ans+=(net2[0][i])*func(lvl+1, (sum+i)%m);
        }
    }else if(lvl==l-1){
        rep(i,0,100){
            ans+=(net2[2][i])*func(lvl+1, (sum+i)%m);
        }
    }else{
        rep(i,0,100){
            ans+=(net2[1][i])*func(lvl+1, (sum+i)%m);
        }
    }
    // debug(lvl)
    // debug(sum)
    // debug(ans)

    return ans;
}

int dpp[100][N];




vvi matrixmult(int n, vvi& mat1, vvi& mat2){
    vvi result(n,vi(n));
    rep(i,0,n){
        rep(j,0,n){
            rep(k,0,n){
                result[i][j]+=(mat1[i][k]*mat2[k][j])%M;
                result[i][j]%=M;
            }
        }
    }
    return result;
}

vvi matexp(vvi& mat, int n, int exp){
    
    if(exp==1){
        return mat;
    }
    vvi matres = matexp(mat, n, exp/2);
    matres = matrixmult(n , matres, matres);
    if(exp&1){
        matres = matrixmult(n , mat, matres);
    }

    return matres;
}

void solve(int testcases){
    cin>>n>>l>>m;
    // net.resize(3, vi(n,20));
    // net2.resize(3, vi(100));

    rep(i,0,3){
        // get_vector(net[i]);
        rep(j,0,n){
            cin>>net[i][j];
        }
    }
    // rep(i,0,3){
    //     rep(j,0,n){
    //         net[i][j] %= m;
    //     }
    // }
    rep(i,0,n){
        net[2][i] = (net[2][i]+net[1][i])%m;
    }
    // debugc(net[1])

    rep(i,0,3){
        rep(j,0,n){
            net2[i][net[i][j]%m]++;
        }
    }
    debugc(net2[0])
    debugc(net2[1])
    debugc(net2[2])

    
    vvi mat(m,vi(m));

    rep(i,0,m){
        rep(j,0,m){
            mat[i][j] = net2[1][(j-i+m)%m];
        }
    }
    
    // rep(i,0,m){
    //     rep(j,0,m){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;





    int lvl = l;

    for(int sum = 0; sum<m; sum++){
        if(lvl==l){
            if(sum==0){
                // dpp[sum][lvl&1] = 1;
                dpp[sum][lvl] = 1;
            }else{
                // dpp[sum][lvl&1] = 0;
                dpp[sum][lvl] = 0;
            }
            continue;
        }
    }
    lvl--;
    for(int sum = 0; sum<m; sum++){
        ll ans = 0;
        if(lvl==l-1){
            rep(i,0,m){
                // ans+=(net2[2][i])*dpp[(sum+i)%m][(lvl+1)&1];
                ans+=((net2[2][i])*dpp[(sum+i)%m][(lvl+1)])%M;
                ans%=M;
            }
        }
        dpp[sum][lvl] = ans;
    }

    if(lvl>1){
        // lvl = 1;
        mat = matexp(mat, m, l-2);
        rep(i,0,m){
            rep(j,0,m){
                dpp[i][1] += (dpp[j][lvl]*mat[i][j])%M;
                dpp[i][1]%=M;
            }
        }

    }
    lvl = 1;





    lvl--;
    for(int sum = 0; sum<m; sum++){
        ll ans = 0;
        if(lvl==0){
            rep(i,0,m){
                // ans+=(net2[0][i])*dpp[(sum+i)%m][(lvl+1)&1];
                ans+=((net2[0][i])*dpp[(sum+i)%m][(lvl+1)])%M;
                ans%=M;
            }
        }
        dpp[sum][lvl] = ans;
    }





    // for(int lvl =l ; lvl>=0; lvl--){
        

    //         ll ans = 0;
    //         if(lvl==0){
    //             rep(i,0,m){
    //                 ans+=(net2[0][i])*dpp[(sum+i)%m][(lvl+1)&1];
    //                 // ans+=(net2[0][i])*dpp[(sum+i)%m][(lvl+1)];
    //                 ans%=M;
    //             }
    //         }else if(lvl==l-1){
    //             rep(i,0,m){
    //                 ans+=(net2[2][i])*dpp[(sum+i)%m][(lvl+1)&1];
    //                 // ans+=(net2[2][i])*dpp[(sum+i)%m][(lvl+1)];
    //                 ans%=M;
    //             }
    //         }else{
    //             rep(i,0,m){
    //                 ans+=(net2[1][i])*dpp[(sum+i)%m][(lvl+1)&1];
    //                 // ans+=(net2[1][i])*dpp[(sum+i)%m][(lvl+1)];
    //                 ans%=M;
    //             }
    //             // ans = tot[sum]*dpp[]
    //         }
    //         ans%=M;
    //         dpp[sum][lvl&1] = ans;


        
    // }

    // rep(i,0,l+1){
    //     rep(j,0,m){
    //         cout<<dpp[j][i]<<" ";
    //     }
    //     cout<<endl;
    // }

    int ans = dpp[0][0];
    // debug(dpp[8][2])

    cout<<ans<<endl;



}

int32_t main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    rep(i,1,t+1){
       solve(i);
    }
    return 0;
}
