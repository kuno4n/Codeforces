#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <fstream>
//#include "cout.h"

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())

int n;
int a[100010], b[100010], l[100010];
double prod[100010];
VI g[100010];
int cnt[100010];

void init() {
}

void input() {
	cin >> n;
	REP(i, n-1){
		cin >> a[i] >> b[i] >> l[i];
		a[i]--;
		b[i]--;
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}
}

int make(int pa, int k){
	cnt[k]++;
	REP(i, SZ(g[k])) if(g[k][i] != pa){
		make(k, g[k][i]);
		cnt[k] += cnt[g[k][i]];
	}
	return cnt[k];
}

void solve() {
	MSET(cnt, 0);
	make(-1, 0);
	REP(i, n-1){
		int x = min(cnt[a[i]], cnt[b[i]]);
		int y = n - x;
		prod[i]  = 1.0 * x * (x - 1) / 2 * y;
		prod[i] += 1.0 * y * (y - 1) / 2 * x;
		prod[i] /= 1.0 * n * (n-1) * (n-2) / 3 / 2;
	}

	double res = 0.0;
	REP(i, n-1) res += prod[i] * l[i] * 2;

	int q;
	cin >> q;
	REP(_, q){
		int r, w;
		cin >> r >> w;
		r--;
		res -= (l[r] - w) * prod[r] * 2;
		l[r] = w;
		printf("%.10lf\n", res);
	}
}

int main() {
	init();
    input();
    solve();
	return 0;
}






