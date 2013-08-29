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


int dp[1000][11][11]; //dp[i][j][k] : i”Ô–Ú‚Éj‚ðŽg‚Á‚ÄA·‚ªk‚Å‚ ‚é‚Æ‚«‚ÌAi-1”Ô–Ú‚Ì”Ô†
bool use[11];
int m;

void init() {
}

void input() {
	string s; cin >> s;
	REP(i, SZ(s)) use[i+1] = (s[i] == '1');
	cin >> m;
}

void solve() {
	MSET(dp, -1);
	for(int i = 1; i <= 10; i++) if(use[i]) dp[0][i][i] = 0;
	
	for(int i = 0; i < m-1; i++) for(int j = 1; j <= 10; j++) for(int k = 1; k <= 9; k++){
		if(dp[i][j][k] == -1) continue;
		for(int nxt = 1; nxt <= 10; nxt++) if(use[nxt] && j != nxt && k < nxt) dp[i+1][nxt][nxt-k] = j;
	}
	
	VI res;
	int prvj = 0, prvk = 0;
	for(int j = 1; j <= 10; j++) for(int k = 1; k <= 10; k++) if(dp[m-1][j][k] >= 0) prvj = j, prvk = k;
	if(prvj == 0){
		cout << "NO" << endl;
		return;
	}
	
	cout << "YES" << endl;
	for(int i = m-1; prvj != 0; i--){
		res.PB(prvj);
		int tmpj, tmpk;
		tmpj = dp[i][prvj][prvk], tmpk = prvj-prvk;
		prvj = tmpj, prvk = tmpk;
	}
	reverse(ALL(res));
	REP(i, m) cout << res[i] << " ";
	cout << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






