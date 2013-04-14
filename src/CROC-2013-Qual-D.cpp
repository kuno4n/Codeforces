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

int n, k;
int res[25][10010];

void init() {
}

void input() {
	cin >> n >> k;
}

void solve() {
	REP(i, k){
		int mask = (1<<i);
		REP(j, n){
			if(j <= mask) res[i][j] = 0;
			else if(j < (mask<<1)) res[i][j] = j - mask;
			else res[i][j] = mask;
			res[i][j] = n - res[i][j];
		}
	}
	REP(i, k){
		reverse(res[i], res[i]+n);
		REP(j, n){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	
}

int main() {
	init();
    input();
    solve();
	return 0;
}
