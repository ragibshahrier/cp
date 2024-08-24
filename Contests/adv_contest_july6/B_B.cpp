#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define bool int
#define int long long
#define vi vector<ll>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pair<int,int>>
#define rep(ii,st, n) for(int ii=st; ii<n; ii++)
#define gp " "


//bit_manupulation
#define checkbit(x,n) ((x&(1LL<<n))!=0)
#define setbit(x,n) (x=(x|(1LL<<n)))
#define resetbit(x,n) (x=(x&(~(1LL<<n))))


// #define DEBG

#define debug(n)
#define debugc(a)
#ifdef DEBG
#define debug(n) cout<<__LINE__<<gp<<#n<<gp<<n<<endl;
#define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp; for(auto el:a){cout<<el<<" ";}cout<<gp<<']'<<endl;
#endif

//----------------------CODE STARTS HERE-------------------


vector<vll>maze(1050, vll(3));
int rr,c;
vector<vi> trak(1050, vi(150,-1));
vector<vi> trak2(1050, vi(150,-1));



void rotatenut(pair<ll,ll>& nut){
    int x = checkbit(nut.first, 0);
    int y = checkbit(nut.second, 0);
    
    nut.first>>=1;
    if(y)setbit(nut.first, (c/2 - 1));
    
    nut.second>>=1;
    if(x)setbit(nut.second, (c - c/2 - 1));
}
void rotatenutr(pair<ll,ll>& nut){
    int x = checkbit(nut.first, (c/2 - 1));
    resetbit(nut.first, (c/2 - 1));
    debug(x)


    int y = checkbit(nut.second, (c - c/2 - 1));
    resetbit(nut.second, (c - c/2 - 1));
    debug(y)
    nut.first<<=1;
    if(y)setbit(nut.first, 0);
    
    nut.second<<=1;
    if(x)setbit(nut.second, 0);

}

bool check(pair<ll,ll>& nut, vll& mazero){
    if((nut.first & mazero[0])==0 && (nut.second & mazero[1])==0){
        return 1;
    }
    else{
        return 0;
    }
}

int modulo(int n, int c){
    if(n>=0)return (n%c);
    else return ((n%c)+c);
}

int func(int mazero, int i, int j, pair<ll,ll>nut){
    debug(" ")
    debug(" ")
    debug(" ")

    debug(mazero)
    debug(i)
    debug(nut.first)
    debug(nut.second)

    if(mazero<0)return 0;
    if(j<0)return 0;

    if(trak[j][i]!=-1)return 0;

    if(!check(nut, maze[mazero]))return 0;

    if(mazero==rr){
        debug("returning 1")
        return 1;
    }
    trak[j][i]=1;

    debug(1)
    
    debug(1)



    int x;
    x = func(mazero-1,modulo(i,c),((j-1)), nut);
    if(x)return 1;
    debug(x)
    debug(1)

    x = func(mazero+1,modulo(i,c),((j+1)), nut);
    debug(x)
    if(x)return 1;

    debug(x)
    debug(1)


    
    rotatenut(nut);
    x = func(mazero,modulo(i+1,c),(j) ,nut);
    if(x)return 1;

    debug(x)
    debug(1)
    debug(nut.first)
    debug(nut.second)

    rotatenutr(nut);

    debug(nut.first)
    debug(nut.second)


    rotatenutr(nut);

    debug(nut.first)
    debug(nut.second)


    x = func(mazero, modulo(i-1,c),(j) , nut);
    if(x)return 1;

    debug(x)
    debug(1)


    return 0;
}

void solve(){
    
    cin>>rr>>c;
    //list<int>nut, nutr;
    ll nut1=0,nut2=0;
    pair<ll,ll>nut;
    ll nut1r=0,nut2r=0;
    pair<ll,ll>nutr;
    string s;
    cin>>s;
    int jjj=0;
    rep(i,0,c/2){
        char x;
        x = s[jjj];
        
        if(x=='1'){
            setbit(nut1, (c)/2 - i-1);
            
        }
        jjj++;
    }
    rep(i,c/2,c){
        char x;
        x = s[jjj];
        if(x=='1'){
            setbit(nut2, c - i -1);
            
        }
        jjj++;
    }

    jjj=s.size()-1;


    rep(i,0,c/2){
        char x;
        x = s[jjj];
        
        if(x=='1'){
            setbit(nut1r, (c)/2 - i-1);
            
        }
        jjj--;
    }
    rep(i,c/2,c){
        char x;
        x = s[jjj];
        if(x=='1'){
            setbit(nut2r, c - i -1);
            
        }
        jjj--;
    }

    


    rep(i,1,rr+1){
        rep(j,0,c/2){
            char x;
            cin>>x;
            if(x=='1')setbit(maze[i][0], (c)/2 - j-1);
        }
        rep(j,c/2,c){
            // debug(j)
            // debug(c-j-1)
            char x;
            cin>>x;
            // debug(x)
            if(x=='1')setbit(maze[i][1], c - j -1);
        }

    }
    debug(nut1)
    debug(nut2)
    nut = {nut1,nut2};
    nutr = {nut1r,nut2r};
    debug(maze[1][0])
    debug(maze[1][1])
    
    int ans = func(0, 0, 0, nut);
    
    if(ans==0){
        debug("turning")
        trak=trak2;
        ans = func(0, 0, 0, nutr);

    }
    if(ans==1)cout<<'Y';
    else cout<<'N';

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();

    
    return 0;
}


