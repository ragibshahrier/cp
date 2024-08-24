#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; ii<n; ii++)
#define gp " "
#define DEBG

#define debug(n)
#define debugi(n)
#ifdef DEBG
#define debugi(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debug(n) cout<<__LINE__<<gp<<#n<<gp;cout<<"[";rep(iii,0,100){cout<<n[iii]<<gp;}cout<<"]"<<endl;
#endif


int main(){

    int t,n,b=0;
    cin>>t;
    while(t--){
        b=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int i;
        for(i=0;i<n+2;i++){
            // rep(i, 0, n){
            //     cout<<a[i]<<" ";
            // }
            debug(a)
            debugi(i)

            for(int j=1; j<n;j++){
                debug(a)
                debugi(n)
                debugi(n-j-1)

                if(a[n-j-1]==n-j){
                    a[n-j-1]=a[n-j-1]-a[n-j-1];
                    a[n-j]=a[n-j]-a[n-j];
                    b=b+1;
                    n=n-2;
                    
                    debug(a)
                    for(int k=(n+2)-j-1, m=0; k<n; k++){
                        for(;m<=2;m++){
                            debug(a)
                            debugi(k)
                            debugi(m)
                            debugi(a[m+k])
                            if(a[m+k]==0){
                                continue;
                            }
                            else{
                            
                                a[k]=a[m+k];
                                break;
                            }
                        }
                        debug(a)
                        debugi(k)
                    }
                    debug(a)
                }
                else{
                    debugi(1)
                    continue;
                }
                    debugi(1)
                break;
            }
            //if(j==n)break;
        
        }
        debugi(n)
        debugi(i)
        cout<<b<<endl;
    }

}