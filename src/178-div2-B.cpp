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

int n, t[101], w[101];

void init() {
}

void input() {
    cin >> n;
    REP(i, n) cin >> t[i] >> w[i];
}

VI v1, v2;

int C(int i1, int i2){
    int tt = i1 + i2*2;
    int tt2 = 0;
    FOR(i, i1, SZ(v1)) tt2 += v1[i];
    FOR(i, i2, SZ(v2)) tt2 += v2[i];
    if(tt >= tt2) return tt;
    return -1;
}

void solve() {
    v1.clear();
    v2.clear();
    REP(i, n){
        if(t[i] == 1) v1.push_back(w[i]);
        else v2.push_back(w[i]);
    }
    int res = 1000000;
    sort(ALL(v1), greater<int>());
    sort(ALL(v2), greater<int>());
    for(int i = 0; i <= SZ(v1); i++){
        for(int j = 0; j <= SZ(v2); j++){
            int tt = C(i, j);
            if(tt != -1) res = min(res, tt);
        }
    }
    cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}
