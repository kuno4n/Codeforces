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

int n, a[101], m, x[101], y[101];

void init() {
}

void input() {
    cin >> n;
    REP(i, n) cin >> a[i];
    cin >> m;
    REP(i, m) cin >> x[i] >> y[i];
    REP(i, m) {
        x[i]--;
    }
}

void solve() {
    REP(i, m){
        if(x[i] > 0){
            a[x[i]-1] += y[i]-1;
        }
        if(x[i] < n-1){
            a[x[i]+1] += a[x[i]] - y[i];
        }
        a[x[i]] = 0;
    }
    REP(i, n) cout << a[i] << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}
