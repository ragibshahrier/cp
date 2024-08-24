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
    list<int>us;
    map<int, list<int>::iterator>s;
    int n, k;
    cin>>n>>k;
    vi v(n), v2(2e5 + 7);
    

    rep(i,0,n){
        cin>>v[i];
        us.push_back(v[i]);
        auto it = us.end();
        it--;
        s.insert({v[i],it});

    }
    int move = 1;
    debug(us.size())
    while(us.size()!=0){
    debug(us.size())
        auto it = s.end();
        it--;
        int maxi = it->first;
        auto itc = it->second;
        auto iti = itc;
        iti++;
        int kn = 0;
        while(iti!=us.end() && kn<k){
            auto itii = iti;
            v2[*iti] = (1-move)+1;
            iti++;
            int temp = *itii;
            s.erase(temp);
            us.erase(itii);
            kn++;
        }


    debug(us.size())
    
        iti = itc;
        if(iti!=us.begin())iti--;
        kn = 0;
        while(iti!=us.begin() && kn<k){
            auto itii = iti;
            v2[*iti] = (1-move)+1;
            iti--;
            int temp = *itii;
            s.erase(temp);
            us.erase(itii);
            kn++;
        }
    
    debug(us.size())
    
    
        if(kn!=k && iti!=itc){
            auto itii = iti;
            v2[*iti] = (1-move)+1;
            int temp = *itii;
            s.erase(temp);
            us.erase(itii);
    debug(us.size())
            kn++;
        }
        v2[*itc] = (1-move)+1;
        s.erase(it);
        us.erase(itc);

        move = 1-move;
    }
    rep(i,0,n){
        cout<<v2[v[i]];
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
