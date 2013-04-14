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

int n, m, k;
LL a[100010];
int l[100010], r[100010], d[100010], x[100010], y[100010];

int xx[100010], yy[100010];

LL opecnt[100010], IMOS[100010];

void init() {
    REP(i, 100010){
        xx[i] = 0;
        yy[i] = 0;
        opecnt[i] = 0;
        IMOS[i] = 0;
    }
}

void input() {
    cin >> n >> m >> k;
    REP(i, n) cin >> a[i];
    REP(i, m) cin >> l[i] >> r[i] >> d[i];
    REP(i, m){
        l[i]--;
        r[i]--;
    }
    REP(i, k) cin >> x[i] >> y[i];
    REP(i, k){
        x[i]--;
        y[i]--;
    }
}

void solve() {
    
    REP(i, k){
        opecnt[x[i]]++;
        opecnt[y[i]+1]--;
    }
    FOR(i, 1, m) opecnt[i] += opecnt[i-1];
    REP(i, m){
        IMOS[l[i]] += opecnt[i] * d[i];
        IMOS[r[i]+1] -= opecnt[i] * d[i];
    }
    FOR(i, 1, n) IMOS[i] += IMOS[i-1];
    REP(i, n) cout << a[i] + IMOS[i]  << " ";

    
    cout << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






