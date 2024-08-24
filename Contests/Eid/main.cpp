#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int min(int a, int b){
    if(a<b)return a;
    else return b;
}

void solve(){
    int n,m;
    int a[200], b[200];
    scanf("%d",&n);
    for(int i='a'; i<='z'; i++){
        a[i]=0;
        b[i]=0;
    }
    for(int i=0; i<n; i++){
        char ch;
        
        scanf("%c", &ch);
        a[(int)ch]++;
    }
    scanf("%d",&m);
    for(int i=0; i<m; i++){
        char ch;
        
        scanf("%c", &ch);
        b[(int)ch]++;
    }
    int ans=1e9;
    for(int i='a'; i<='z'; i++){
        if(b[i]!=0){
            ans=min(ans, a[i]/b[i]);
        }
    }
    printf("%d\n", ans);
}


int main() {

    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}