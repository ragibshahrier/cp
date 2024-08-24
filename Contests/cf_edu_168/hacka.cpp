// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define gp " "
// #define debugc(a) cout<<__LINE__<<gp<<#a<<gp<<'['<<gp;for(auto el:a){cout<<el<<gp;}cout<<']'<<endl;

// int main(){
//     // 2 1 1 1 1
//     vector<int> v={};
//     make_heap(v.begin(), v.end());
//     v.push_back(2);
//     push_heap(v.begin(),v.end());
//     v.push_back(1);
//     push_heap(v.begin(),v.end());
//     v.push_back(1);
//     push_heap(v.begin(),v.end());
//     v.push_back(1);
//     push_heap(v.begin(),v.end());
//     v.push_back(1);
//     push_heap(v.begin(),v.end());
//     v.push_back(2);
//     push_heap(v.begin(),v.end());
//     debugc(v)

// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v{2}; // Initialize with a value
    make_heap(v.begin(), v.end());

    v.push_back(7);
    push_heap(v.begin(), v.end());

    v.push_back(3);
    push_heap(v.begin(), v.end());

    v.push_back(1);
    push_heap(v.begin(), v.end());

    v.push_back(6);
    push_heap(v.begin(), v.end());

    v.push_back(8);
    push_heap(v.begin(), v.end());

    // Print the max heap
    for (const auto& el : v) {
        cout << el << " ";
    }
    cout << endl;

    return 0;
}
