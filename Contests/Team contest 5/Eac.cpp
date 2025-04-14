1
#include <bits/stdc++.h>
2
#include
<ext/pb_ds/assoc_container.hpp>
3
using namespace_gnu_pbds;
4
using namespace std;
5 #define fast ios_base::sync_with_stdio (0); cin.tie (0); cout.tie(0);
int tree [4*N];
void init(int node, int l.int r) {
if(l==r) { tree [node]=0; return;}
6
7
8
#define N 200005
9
10
struct segtree{
11
12
13
14
15
16
17
}
18
19
20
21
init (node * 2, 1, (1+r)/2);
init (node *2+1, (1+r)/2 +1,r);
tree [node]=tree [node *2]+tree [node *2+11;
void update(int node, int 1. int r,int p,int x) {
if (p<l || p>r) return;
if(l==r) { tree [node]=x; return;}
update (node*2.1, (1+r)/2.p.x);
update (node *2+1, (1+r)/2 +1, r.p.x);
tree [node]=tree [node *2]+tree [node *2+11;
int query (int node, int l.int r,int a.int b) {
23
22
1 2 2 2 2 2 2 2 2 2 2 23
24
}
25
26
27
28
29
}
30
}sg;
31
if(r<a || l>b) return 0;
if (l>=a && r<=b) return tree [node];
return query(node *2, 1, (1+r)/2, a, b) +query (node *2+1, (1+r)/2 +1,r,a,b);
int n,m,k;
33 int a[N] b[N], chk [N], idx [N],c[N];
34
35 void solve() {
36
37
cin >> n >> m >> k;
38
39
40
41
42
}
43
44
45
46
47
48
49
50
51
}
52
53
54
55
}
56
57
58
59
for (int i=1;i<=n;i++) {
chk [i]=0; c[i]=0;
sg.init(1,1,n);
set<int> idxx;
multiset<int> mlen;
for (int i=1;i<=n;i++) {
cin >> a[i];
idx [a[i]]=i;
for (int i=1;i<=m; i++) {
cin >> b[i];
chk [b[i]]=1;
for (int i=1;i<=k; i++) {
int x;
cin >> x;
mlen. insert(x);
60
}
61
62
63
64
65
66
67
{
68
idxx.insert(0);
idxx.insert(n+1);
int flag=0;
for (int i=1;i<m; i++)
if(idx[b[i]]> idx [b[i+1]]) flag=1;
69
}
70
71
72
73
// int flg=0;
74
75
// int i=0.jj=0;
76
// while (ii<=n && jj<=m) {
77
[/
if(a[ii]==b[jj]) ii++, jj++;
78
[/
else ii++;
79
// }
80
// if(jj<=m) flg=1;
81
82
if(flag) {
83
84
cout << "NO\n";
return;
85
}
86
87
88
if (chk [i]) {
89
90
91
for (int i=n;i>0; i--) {
idxx.insert(idx[i]);
// c[idx[i]]=i;
// cout << i << " -> " << idx[i] << endl;
92
}
93
else{
94
auto it-idxx.upper_bound (idx[i]);
95
int lo,hi;
96
hi=(*it);
97
98
99
100
101
it--;
lo=(*it);
int len-hi-lo-1-sg.query(1.1.n, lo+1, hi-1); sg.update(1,1, n.idx[i], 1);
102
103
// cout << hi << " " << lo << endl;
104
105
106
107
auto itr=mlen.upper_bound (len);
// cout << (*itr) << endl;
if (itr==mlen.begin()) {
108
// cout << (*itr) << endl;
109
110
111
}
112
113
cout << "NO\n";
return;
itr--;
// cout << (*itr) << endl;
114
mlen.erase(itr);
115
}
116
}
117
118
cout << "YES\n";
119
120
121
122
}
123
124
int main()
125
{
126
fast;
127
int t=1;
128
cin>>t;
129
while(t--)
130
{
131
solve();
132
}
133
}