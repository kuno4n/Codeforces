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

LL x, y, m;

void init() {
}

void input() {
	cin >> x >> y >> m;
	if(x > y) swap(x, y);
}

void solve() {
	if(y >= m){
		cout << 0 << endl;
		return;
	}
	if(y < m && y <= 0){
		cout << -1 << endl;
		return;
	}
	
	LL res = 0;
	if(x < 0){
		LL tmp = (-x)/y;
		x += y*tmp; res += tmp;
		x += y; res++;
	}
	if(x >= m){
		cout << res << endl;
		return;
	}
	if(x > y) swap(x, y);
	LL tmp = (y-x)/y;
	x += y*tmp; res += tmp;

	
	while(m-x > y){
		res++;
		x += y;
		swap(x, y);
	}
	cout << res+1 << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






