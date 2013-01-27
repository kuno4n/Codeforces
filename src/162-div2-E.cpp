
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
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
#define FIT(it,v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl

int n, q;
long long v[100001], sameFactor, diffFactor;
int col[100001];

long long bestNow[2];
long long INF = 1000000000000001LL;
LL dp[100001];


long long solve(){
    REP(i, n) dp[i] = -INF;
    bestNow[0] = bestNow[1] = -INF;
    REP(i, n){
        LL mx = max(dp[col[i]], v[i]*diffFactor);
        mx = max(mx, dp[col[i]] + v[i]*sameFactor);
        mx = max(mx, (bestNow[0]==dp[col[i]] ? bestNow[1] : bestNow[0]) + v[i]*diffFactor);
        if(bestNow[0] == dp[col[i]]) bestNow[0] = mx;
        else if(bestNow[1] == dp[col[i]]) bestNow[1] = mx;
        else if(bestNow[1] < mx) bestNow[1] = mx;
        if(bestNow[0] < bestNow[1]) swap(bestNow[0], bestNow[1]);
        dp[col[i]] = mx;
    }
    LL res = 0;
    REP(i, n) res = max(res, dp[i]);
    return res;
}

int main()
{
	cin >> n >> q;
	REP(i, n) cin >> v[i];
	REP(i, n) {cin >> col[i]; col[i]--;}
	REP(i, q){
        cin >> sameFactor >> diffFactor;
        cout << solve() << endl;
    }
	return 0;
}


