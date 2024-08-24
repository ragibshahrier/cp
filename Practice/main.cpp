#include<bits/stdc++.h>
using namespace std; 


#define debug(v) cout<<#v<<endl;

long double pow2(long double x){
    return x*x;
}
int main(){

    int a, b;
    cin>>a>>b;
    int x = 0;
    for(x=0; ; x++){
        cout<<a<<" "<<b<<" "<<x<<endl;
        
        a = pow(3, x)*a;
        b = pow(2, x)*b;
        cout<<a<<" "<<b<<" "<<x<<endl;
        if(a>b)break;
    }
    cout<<x;

}


