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

LL INF = (1LL << 55);
LL table[310][310]; // l, r -> mincost
LL dp[310][310]; // pos, fixed -> mincost
int n, m, k;

void init() {
}

void input() {
    REP(i, 310) REP(j, 310) table[i][j] = INF;
    cin >> n >> m >> k;
    REP(i, m){
        int l, r;
        LL c;
        cin >> l >> r >> c;
        table[l][r] = min(table[l][r], c);
    }
    for(int len = n; len >= 2; len--){
        for(int l = 1; l+len-1 <= n; l++){
            int r = l+len-1;
            table[l][r-1] = min(table[l][r-1], table[l][r]);
            table[l+1][r] = min(table[l+1][r], table[l][r]);
        }
    }
    REP(i, n+1) REP(j, n+1) dp[i][j] = INF;
}

void solve() {
    dp[0][0] = 0;
    for(int l = 1; l <= n; l++){
        REP(fixed, n+1){
            dp[l][fixed] = min(dp[l][fixed], dp[l-1][fixed]);
            if(dp[l-1][fixed] == INF) continue;
            for(int r = l; r <= n; r++){
                if(table[l][r] == INF) break;
                dp[r][fixed+(r-l+1)] = min(dp[r][fixed+(r-l+1)], dp[l-1][fixed]+table[l][r]);
            }
        }
    }
    LL res = INF;
    for(int i = k; i <= n; i++) res = min(res, dp[n][i]);
    cout << (res == INF ? -1 : res) << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






