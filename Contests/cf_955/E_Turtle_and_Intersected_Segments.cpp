#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; i<n; i++)
#define gp " ";
#define debug(n) cout<<__LINE__<<gp<<n<<endl;

ll diffsum(vi& v, int n1, int k){
    ll sum=0;
    int n=(n1/2)*2;
    for(int i=0; i<n-1; i+=2){
        sum+=(v[i+1]-v[i])/k;
    }
    ll tempsum = sum;
    if(n1!=n){
        n=n1;
        for(int i=n-3; i>=0; i-=2){
            tempsum = tempsum-((v[i+1]-v[i])/k)+((v[i+2]-v[i+1])/k);
            sum= min(sum,tempsum); 
            /*debug(sum);
            debug(v[i+1]);
            debug(v[i]);
            debug(v[i+2]);
            debug(i);
            cout<<endl;
            */
        }

    }
    //debug(sum);
    return sum;
}

void solve(){
    int n, k;
    cin>>n>>k;
    vi v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    if(n==1){
        cout<<0<<endl;return;
    }
    sort(v.begin(),v.end());

    //for(auto el:v)cout<<el<<" ";
    //cout<<endl;


    map<int,ll> modcnt;
    map<int,vi> modv;
    map<int,ll>modans;

    for(auto el:v){
        modcnt[el%k]++;
        modv[el%k].push_back(el);
        modans[el%k]=-1;
    }
    ll oddcnt=0;
    for(auto el:modcnt){
        if(el.second%2)oddcnt++;
    }
    if(oddcnt>1){cout<<-1<<endl;return;}
    ll ans=0;
    for(auto el:modcnt){
        ll tempsum,t1, t2;
        if(el.second%2==0){
            tempsum=diffsum(modv[el.first], el.second, k);
        }else{
            //t1= diffsum(modv[el.first],el.second, k);
            //t2=diffsum(it,el.second-1, k);
            tempsum=diffsum(modv[el.first], el.second, k);
        }
        ans+=tempsum;
    }
    cout<<ans<<endl;



}



 
int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
