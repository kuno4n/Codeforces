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

int k;
LL x;
int n, m;

void init() {
}

void input() {
	cin >> k >> x >> n >> m;
}

void solve() {
	LL a = 0;
	LL b = 0;
	LL ab = 0;
	LL bb = 0;
	LL ba = 0;
	
	LL a_2 = 1;
	LL a_1 = 0;
	LL b_2 = 0;
	LL b_1 = 1;
	LL ab_2 = 0;
	LL ab_1 = 0;
	LL bb_2 = 0;
	LL bb_1 = 0;
	LL ba_2 = 0;
	LL ba_1 = 0;
	for(int i = 3; i <= k; i++){
		a = a_2 + a_1;
		b = b_2 + b_1;
		ab = ab_2 + ab_1;
		bb = bb_2 + bb_1;
		ba = ba_2 + ba_1;
		if(i == 3) ab++;
		else if(i&1){
			bb++;
		}
		else{
			ba++;
		}
		a_2 = a_1;
		a_1 = a;
		b_2 = b_1;
		b_1 = b;
		ab_2 = ab_1;
		ab_1 = ab;
		bb_2 = bb_1;
		bb_1 = bb;
		ba_2 = ba_1;
		ba_1 = ba;
	}
	
	for(int i = 0; i <= n; i += 2){
		for(int j = 0; j <= m; j += 2){
			REP(i_first, 2) REP(i_end, 2) REP(j_first, 2) REP(j_end, 2){
				if(i + i_first + i_end > n) continue;
				if(j + j_first + j_end > m) continue;
				LL res = 0;
				res += (i/2) * a;
				res += (j/2) * b;
				res += (i_end & j_first) * ab;
				res += (j_end & j_first) * bb;
				res += (j_end & i_first) * ba;
				if(res != x) continue;
				
				string sa = "";
				string sb = "";
				if(i_first) sa += "C";
				if(j_first) sb += "C";
				REP(ii, i/2) sa += "AC";
				REP(jj, j/2) sb += "AC";
				for(int ii = SZ(sa); ii < n; ii++) sa += "Z";
				for(int jj = SZ(sb); jj < m; jj++) sb += "Z";
				if(i_end) sa[n-1] = 'A';
				if(j_end) sb[m-1] = 'A';
				cout << sa << endl << sb << endl;;
				return;
			}
		}
	}
	
	cout << "Happy new year!" << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






