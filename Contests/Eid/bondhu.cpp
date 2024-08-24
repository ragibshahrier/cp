#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 

//#define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

void solve(){
    int n;
    scanf("%d",&n);

    int arr[200], arrb[200];
    for(int i=0; i<200;i++){
        arr[i]=0;
        arrb[i]=0;
    }
    for(int i=0; i<n; i++){
        char x;
        scanf("%c",&x);
        int y = (int)x;
        arr[y]++;
        
    }
    int m;
    scanf("%d",&m);
    
    for(int i=0; i<m; i++){
        char x;
        scanf("%c",&x);
        int y = (int)x;
        arrb[y]++;
        
    }
    
    for(int i='a'; i<='z'; i++){
         printf("%d", arrb[i]);
    }
    
    int ans=INT_MAX;
    for(int i='a'; i<='z'; i++){
        if(arrb[i]){
            ans=min(ans, arr[i]/arrb[i]);
        }
    }
    printf("%d\n", ans);


}

int main(){
    int t=1;
    scanf("%d",&t);
    //cout<<t<<endl;
    while(t--)solve();
    return 0;
}