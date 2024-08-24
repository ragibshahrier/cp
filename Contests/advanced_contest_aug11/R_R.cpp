#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
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
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#define debugcc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp; cout<<'{'<<gp; for(auto el:a){cout<<'{'<<gp;for(auto elel:el){cout<<elel<<',';}cout<<'}'<<',';}cout<<']'<<endl;
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



map<int ,vi>mp;


void preprocessing(){
    mp[2]={1,0,0,0};
    mp[3]={0,1,0,0};
    mp[4]={2,0,0,0};
    mp[5]={0,0,1,0};
    mp[6]={1,1,0,0};
    mp[7]={0,0,0,1};
    mp[8]={3,0,0,0};
    mp[9]={0,2,0,0};
    mp[10]={1,0,1,0};
}




#define MAX 300008
// #define MAX 13
 
// Ideally, we should not use global variables and large
// constant-sized arrays, we have done it here for simplicity.
vvi tree(MAX, vi(4));  // To store segment tree
vvi lazy(MAX, vi(4));  // To store pending updates
 

// void addsg(vvi& tree, int si, int diff, int rng){
    
//     tree[si][1]
// }


/*  si -> index of current node in segment tree
    ss and se -> Starting and ending indexes of elements for
                 which current nodes stores sum.
    us and ue -> starting and ending indexes of update query
    diff -> which we need to add in the range us to ue */
void updateRangeUtil(int si, int ss, int se, int us,
                     int ue, int diff)
{
    // If lazy value is non-zero for current node of segment
    // tree, then there are some pending updates. So we need
    // to make sure that the pending updates are done before
    // making new updates. Because this value may be used by
    // parent after recursive calls (See last line of this
    // function)
    if (lazy[si][0] != 0 || lazy[si][1] != 0 || lazy[si][2] != 0 || lazy[si][3] != 0)
    {
        // Make pending updates using value stored in lazy
        // nodes
        // tree[si][0] += (se-ss+1)*lazy[si][0];
        // tree[si][1] += (se-ss+1)*lazy[si][1];
        // tree[si][2] += (se-ss+1)*lazy[si][2];
        // tree[si][3] += (se-ss+1)*lazy[si][3];
        
        tree[si][0] += lazy[si][0];
        tree[si][1] += lazy[si][1];
        tree[si][2] += lazy[si][2];
        tree[si][3] += lazy[si][3];

        
 
        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // We can postpone updating children we don't
            // need their new values now.
            // Since we are not yet updating children of si,
            // we need to set lazy flags for the children
            lazy[si*2 + 1][0]   += lazy[si][0];
            lazy[si*2 + 1][1]   += lazy[si][1];
            lazy[si*2 + 1][2]   += lazy[si][2];
            lazy[si*2 + 1][3]   += lazy[si][3];

            lazy[si*2 + 2][0]   += lazy[si][0];
            lazy[si*2 + 2][1]   += lazy[si][1];
            lazy[si*2 + 2][2]   += lazy[si][2];
            lazy[si*2 + 2][3]   += lazy[si][3];
        }
 
        // Set the lazy value for current node as 0 as it
        // has been updated
        lazy[si][0] = 0;
        lazy[si][1] = 0;
        lazy[si][2] = 0;
        lazy[si][3] = 0;
    }
 
    // out of range
    if (ss>se || ss>ue || se<us)
        return ;
 
    // Current segment is fully in range
    if (ss>=us && se<=ue)
    {
        // Add the difference to current node
        // tree[si][0] += (se-ss+1)*mp[diff][0];
        // tree[si][1] += (se-ss+1)*mp[diff][1];
        // tree[si][2] += (se-ss+1)*mp[diff][2];
        // tree[si][3] += (se-ss+1)*mp[diff][3];

        tree[si][0] += mp[diff][0];
        tree[si][1] += mp[diff][1];
        tree[si][2] += mp[diff][2];
        tree[si][3] += mp[diff][3];
 
        // same logic for checking leaf node or not
        if (ss != se)
        {
            // This is where we store values in lazy nodes,
            // rather than updating the segment tree itself
            // Since we don't need these updated values now
            // we postpone updates by storing values in lazy[]
            lazy[si*2 + 1][0]   += mp[diff][0];
            lazy[si*2 + 1][1]   += mp[diff][1];
            lazy[si*2 + 1][2]   += mp[diff][2];
            lazy[si*2 + 1][3]   += mp[diff][3];
            
            lazy[si*2 + 2][0]   += mp[diff][0];
            lazy[si*2 + 2][1]   += mp[diff][1];
            lazy[si*2 + 2][2]   += mp[diff][2];
            lazy[si*2 + 2][3]   += mp[diff][3];
        }
        return;
    }
 
    // If not completely in rang, but overlaps, recur for
    // children,
    int mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);
 
    // And use the result of children calls to update this
    // node
    tree[si][0] = max(tree[si*2+1][0] , tree[si*2+2][0]);
    tree[si][1] = max(tree[si*2+1][1] , tree[si*2+2][1]);
    tree[si][2] = max(tree[si*2+1][2] , tree[si*2+2][2]);
    tree[si][3] = max(tree[si*2+1][3] , tree[si*2+2][3]);
}
 
// Function to update a range of values in segment
// tree
/*  us and eu -> starting and ending indexes of update query
    ue  -> ending index of update query
    diff -> which we need to add in the range us to ue */
