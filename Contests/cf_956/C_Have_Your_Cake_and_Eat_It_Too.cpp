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
    vi va(n),vb(n), vc(n);
    vll vacc(n+1),vbcc(n+1), vccc(n+1);
    ll tot=0;
    rep(i,0,n){
        cin>>va[i];
        tot+=va[i];
        
    }
    rep(i,0,n){
        cin>>vb[i];
        
    }
    rep(i,0,n){
        cin>>vc[i];
        
    }
    ll x = tot/3 + (tot%3!=0);



    rep(i,1,n+1){
        vacc[i]=va[i-1]+vacc[i-1];
        
    }
    rep(i,1,n+1){
        vbcc[i]=vb[i-1]+vbcc[i-1];
        
        
    }
    rep(i,1,n+1){
        vccc[i]=vc[i-1]+vccc[i-1];
        
        
    }
    int f,kk,kkk;
    vector<vi>range(6, vi(8));
    
    
    f = 1;
    kk = 0;
    debug(x);
    debug(tot);
    kkk=0;
    rep(i,1,n+1){
        debug(f)
        if(f==1){
            vll& v = vacc;
            debug(v[i])
            debug(v[kk])
            if(v[i]-v[kk]>=x){
                debug(1)
            f++;
            range[kkk][0]=kk+1;
            range[kkk][1]=i;
            kk=i;
        }
        }
        if(f==2){
            vll& v = vbcc;
            if(v[i]-v[kk]>=x){
            f++;
            range[kkk][2]=kk+1;
            range[kkk][3]=i;
            kk=i;
        }
        }
        if(f==3){
            vll& v = vccc;
            if(v[i]-v[kk]>=x){
            f++;
            range[kkk][4]=kk+1;
            range[kkk][5]=i;
            kk=i;
        }
        }
    }
    if(f==4){
        rep(i,0,6){
            cout<<range[kkk][i]<<" ";
        }
        cout<<endl;
        return;
    }
    




    f = 1;
    kk = 0;
    debug(x);
    debug(tot);
    kkk=1;
    rep(i,1,n+1){
        debug(f)
        if(f==1){
            vll& v = vacc;
            debug(v[i])
            debug(v[kk])
            if(v[i]-v[kk]>=x){
                debug(1)
            f++;
            range[kkk][0]=kk+1;
            range[kkk][1]=i;
            kk=i;
        }
        }
        if(f==3){
            vll& v = vbcc;
            if(v[i]-v[kk]>=x){
            f++;
            range[kkk][2]=kk+1;
            range[kkk][3]=i;
            kk=i;
        }
        }
        if(f==2){
            vll& v = vccc;
            if(v[i]-v[kk]>=x){
            f++;
            range[kkk][4]=kk+1;
            range[kkk][5]=i;
            kk=i;
        }
        }
    }
    if(f==4){
        rep(i,0,6){
            cout<<range[kkk][i]<<" ";
        }
        cout<<endl;
        return;
    }






    f = 1;
    kk = 0;
    debug(x);
    debug(tot);
    kkk=2;
    rep(i,1,n+1){
        debug(f)
        if(f==2){
            vll& v = vacc;
            debug(v[i])
            debug(v[kk])
            if(v[i]-v[kk]>=x){
                debug(1)
            f++;
            range[kkk][0]=kk+1;
            range[kkk][1]=i;
            kk=i;
        }
        }
        if(f==1){
            vll& v = vbcc;
            if(v[i]-v[kk]>=x){
            f++;
            range[kkk][2]=kk+1;
            range[kkk][3]=i;
            kk=i;
        }
        }
        if(f==3){
            vll& v = vccc;
            if(v[i]-v[kk]>=x){
            f++;
            range[kkk][4]=kk+1;
            range[kkk][5]=i;
            kk=i;
        }
        }
    }
    if(f==4){
        rep(i,0,6){
            cout<<range[kkk][i]<<" ";
        }
        cout<<endl;
        return;
    }



    f = 1;
    kk = 0;
    debug(x);
    debug(tot);
    kkk=3;
    rep(i,1,n+1){
        debug(f)
        if(f==2){
            vll& v = vacc;
            debug(v[i])
            debug(v[kk])
            if(v[i]-v[kk]>=x){
                debug(1)
            f++;
            range[kkk][0]=kk+1;
            range[kkk][1]=i;
            kk=i;
        }
        }
        if(f==3){
            vll& v = vbcc;
            if(v[i]-v[kk]>=x){
            f++;
            range[kkk][2]=kk+1;
            range[kkk][3]=i;
            kk=i;
        }
        }
        if(f==1){
            vll& v = vccc;
            if(v[i]-v[kk]>=x){
            f++;
            range[kkk][4]=kk+1;
            range[kkk][5]=i;
            kk=i;
        }
        }
    }
    if(f==4){
        rep(i,0,6){
            cout<<range[kkk][i]<<" ";
        }
        cout<<endl;
        return;
    }




    f = 1;
    kk = 0;
    debug(x);
    debug(tot);
    kkk=4;
    rep(i,1,n+1){
        debug(f)
        if(f==3){
            vll& v = vacc;
            debug(v[i])
            debug(v[kk])
            if(v[i]-v[kk]>=x){
                debug(1)
            f++;
            range[kkk][0]=kk+1;
            range[kkk][1]=i;
            kk=i;
        }
        }
        if(f==1){
            vll& v = vbcc;
            if(v[i]-v[kk]>=x){
            f++;
            range[kkk][2]=kk+1;
            range[kkk][3]=i;
            kk=i;
        }
        }
        if(f==2){
            vll& v = vccc;
            if(v[i]-v[kk]>=x){
            f++;
            range[kkk][4]=kk+1;
            range[kkk][5]=i;
            kk=i;
        }
        }
    }
    if(f==4){
        rep(i,0,6){
            cout<<range[kkk][i]<<" ";
        }
        cout<<endl;
        return;
    }




    f = 1;
    kk = 0;
    debug(x);
    debug(tot);
    kkk=5;
    rep(i,1,n+1){
        debug(f)
        if(f==3){
            vll& v = vacc;
            debug(v[i])
            debug(v[kk])
            if(v[i]-v[kk]>=x){
                debug(1)
            f++;
            range[kkk][0]=kk+1;
            range[kkk][1]=i;
            kk=i;
        }
        }
        if(f==2){
            vll& v = vbcc;
            if(v[i]-v[kk]>=x){
            f++;
            range[kkk][2]=kk+1;
            range[kkk][3]=i;
            kk=i;
        }
        }
        if(f==1){
            vll& v = vccc;
            if(v[i]-v[kk]>=x){
            f++;
            range[kkk][4]=kk+1;
            range[kkk][5]=i;
            kk=i;
        }
        }
    }
    if(f==4){
        rep(i,0,6){
            cout<<range[kkk][i]<<" ";
        }
        cout<<endl;
        return;
    }


    cout<<-1<<endl;




}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
