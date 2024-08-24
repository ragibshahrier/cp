#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
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

#define DEBG

#define debug(n)
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;
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



void preprocessing(){
}

void solve(){
    vector<vector<char>>aa(26);
    
    int n;cin>>n;
    string s;cin>>s;
    
    vi hsh(26,-1);
    int i,j;
    string un;
    for(i=0; i<s.length();i++){
        if(hsh[s[i]-'a']==-1){
            hsh[s[i]-'a']=1;
            un.push_back(s[i]);
        }

    }
    int xx= un.size();
    rep(i,0,26){
        if(hsh[i]==-1){
            un.push_back(i+'a');
            hsh[i]=1;
        }
    }
    // rep(i,0,26){
    //     // sort(aa[i])
    // }
    map<char,char>mp;
    vi tik(26);
    char x = s[0];
    i=0;
    bool r=1;
    debug(un)
    do{
        int ii = i;
            debug(un[i])
            debug(r)
        if(r){
            int j = i+1;
            int mini=j;
            while(j<=25){
                if(un[mini]>un[j] && tik[mini]==0){
                    mini=j;
                    debug(mini)
                    debug(tik[mini])
                }
                j++;
            }
            debug(mini)
            debug(tik[mini])
            if(mini>=26){
                r=0;
            }else{
                mp[un[i]]=un[mini];
                i=mini;
                debug(mini)
                debug(un[mini])
                debug(tik[mini])
                tik[mini]=1;

            }

        }
        else{
            int j=i-1;
            while(tik[j]==1){
                j--;
            }
            tik[j]=1;
            mp[un[i]]=un[j];
            i=j;
        }
            debug(mp[un[ii]])
        if(ii<xx-1 && i>=xx){
            i=ii+1;
        }
        debug(i)
    }while(i!=0);
    
    
    for(auto el:s){
        cout<<mp[el];
    }
    cout<<endl;
    

}

int main(){
    fastcin();

    int t=1;
    cin>>t;
    preprocessing();
    while(t--)solve();
    return 0;
}
