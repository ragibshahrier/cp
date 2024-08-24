#include<stdio.h>
typedef long long ll;


//==============================CODE STARTS HERE==============================//



int main(){
    int t=1;
    scanf("%lld " , &t);

    while(t--){
        ll a,b,c;
        // cin>>a>>b>>c;
        scanf("%lld %lld %lld ", &a, &b, &c);
        // ll lcmm = (a/(__gcd(a,b)))*b;
        // ll x = (a>b)?a:b;
        // ll y = (a<b)?a:b;
        // vll ans;
        for(ll i=a*b; i<=c;i+=a*b){
            // if(i%y == 0){
                // cout<<i<<endl;
                printf("%lld\n", i);
            // }
        }
        printf("\n");
    }
    return 0;
}
