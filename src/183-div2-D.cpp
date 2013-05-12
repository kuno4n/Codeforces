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

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

LL n, m, x, y, a, b;

void init() {
}

void input() {
	cin >> n >> m >> x >> y >> a >> b;
}

void solve() {
	LL g = gcd(a, b);
	a /= g; b /= g;
	LL hi = min((n/a), (m/b));
	LL aa = a * hi, bb = b * hi;
	LL x2 = x + aa/2, y2 = y + bb/2;
	LL x1 = x2 - aa, y1 = y2 - bb;
	if(x1 < 0){
		x2 += -x1;
		x1 = 0;
	}
	if(y1 < 0){
		y2 += -y1;
		y1 = 0;
	}
	if(x2 > n){
		x1 -= x2-n;
		x2 = n;
	}
	if(y2 > m){
		y1 -= y2-m;
		y2 = m;
	}
	cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






