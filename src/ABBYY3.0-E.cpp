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

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())

LL MOD = 1000000000;
LL f[200010];
int n, m;
LL a[200010];

void init() {
	f[0] = f[1] = 1;
	FOR(i, 2, 200010) f[i] = (f[i-1] + f[i-2]) % MOD;
}

void input() {
	cin >> n >> m;
	REP(i, 200010) a[i] = 0;
	REP(i, n) cin >> a[i];
}

void solve() {
	REP(i, m){
		int t; cin >> t;
		if(t == 1){
			int x; LL v;
			cin >> x >> v; x--;
			a[x] = v;
		}
		else if(t == 2){
			int l, r;
			cin >> l >> r; l--;
			LL sum = 0;
			for(int i = 0; i+l < r; i++){
				sum = (sum + (f[i]*a[i+l])%MOD) % MOD;
			}
			cout << sum << endl;
		}
	}
}

int main() {
	init();
    input();
    solve();
	return 0;
}






