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

int n;

void init() {
}

void input() {
	cin >> n;
}

void solve() {
	if(n%2 == 0){
		cout << -1 << endl;
		return;
	}
	VI res;
	REP(i, n){
		if(i%2 == 0){
			res.PB(i/2);
		}
		else{
			res.PB((n+i)/2);
		}
	}
	REP(a, 2){
		REP(i, SZ(res)){
			cout << res[i];
			if(i == SZ(res)-1) cout << endl;
			else cout << " ";
		}
	}
	REP(i, n){
		cout << i;
		if(i == SZ(res)-1) cout << endl;
		else cout << " ";
	}
}

int main() {
	init();
    input();
    solve();
	return 0;
}






