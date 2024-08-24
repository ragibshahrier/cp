#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,k;
        cin>>x>>y>>k;
        if(k%2==0){
            cout<<"0"<<" "<<"0"<<endl;
            cout<<x*k<<" "<<y*k<<endl;
            for(int i=1;i<=(k-2)/2;i++){
                if(i==x || i+x==0){
                    k=k+2;
                    continue;
                }
                else{
                    cout<<i<<" "<<i<<endl;
                    cout<<-i<<" "<<-i<<endl;
                }

            }
            
        }
        else{
            cout<<x*k<<" "<<y*k<<endl;
            for(int i=1;i<=(k-1)/2;i++){
                if(i==x || i+x==0){
                    k+=2;
                    continue;
                }
                else{
                    cout<<i<<" "<<i<<endl;
                    cout<<-i<<" "<<-i<<endl;
                }
        }
    }
}
}