#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<set>
#include<utility>
#include <stack>
#include<algorithm>
 
using namespace std;

void solve(){
string a, b;
cin >> a >> b;
int ans = a.size();
map<char,int> aj, bj;
for(int i = 0; i < a.size(); i++){
    aj[a[i]]++;
}
for (int i = 0; i < b.size(); i++)
{
    bj[b[i]]++;
}
set<char> che;
che.insert(b.begin(), b.end());
for (auto it = che.begin(); it != che.end(); it++)
{
    if(aj[*it] == 0 || (aj[*it] < bj[*it])){
        ans += (bj[*it] - aj[*it]);
    }else{
        continue;
    }
}
if (ans < b.size())
{
    ans = b.size();
}
cout << ans << endl;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t; cin >> t;
while(t--)solve();
return 0;
}