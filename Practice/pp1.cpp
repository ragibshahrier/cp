#include<bits/stdc++.h>
using namespace std;

int checkbit(int i, int a){
    if(a & (1<<i))return 1;
    else return 0;
}
int setbit(int i, int a){
    a = a|(1<<i);
    return a;
}

int main(){
    int n;
    cin>>n;
    int x=0;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<31; i++){
        int cnt0=0, cnt1=0;
        for(int j=0; j<n; j++){
            cnt1+=checkbit(i, arr[j]);
        }
        cnt0 = n-cnt1;
        if(cnt0>cnt1){
            x = setbit(i,x);
        }
    }
    long long ans = 0; 
    for(int i=0; i<n; i++){
        ans+=x^arr[i];
    }
    cout<<ans;

}