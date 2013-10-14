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

int n, l, r, ql, qr;
int w[100010];

void init() {
}

void input() {
	cin >> n >> l >> r >> ql >> qr;
	REP(i, n) cin >> w[i];
}

void solve() {
	
	LL res = (1LL<<60);
	LL L = 0, R = 0;
	REP(i, n) R += w[i] * r	;
	for(int i = 0; i <= n; i++){
		if(i != 0) L += w[i-1] * l, R -= w[i-1] * r;
		LL tmp = L + R;
		int lc = i;
		int rc = n-i;
		if(lc > rc) tmp += ql*(lc-rc-1);
		if(lc < rc) tmp += qr*(rc-lc-1);
		chmin(res, tmp);
	}
	cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






