#include<stdio.h>

int main(){
    int j,i,k,a=5;
    
    int b = ++a + a++ + --a;
    printf("%d", b);
}