void updateRange(int n, int us, int ue, int diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}
 
 
/*  A recursive function to get the sum of values in given
    range of the array. The following are parameters for
    this function.
    si --> Index of current node in the segment tree.
           Initially 0 is passed as root is always at'
           index 0
    ss & se  --> Starting and ending indexes of the
                 segment represented by current node,
                 i.e., tree[si]
    qs & qe  --> Starting and ending indexes of query
                 range */
int getSumUtil(int ss, int se, int qs, int qe, int si)
{
    // If lazy flag is set for current node of segment tree,
    // then there are some pending updates. So we need to
    // make sure that the pending updates are done before
    // processing the sub sum query
    if (lazy[si][0] != 0 || lazy[si][1] != 0 || lazy[si][2] != 0 || lazy[si][3] != 0)
    {
        // Make pending updates to this node. Note that this
        // node represents sum of elements in arr[ss..se] and
        // all these elements must be increased by lazy[si]
        // tree[si] += (se-ss+1)*lazy[si];
        // tree[si][0] += (se-ss+1)*lazy[si][0];
        // tree[si][1] += (se-ss+1)*lazy[si][1];
        // tree[si][2] += (se-ss+1)*lazy[si][2];
        // tree[si][3] += (se-ss+1)*lazy[si][3];

        tree[si][0] += lazy[si][0];
        tree[si][1] += lazy[si][1];
        tree[si][2] += lazy[si][2];
        tree[si][3] += lazy[si][3];

        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // Since we are not yet updating children os si,
            // we need to set lazy values for the children

            // lazy[si*2+1] += lazy[si];
            // lazy[si*2+2] += lazy[si];

            lazy[si*2 + 1][0]   += lazy[si][0];
            lazy[si*2 + 1][1]   += lazy[si][1];
            lazy[si*2 + 1][2]   += lazy[si][2];
            lazy[si*2 + 1][3]   += lazy[si][3];
            
            lazy[si*2 + 2][0]   += lazy[si][0];
            lazy[si*2 + 2][1]   += lazy[si][1];
            lazy[si*2 + 2][2]   += lazy[si][2];
            lazy[si*2 + 2][3]   += lazy[si][3];
        }
 
        // unset the lazy value for current node as it has
        // been updated
        // lazy[si] = 0;

        lazy[si][0] = 0;
        lazy[si][1] = 0;
        lazy[si][2] = 0;
        lazy[si][3] = 0;
    }
 
    // Out of range
    if (ss>se || ss>qe || se<qs)
        return 0;
 
    // At this point we are sure that pending lazy updates
    // are done for current node. So we can return value 
    // (same as it was for query in our previous post)
 
    // If this segment lies in range
    if (ss>=qs && se<=qe)
        return max({tree[si][0],tree[si][1],tree[si][2],tree[si][3]});
 
    // If a part of this segment overlaps with the given
    // range
    int mid = (ss + se)/2;
    return max(getSumUtil(ss, mid, qs, qe, 2*si+1) ,
           getSumUtil(mid+1, se, qs, qe, 2*si+2));
}
 
// Return sum of elements in range from index qs (query
// start) to qe (query end).  It mainly uses getSumUtil()
int getSum(int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        cout <<"Invalid Input";
        return -1;
    }
 
    return getSumUtil(0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for
//  array[ss..se]. si is index of current node in segment
// tree st.
void constructSTUtil(vvi& arr, int ss, int se, int si)
{
    // out of range as ss can never be greater than se
    if (ss > se)
        return ;
 
    // If there is one element in array, store it in
    // current node of segment tree and return
    if (ss == se)
    {
        tree[si][0] = arr[ss][0];
        tree[si][1] = arr[ss][1];
        tree[si][2] = arr[ss][2];
        tree[si][3] = arr[ss][3];
        return;
    }
 
    // If there are more than one elements, then recur
    // for left and right subtrees and store the sum
    // of values in this node
    int mid = (ss + se)/2;
    constructSTUtil(arr, ss, mid, si*2+1);
    constructSTUtil(arr, mid+1, se, si*2+2);
 
    // tree[si] = tree[si*2 + 1] + tree[si*2 + 2];
    tree[si][0] = min(tree[si*2+1][0] , tree[si*2+2][0]);
    tree[si][1] = max(tree[si*2+1][1] , tree[si*2+2][1]);
    tree[si][2] = max(tree[si*2+1][2] , tree[si*2+2][2]);
    tree[si][3] = max(tree[si*2+1][3] , tree[si*2+2][3]);
}
 
/* Function to construct segment tree from given array.
   This function allocates memory for segment tree and
   calls constructSTUtil() to fill the allocated memory */
void constructST(vvi& arr, int n)
{
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, 0);
}
 







void solve(){
    int n,q;
    cin>>n>>q;

    // vector<vi> arr(n,vi(4));
    // constructST(arr, n);
    // debugcc(tree);
    while(q--){
        string s;
        cin>>s;
        if(s=="MULTIPLY"){
            int l,r,x;
            cin>>l>>r>>x;
            updateRange(n, l-1, r-1, x);
    debugcc(tree);
    debugcc(lazy);

        }else{
            int l,r;
            cin>>l>>r;
            int ans = getSum(n,l-1,r-1);
    debugcc(tree);
    debugcc(lazy)
            cout<<"ANSWER "<<ans<<endl;
        }
        debug("")
    }

    

}

int main(){
    fastcin();

    int t=1;
    // cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
