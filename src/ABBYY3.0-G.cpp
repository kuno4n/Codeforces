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

typedef unsigned long long ull;

const ull B = 100000007;

string s;
int n;
string p[10];
int l[10], r[10];

void init() {
}

void input() {
	cin >> s >> n;
	REP(i, n) cin >> p[i] >> l[i] >> r[i];
}

void solve() {
	int res = 0;
	for(int len = 1; len <= SZ(s); len++){
		ull t = 1; REP(i, len) t *= B;
		map<ull, int> m[10];
		REP(i, n){
			if(len > SZ(p[i])) continue;
			ull h = 0;
			REP(j, len) h = h * B + p[i][j];
			for(int j = 0; j+len <= SZ(p[i]); j++){
				m[i][h]++;
				if(j+len < SZ(p[i])) h = h * B + p[i][j+len] - p[i][j] * t;
			}
		}
		ull h = 0;
		REP(i, len) h = h * B + s[i];
		map<ull, int> checked;
		for(int i = 0; i+len <= SZ(s); i++){
			if(checked[h] == 0){
				checked[h]++;
				bool pass = true;
				REP(j, n){
					if(m[j][h] < l[j] || r[j] < m[j][h]){
						pass = false;
						break;
					}
				}
				if(pass) res++;
			}
			if(i+len < SZ(s)) h = h * B + s[i+len] - s[i]*t;
		}
		
	}
	cout << res << endl;
	
	
	
//	REP(i, n){
//		for(int start = 0; start < SZ(p[i]); start++){
//			ull roll = 0;
//			for(int ptr = start; ptr < SZ(p[i]); ptr++){
//				int len = ptr - start + 1;
//				roll = roll * B + p[i][ptr];
//				m[i][len][roll]++;
//			}
//		}
//	}
//	int res = 0;
//	for(int start = 0; start < SZ(s); start++){
//		ull roll = 0;
//		for(int ptr = start; ptr < SZ(s); ptr++){
//			int len = ptr - start + 1;
//			roll = roll * B + s[ptr];
//			if(checked[len][roll] > 0) continue;
//			checked[len][roll]++;
//			bool pass = true;
//			REP(i, n){
//				if(m[i][len][roll] < l[i] || m[i][len][roll] > r[i]){
//					pass = false;
//					break;
//				}
//			}
//			if(pass){
////				OUT(start); OUT(ptr);
//				res++;
//			}
//		}
//	}
//	cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






