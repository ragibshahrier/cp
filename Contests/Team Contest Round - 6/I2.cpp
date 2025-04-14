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

#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define resetbit(x,n) (x=(x&(~(1LL<<n))))

#define All(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i=a;i<b;i++)
template<typename T> void get_vector(T&a){for(auto&e:a)cin>>e;}
template<typename T> void put_vector(T a){for(auto e:a)cout<<e<<" ";cout<<endl;}

bool comp(pll a, pll b, pll c){
    ll dx1 = a.first-b.first, dy1 = a.second-b.second;
    ll dx2 = a.first-c.first, dy2 = a.second-c.second;
    ll g1 = __gcd(abs(dx1),abs(dy1)), g2 = __gcd(abs(dx2),abs(dy2));
    if(dx1 == 0){
        return (dx2 == 0 );
    }
    if(dy1 == 0){
        return (dy2 == 0);
    }

    dx1 /= g1;
    dy1 /= g1;
    dx2 /= g2;
    dy2 /= g2;
    return ((abs(dx1) == abs(dx2)) && (abs(dy1) == abs(dy2)));
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << __gcd(0,9) << endl;

    int n;
    cin>>n;
    vpll a(n);
    FOR(i,0,n)cin>>a[i].first>> a[i].second;

    if(n<=4){
        cout << "YES" << endl;
        return 0;
    }
    int x = -1,y = -1;
    FOR(i,0,4){
        FOR(j,i+1,4){
            if(comp(a[i],a[j],a[4])){
                x = i;
                y = j;
                break;
            }
        }
        if(x != -1)break;
    }
    if(x == -1) {
        cout << "NO" << endl;
        return 0;
    }
    vi z;
    FOR(i,0,4){
        if(i!=x && i!=y)z.push_back(i);
    }

    FOR(i,5,n){
        if(!comp(a[x],a[y],a[i]) && !comp(a[z[0]],a[z[1]],a[i])){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}