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
// #define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

void solve(){
    int n, d, l;
    cin>>n>>d>>l;
    vector<int> ans;
    bool done = 0;
    if(l==1){
        if(((n&1) && d==1) || (!(n&1) && d==0)){
            rep(i,0,n){
                cout<<1<<" ";
            }
            return;
        }else{
            cout<<-1;
            return;
        }
    }
    do {
        debug(d)
        debug(ans.size())
        if(d>0){
            debug(l)
            if(d<=l){
                ans.push_back(d);
                n--;
                d=0;
            }else{
                ans.push_back(l);
                d = l-d;
                n--;
            }

        debug(1)
        }
        else if(d<0){
        debug(1)
            ans.push_back(1);
            n--;
            d = 1-d;
        }
        if(d==0){
            if(n<0)break;
            if((n&1) == 0){
                done = 1;
                break;
            }
            debug(ans.size())
            debug(ans[ans.size()-1]);
            if(ans.size()>0 && ans[ans.size()-1]!=l){
                ans[ans.size()-1]++;
                ans.push_back(1);
                n--;
                done = 1;
                break;
            }
            ans.push_back(1);
            ans.push_back(2);
            ans.push_back(1);
            n--;n--;n--;
            done = 1;
            break;


        }
    }while(n>0);
        debug(n)
    if(n<0 || done==0){
        cout<<-1;return;
    }
    while(n>0){
        ans.push_back(1);
        n--;
    }
    for(auto el:ans){
        cout<<el<<" ";
    }




}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
