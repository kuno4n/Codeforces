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

int n, k, a[1000010];
int imos[1000010];

void init() {
}

void input() {
	cin >> n >> k;
	REP(i, n) cin >> a[i];
}

void solve() {
	sort(a, a+n);
	if(a[0] <= k){
		cout << a[0] << endl;
		return;
	}
	
	MSET(imos, 0);
	REP(i, n) imos[a[i]-k]++, imos[a[i]+1]--;
	for(int i = 1; i < 1000010; i++) imos[i] += imos[i-1];
	
	int res = 0;
	for(int i = k; i <= a[0]; i++){
		int tmp = 0;
		for(int j = i; j < 1000010; j += i) tmp += imos[j];
		if(tmp == n) res = i;
	}
	cout << res << endl;
	
	
}

int main() {
	init();
    input();
    solve();
	return 0;
}






