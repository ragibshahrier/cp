#include<bits/stdc++.h>

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key

using namespace std; 
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

#define All(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i=a;i<b;i++)

#define gp " "
// #define DEBG

#define debug(n)
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#endif

template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}

const int N = 1e7+5;

vi hasprime(N);
vi eratt(N);
vi dis(N);
int a,b,c,d;

void erat(){
    if(a==1&&c==1){
        eratt[1]=1;
    }
    FOR(i,2,N){
        // if((a<=i && i<=b)&&(c<=i && i<=d)){
        //     eratt[i]=i-min(a, c)+1;
        // }else if((a<=i && i<=b)&&!(c<=i && i<=d)){
        //     if(i>c){
        //         eratt[i]=d-c+1;
        //     }else{
        //         eratt[i] = 0;
        //     }

        // }else if(!(a<=i && i<=b)&&(c<=i && i<=d)){
        //     if(i>a){
        //         eratt[i]=b-a+1;
        //     }else{
        //         eratt[i] = 0;
        //     }

        // }
        if(a<=i && i<=b){
            eratt[i]+=max(0, min(d,i)-c+1);
        }if(c<=i && i<=d){
            eratt[i] += max(0, min(b,i)-a+1);

        }
    }
    debugc(eratt)
    FOR(i,2,N){
        int m1=0,m2=0;
        bool isprime = 0;
        if(hasprime[i]==0){
            isprime = 1;
        }
        if(!isprime && dis[i]){
            continue;
        }
        debug(i)
        debug(hasprime[i])
        for(int j=i; j<N;j+=i){
            if(j%(i*i)==0){
                dis[j]=1;
            }
            if(isprime)hasprime[j]++;
            if(a<=j && j<=b){
                m1++;
                
            }
            if(c<=j && j<=d){
                m2++;
                if(hasprime[i]&1){
                    eratt[j]-=m1;
                }else{
                    eratt[j]+=m1;
                }
            }
            if(a<=j && j<=b){
                
                if(hasprime[i]&1){
                    eratt[j]-=m2;
                }else{
                    eratt[j]+=m2;
                }
            }
        }
        debugc(eratt)
        

    }
}

void solve(){

    cin>>a>>b>>c>>d;
    // cout<<a<<b<<c<<d;
    erat();
    ll ans = 0;
    FOR(i,1,N){
        if(a<=i && i<=b){
            ans+=eratt[i];
        }else if(c<=i && i<=d){
            ans+=eratt[i];

        }
    }
    // put_vector(hasprime);
    // put_vector(eratt);
    cout<<ans<<endl;
}
    

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}