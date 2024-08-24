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
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
#endif

//----------------------CODE STARTS HERE-------------------

const int N = 1e5;

vi primes;
vi ert(N+7);

void solve(){
    int n;
    cin>>n;
    int n1 = n;
    vpi facts;
    ll totcnt=0;
    for(auto el:primes){
        int count  = 0;
        while((n%el)==0){
            n/=el;
            count++;
            totcnt++;
        }
        if(count)facts.push_back({el,count});
    }
    vll ans;
    for(auto el:facts){
        debugc(ans)
        // for(auto x:facts){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        if(ans.size()<2){
            if(el.second<=2){
                ans.push_back(el.first);
                n1/=el.first;

            }else if(el.second>2){
                ans.push_back(el.first);
                n1/=el.first;
                if(ans.size()<2){
                    ans.push_back(el.first*el.first);
                    n1/=(el.first*el.first);
                }
            }
        }
        else{
            break;
        }
    }
    debugc(ans)
    if(n1!=1)ans.push_back(n1);
    if(ans[0]==ans[1] || ans[1]==ans[2] || ans[0]==ans[2] || ans.size()!=3){
        cout<<"NO";
    }else{
        cout<<"YES"<<endl;
        for(auto el:ans){
            cout<<el<<" ";
        }

    }
    cout<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=2; i<=N; i++){
        if(ert[i]==0){
            primes.push_back(i);
            for(int j = i+i; j<=N; j+=i){
                ert[i]=1;
            }
        }
    }
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
