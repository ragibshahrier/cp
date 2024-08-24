#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, p, q;
    cin >> n >> p;
    int arr[205];
    for(int i=0; i<p; i++){
        cin >> arr[i];
    }
    cin >> q;
    for(int i=0; i<q; i++){
        cin >> arr[p+i];
    }
    int count=1;
    sort(arr, arr+(p+q));
    for(int i=1; i<p+q; i++){
        if(arr[i] != arr[i-1]) count ++;
    }

    if(count == n) cout << "I become the guy.";
    else cout << "Oh, my keyboard!";
}