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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())

int table[300][300];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int t;

void init() {
}

void input() {
	MSET(table, 0);
	cin >> table[150][150] >> t;
}

void solve() {
	while(1){
		bool cg = false;
		REP(i, 300) REP(j, 300) if(table[i][j] >= 4){
			cg = true;
			int tmp = table[i][j]/4;
			table[i][j] %= 4;
			REP(k, 4) table[i+dx[k]][j+dy[k]] += tmp;
		}
		if(!cg) break;
	}
	REP(i, t){
		LL x, y;
		cin >> x >> y;
		x += 150, y += 150;
		if(x < 0 || x >= 300 || y < 0 || y >= 300){
			cout << 0 << endl;
		}
		else{
			cout << table[x][y] << endl;
		}
	}
}

int main() {
	init();
    input();
    solve();
	return 0;
}






