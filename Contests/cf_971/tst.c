#include<stdio.h>

long long ncr(int n, int r){
    if (r==0 || n==r)return 1;
    return ncr(n-1,r-1)+ncr(n-1, r);
}

int main(){
    int n,r;
    scanf("%d %d", &n, &r);
    long long ans = ncr(n,r);
    printf("%lld", ans);
    





}
// int main(){
//     int n;
//     scanf("%d", &n);
//     unsigned int po = 1;
//     int lft = 0;
//     while(po<=n){
//         po*=2;
//         lft ++;
//     }
//     int ans = 32-lft;
//     printf("%d", ans);





// }
// int main(){
//     int x, n;
//     scanf("%d %d",&x, &n);
//     double sum = 0;
//     double numerator = 1;
//     double denominator = 2;
//     sum+= numerator/denominator;
    
//     for(int i = 1; i<n; i++){
//         numerator = -numerator * (x*x);
//         denominator = denominator*((2*i+1) * (2*i+2));
//         sum+= numerator/denominator;
//     }
//     printf("%lf" , sum);



// }