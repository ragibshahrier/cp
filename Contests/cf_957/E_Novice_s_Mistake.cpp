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
    int n;
    cin>>n;
    vpi ans;
    if(n==1){
        cout<<9999<<endl;
        for(int i=1; i<=9999; i++){
            cout<<i+1<<" "<<i<<endl;
        }
        return;
    }
    if(n<10){
        vi v;
        v.push_back(n*(100000+10000+1000+100+10+1));
        v.push_back(n*(10000+1000+100+10+1));
        v.push_back(n*(1000+100+10+1));
        v.push_back(n*(100+10+1));
        v.push_back(n*(10+1));
        v.push_back(n*(1));

        for(int i= v.size()-1; i>=0; i--){
            int el = v[i];
            debug(el)
            int dig = 6-i;
            debug(dig)
            if(((el-dig)%(n-1)) == 0 && n!=1){
                int a = (el-dig)/(n-1);
                debug(a)
                int b = n*a-el;
                debug(b)
                if(a>0 && a<=10000 && b>0 && b<10000){
                    debug(1)
                    ans.push_back({a,b});
                }
                
                
            }
        }
       

    }
    else if(n<100){
        vi v;
        v.push_back(n*(10000+100+1));
        v.push_back(n*(1000+10)+n/10);
        v.push_back(n*(100+1));
        v.push_back(n*(10)+n/10);
        v.push_back(n*(1));
        v.push_back(n/10);

        for(int i= v.size()-1; i>=0; i--){
            int el = v[i];
            debug(el)
            int dig = 6-i;
            debug(dig)
            if(((el-dig)%(n-2)) == 0 && n!=2){
                int a = (el-dig)/(n-2);
                debug(a)
                int b = n*a-el;
                debug(b)
                if(a>0 && a<=10000 && b>0 && b<10000){
                    debug(1)
                    ans.push_back({a,b});
                }
                
                
            }
        }
       

    }
    else if(n<1000){
        vi v;
        v.push_back(n*(1000+1));
        v.push_back(n*100+n/10);
        v.push_back(n*10+n/100);
        v.push_back(n);
        v.push_back(n/10);
        v.push_back(n/100);

        for(int i= v.size()-1; i>=0; i--){
            int el = v[i];
            debug(el)
            int dig = 6-i;
            debug(dig)
            if(((el-dig)%(n-3)) == 0 && n!=3){
                int a = (el-dig)/(n-3);
                debug(a)
                int b = n*a-el;
                debug(b)
                if(a>0 && a<=10000 && b>0 && b<10000){
                    debug(1)
                    ans.push_back({a,b});
                }
                
                
            }
        }

       

    }
    debug(1)
    if(ans.size()==0){
        cout<<0<<endl;
        return;
    }
    cout<<ans.size()<<endl;
    debug(1)
    for(auto el : ans){
        cout<<el.first<<" "<<el.second<<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t=1;
    cin>>t;
    while(t--)solve();
    // cout<<100<<endl;
    // for(int i=1; i<=100;i++){
    //     cout<<i<<endl;
    // }
    return 0;
}
