#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; i<n; i++)
#define gp " "
//#define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif


void solve(){
    string s;
    cin>>s;
    string s1="heavy";
    string s2="metal";
    int i=0, j=0, heavy=0, metal=0;
    ll ans=0;

    for(auto ch:s){
        if(ch==s1[i]){
            j=0;
            if(i==4){
                heavy++;
                i=0;
            }else{
                i++;
            }
        }else if(ch==s2[j]){
            i=0;
            if(j==4){
                metal++;
                j=0;
                ans+=heavy;
            }else{
                j++;
            }
        }else{
            i=0;j=0;
            if(ch==s1[i]){
                j=0;
                if(i==4){
                    heavy++;
                    i=0;
                }else{
                    i++;
                }
            }else if(ch==s2[j]){
                i=0;
                if(j==4){
                    metal++;
                    j=0;
                    ans+=heavy;
                }else{
                    j++;
                }
            }
            

        }
    }
    cout<< ans<<endl;


}



 
int main(){
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}
