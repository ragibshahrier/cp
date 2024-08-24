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
#define debugcc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<'{'<<el.ff<<','<<el.ss<<'}'<<gp;}cout<<']'<<endl;
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

#include <bits/stdc++.h> 
using namespace std; 


const int N = 20; 

int n; 


vpi treee(2 * N); 


// void build( vi& arr) 
// { 
// 	// insert leaf nodes in treee 
// 	for (int i=0; i<n; i++)	 
// 		treee[n+i] = {arr[i],1}; 
	
// 	// build the treee by calculating parents 
// 	for (int i = n - 1; i > 0; --i)	 
// 		// treee[i] = treee[i<<1] + treee[i<<1 | 1];	 
//         if(treee[i<<1].ss && treee[i<<1 | 1].ss && treee[i<<1].ff/2 == treee[i<<1 | 1].ff/2){
//             treee[i].ss=1;
//             treee[i].ff=treee[i<<1].ff/2 ;

//         }else{
//             treee[i].ss=0;
//             treee[i].ff=treee[i<<1].ff/2 ;

//         }
// } 


long long power(long long A, long long B)
{
    if (B == 0)
        return 1;

    long long res = power(A, B / 2);

    if (B % 2)
        return res * res * A;
    else
        return res * res;
}

int k;


void build( vi& arr,int posintree, int pos, int lvl) 
{ 
    if(lvl>k+1){
        return;
    }
    debug(lvl)
    debug(posintree)
    debug(pos)
    debugc(arr)

	treee[posintree].ff=arr[pos-1];
    int x= power(2,(k-lvl+1));
    int y = power(2,lvl+1);
    for(int i=0; i<2; i++){
        build(arr,posintree*2+i,pos+1+(x-1)*i,lvl+1);
    }
    for (int i=0; i<n; i++)	 
		treee[n+i].ss = 1; 
    for (int i = n - 1; i > 0; --i)	{ 
		// treee[i] = treee[i<<1] + treee[i<<1 | 1];	 
        if(treee[i<<1].ss && treee[i<<1 | 1].ss && treee[i<<1].ff/2 == treee[i<<1 | 1].ff/2 && treee[i<<1].ff/2 == treee[i].ff){
            treee[i].ss=1;
            // treee[i].ff=treee[i<<1].ff/2 ;

        }else{
            treee[i].ss=0;
            // treee[i].ff=treee[i<<1].ff/2 ;

        }
    } 

} 

// function to update a treee node 
void updatetreeeNode(int p, int value) 
{ 
	// set value at position p 
	treee[p+n].ff = value; 
	p = p+n; 
	
	// move upward and update parents 
	for (int i=p; i > 1; i >>= 1) {
		// treee[i>>1] = treee[i] + treee[i^1]; 
        	 
        if(treee[i<<1].ss && treee[i<<1 | 1].ss && treee[i<<1].ff/2 == treee[i<<1 | 1].ff/2){
            treee[i].ss=1;
            // treee[i].ff=treee[i<<1].ff/2 ;

        }else{
            treee[i].ss=0;
            // treee[i].ff=treee[i<<1].ff/2 ;

        }
    }
} 

// function to get sum on interval [l, r) 
// int query(int l, int r) 
// { 
// 	int res = 0; 
	
// 	// loop to find the sum in the range 
// 	for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
// 	{ 
// 		if (l&1) 
// 			res += treee[l++]; 
	
// 		if (r&1) 
// 			res += treee[--r]; 
// 	} 
	
// 	return res; 
// } 




void solve(){
    int nn,q;cin>>nn>>q;
    vi par(nn-1);
    rep(i,0,nn-1){
        cin>>par[i];
    }
    k=log2(nn);
    vi a(nn);
    get_vector(a);
    n = (nn+1)/2;
    build(a, 1, 1, 1);
    debugcc(treee)
    while(q--){
        int x,y;
        cin>>x>>y;
        int tempx = a[x-1];
        int tempy = a[y-1];

        updatetreeeNode(x, tempy);
        updatetreeeNode(y, tempx);
        debugcc(treee);
        if(treee[1].ss){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }



}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
