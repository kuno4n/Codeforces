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


LL seq[300010];
LL sum[300010];
map<LL, int> le;
int n;
LL INF = (1LL<<58);

LL ans;

void init() {
}

void input() {
	cin >> n;
	REP(i, n) cin >> seq[i];
}

void solve() {
	MSET(sum, 0);
	LL res = -INF; int l = -1; int r = -1;
	
	REP(i, n){
		if(i > 0) sum[i] = sum[i-1];
		if(seq[i] >= 0) sum[i] += seq[i];
		
		
		if(le.count(seq[i]) != 0){
			LL su = sum[i];
			if(seq[i] < 0) su += seq[i]*2;
			if(le[seq[i]] > 0) su -= sum[le[seq[i]]-1];
			if(su > res){
				res = su;
				l = le[seq[i]];
				r = i;
			}
		}
		else{
			le[seq[i]] = i;
		}
		
	}
	
	cout << res << " ";
	
	VI ans;
	REP(i, l) ans.push_back(i+1);
	FOR(i, l+1, r) if(seq[i] < 0) ans.push_back(i+1);
	FOR(i, r+1, n) ans.push_back(i+1);
	cout << SZ(ans) << endl;
	REP(i, SZ(ans)){
		cout << ans[i];
		if(i != SZ(ans)-1) cout << " ";
	}
	cout << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






