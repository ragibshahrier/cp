#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define rep(ii,n) for(int ii=0; i<n; i++)
#define debug(n) cout<<n<<endl;
#define sc second;
#define fr first;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n+3, vector<int>(m+3));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>mat[i][j];
        }
    }
    multiset<pair<int, pair<int,int>>>ms;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(mat[i][j]>mat[i+1][j]&&
                mat[i][j]>mat[i-1][j]&&
                mat[i][j]>mat[i][j+1]&&
                mat[i][j]>mat[i][j-1]
            ){
                ms.insert({mat[i][j],{i,j}});
            }
        }
    }
    for(auto el: ms){
        int i = el.second.first;
        int j = el.second.second;
        mat[i][j]=max(max(mat[i+1][j],mat[i-1][j]),
                max(mat[i][j+1],mat[i][j-1]));
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }


    
}



 
int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}