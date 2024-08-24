#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; i<n; i++)
#define gp <<" "
//#define DEBG

#define debug(n)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#endif

//----------------------CODE STARTS HERE-------------------


int difff(int dt, int m , int y){
    int ans=0;
    ans+=(y-2000)*365+((y-2001)/4)+1;
    if(m>=1)ans+=0;
    if(m>=2)ans+=31;
    if(m>=3){
        if(y%4==0){
            ans+=29;
        }else ans+=28;
    }
    if(m>=4)ans+=31;
    if(m>=5)ans+=30;
    if(m>=6)ans+=31;
    if(m>=7)ans+=30;
    if(m>=8)ans+=31;
    if(m>=9)ans+=31;
    if(m>=10)ans+=30;
    if(m>=11)ans+=31;
    if(m>=12)ans+=30;
    ans+=dt;
    return ans;
}



void solve(){
    string d1, d2;
    cin>>d1>>d2;
    int dt1=0,dt2=0,m1=0,m2=0,y1=0,y2=0;
    for(int i=0; i<d1.length(); i++){
        int x = d1[i]-'0';
        if(i==0)dt1+=10*x;
        if(i==1)dt1+=x;
        if(i==3)m1+=x*10;
        if(i==4)m1+=x;
        if(i==6)y1+=x*1000;
        if(i==7)y1+=x*100;
        if(i==8)y1+=x*10;
        if(i==9)y1+=x*1;
        
    }
    for(int i=0; i<d2.length(); i++){
        int x = d2[i]-'0';
        if(i==0)dt2+=10*x;
        if(i==1)dt2+=x;
        if(i==3)m2+=x*10;
        if(i==4)m2+=x;
        if(i==6)y2+=x*1000;
        if(i==7)y2+=x*100;
        if(i==8)y2+=x*10;
        if(i==9)y2+=x*1;
        
    }

    int diff=0, dif1=0, dif2=0;
    dif1 = difff(dt1, m1, y1);
    dif2 = difff(dt2, m2, y2);
    diff=dif2-dif1;

    int ans = diff/7;
    cout<<ans<<"\n";
    


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
