#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define vi vector<int>
#define vpi vector<pair<int,int>>
#define rep(ii,n) for(int ii=0; i<n; i++)
#define debug(n) cout<<n<<endl;

ll lcm(ll LCM, ll a){
    return (LCM*a)/__gcd(LCM,a);
}
int logi(int a){
    int i=0;

    while(a!=1&&a>0){
        a/=2;
        i++;
    }return i;
}


bool gapfill(vi & ansv, vpi & notm, int i, int j, int typ){
    int n=ansv.size();
    if(i==j)return 0;
    
    if(typ==1){
        int y = ansv[j];
        for(int ii=j; ii>=i; ii--){
            ansv[ii]=y/(2-((j-ii)%2));
        }
        debug(y);
        return 0;
    }else if(typ==3){
        int x=ansv[i];
        for(int ii=i; ii<=j; ii++){
            ansv[ii]=x/(2-((ii-i)%2));
        }
    }else{
        int x=notm[i].first, y=notm[j].first;
        debug(x)
        if(j-i==1){
            if((y/2==x)||(x/2==y)){
                return 0;
            }else return 1;
        }
        vi temp(n);
        temp[j-i]=y;
        temp[i]=x;
        int lx=logi(x), ly=logi(y), bet=j-i-1, ii, jj;
        for(ii=i+1, jj=j-i-1; ii>=jj && temp[ii]!=temp[jj];){
            if(lx>ly){
                temp[ii]=temp[ii-1]/2;
                ii++;
                lx--;
                bet--;
            }else if(lx<ly){
                temp[jj]=temp[jj+1]/2;
                jj--;
                ly--;
                bet--;
            }else{
                temp[ii]=temp[ii-1]/2;
                temp[jj]=temp[jj+1]/2;
                ii++;
                lx--;
                bet--;
                jj--;
                ly--;
                bet--;

            }

        }
        if(bet>0){
            if(bet%2){
                return 1;
            }else{
                gapfill(temp, notm, ii, jj, 3);
                for(int iii=i; iii<=j; iii++){
                    ansv[iii]=temp[iii];
                }
            }
        }else if(bet==0 && temp[ii] == temp[jj]){
            for(int iii=i; iii<=j; iii++){
                ansv[iii]=temp[iii];
            }
        }else return 1;

    }
    return 0;
}

void solve(){
    int n;
    cin>>n;
    vi v(n), ansv(n);
    vpi notm;
    rep(i, n){
        cin>>v[i];
        if(v[i]!=-1){
            notm.push_back({v[i], i});
        }

    }
    if(notm.size()==0){
        rep(i,n){
            cout<<1+(1%i)<<" ";
            
        }cout<<endl;return;
    }
    bool f=0;
    debug(ansv.size())
    f|=gapfill(ansv, notm, 0, notm[0].second, 1);
    rep(i,notm.size()-1){
        f|=gapfill(ansv, notm, notm[i].second, notm[i+1].second, 2);
    }
    f|=gapfill(ansv, notm, notm[notm.size()-1].second, n-1, 3);
    if(f)cout<<-1<<endl;return;
    for(auto el:ansv){cout<<el<<" ";}
    
    cout<<endl;


}


int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
