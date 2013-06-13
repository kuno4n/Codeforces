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

bool table[1010];
int mae[1010], ato[1010];
int n, x;

void init() {
}

void input() {
	REP(i, 1010) table[i] = false;
	table[0] = true;
	cin >> n >> x;
	REP(i, 1010) mae[i] = ato[i] = 0;
	REP(i, n) cin >> mae[i+1];
	FOR(i, 1, n+1) ato[mae[i]] = i;
}

void solve() {
	VI re;
	int mae_me;
	FOR(i, 1, n+1) if(mae[i] == 0) {
		bool me = false;
		int cnt = 0;
		int ptr = i;
		while(1){
			if(ptr == x){
				me = true;
				mae_me = cnt;
				break;
			}
			cnt++;
			if(ato[ptr] == 0) break;
			ptr = ato[ptr];
		}
		if(!me) re.PB(cnt);
	}
	REP(i, SZ(re)){
		int tmp[1010]; REP(j, 1010) tmp[j] = table[j];
		REP(j, 1010) if(table[j]) tmp[j+re[i]] = true;
		REP(j, 1010) table[j] = tmp[j];
	}
	
	REP(i, 1010) if(table[i]) cout << i+mae_me+1 << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






