//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
// using ordered_set =
//     tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
// sim > struct rge { c b, e; };
// sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
// sim > auto dud(c* x) -> decltype(cerr << *x, 0);
// sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=807;
const int inf=1e9;

int n;

int tab[nax];

int dp[nax][nax];

int pref[nax];

void mini(int &a, int b)
{
	a=min(a, b);
}

void maxi(int &a, int b)
{
	a=max(a, b);
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=0; i<=n+1; i++)
		for (int j=0; j<=n+1; j++)
			dp[i][j]=inf;
	for (int p=1; p<=n; p++)
	{
		for (int l=p-1; l>=1; l-=2)
		{
			for (int i=l+1; i<p; i+=2)
				mini(dp[l][p], max(dp[l][i], dp[i+1][p]-(i-l+1)/2));
			if ((tab[l]&1)!=(l&1) || tab[l]>l)
				continue;
			if (l+1==p)
			{
				mini(dp[l][p], (l-tab[l])/2);
				continue;
			}
			int x=(l-tab[l])/2;
			if (dp[l+1][p-1]<=x)
				mini(dp[l][p], x);
		}
	}
	//~ for (int i=1; i<=n; i++)
		//~ for (int j=i; j<=n; j++)
			//~ if (dp[i][j]<inf)
				//~ debug() << i << " " << j << " " << dp[i][j];
	for (int i=0; i<=n+1; i++)
		pref[i]=-inf;
	pref[0]=0;
	for (int i=0; i<n; i++)
	{
		maxi(pref[i+1], pref[i]);
		for (int j=i+1; j<=n; j++)
		{
			if (dp[i+1][j]<=pref[i])
				maxi(pref[j], pref[i]+(j-i)/2);
		}
	}
	printf("%d\n", pref[n]);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
