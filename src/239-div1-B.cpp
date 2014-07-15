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

const int MOD = 1000000007;
LL dp[1010];
int n;
int p[1010];

void add(LL &a, LL b){
    a = (a + b) % MOD;
}

void init() {
}

void input() {
    cin >> n;
    REP(i, n) {
        cin >> p[i];
        p[i]--;
    }
}

void solve() {
    MSET(dp, 0);
    REP(i, n){
        dp[i] = 1;
        for(int j = p[i]; j < i; j++){
            add(dp[i], dp[j]);
            add(dp[i], 1);
        }
    }
    LL res = 0;
    REP(i, n){
        add(res, dp[i]);
        add(res, 1);
    }
    cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}





