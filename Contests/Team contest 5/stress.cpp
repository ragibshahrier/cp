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

//#define DEBG

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

int getNum(vector<int>& v)
{
 
    // Size of the vector
    int n = v.size();
 
    // Generate a random number
    srand(time(NULL));
 
    // Make sure the number is within
    // the index range
    int index = rand() % n;
 
    // Get random number from the vector
    int num = v[index];
 
    // Remove the number from the vector
    swap(v[index], v[n - 1]);
    v.pop_back();
 
    // Return the removed number
    return num;
}
 
// Function to generate n non-repeating random numbers
vi generateRandom(int n)
{
    vector<int> v(n);
 
    // Fill the vector with the values
    // 1, 2, 3, ..., n
    for (int i = 0; i < n; i++)
        v[i] = i + 1;
 
    // While vector has elements
    // get a random number from the vector and print it
    vi ans;
    while (v.size()) {
        ans.push_back(getNum(v));
    }
    return ans;
}

std::random_device rd; // obtain a random number from hardware
std::mt19937 gen(rd()); // seed the generator

void solve(){
    
    // cout<<100<<endl;

    std::uniform_int_distribution<> distr(1, 900); // define the range
    
    // int n = distr(gen);
    int n = 10000;
    std::uniform_int_distribution<> distr2(1, n); // define the range
    std::uniform_int_distribution<> distr3(1, n); // define the range
    // int m = distr2(gen);
    int m = 987;

    int k = 10000;

    vi a = generateRandom(n);
    set<int>s(All(a));
    rep(i,0,m-1){
        int x = distr(gen);
        s.erase(x);
    }
    vi b;
    for(auto el:a){
        if(s.find(el)!=s.end()){
            b.push_back(el);
        }
    }
    vi kk;
    rep(i,0,k){
        int x = distr3(gen);
        kk.push_back(x);

    }
    cout<<a.size()<<" "<<b.size()<<" "<<kk.size()<<endl;
    put_vector(a);
    put_vector(b);
    put_vector(kk);



    



    

}

int main(){
    fastcin();
    // freopen("input.txt", "r", stdin);
    freopen("input.txt", "w", stdout);
    int t=10;
    cout<<10<<endl;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
