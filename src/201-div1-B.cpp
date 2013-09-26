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

string s1, s2, v;
int n1, n2, n3;
int dp[105][105][105];
int next1[105][26], next2[105][26], fail[105][26];

int rec(int a, int b, int c){
	if(dp[a][b][c] != -1) return dp[a][b][c];
	
	int res = 0;
	REP(i, 26){
		int na = next1[a][i];
		int nb = next2[b][i];
		int nc = fail[c][i];
		if(na != -1 && nb != -1 && nc != n3) chmax(res, rec(na, nb, nc) + 1);
	}
	return dp[a][b][c] = res;
}

string rec2(int a, int b, int c){
	if(dp[a][b][c] == 0) return "";
	string res = "";
	REP(i, 26){
		int na = next1[a][i];
		int nb = next2[b][i];
		int nc = fail[c][i];
		if(na != -1 && nb != -1 && nc != n3 && dp[na][nb][nc] == dp[a][b][c] - 1){
			res = string(1, 'A'+i) + rec2(na, nb, nc);
			return res;
		}
	}
	return res;
}

void init() {
}

void input() {
	cin >> s1 >> s2 >> v;
	n1 = SZ(s1), n2 = SZ(s2), n3 = SZ(v);
}

void solve() {
	REP(i, 26) next1[n1][i] = -1, next2[n2][i] = -1;
	for(int i = n1 - 1; i >= 0; i--) REP(c, 26){
		if(s1[i] == 'A'+c) next1[i][c] = i+1;
		else next1[i][c] = next1[i+1][c];
	}
	for(int i = n2 - 1; i >= 0; i--) REP(c, 26){
		if(s2[i] == 'A'+c) next2[i][c] = i+1;
		else next2[i][c] = next2[i+1][c];
	}

	REP(i, n3) REP(j, 26){
		fail[i][j] = 0;
		for(int k = 0; k <= i; k++){
			string s = v.substr(k, i-k) + string(1, 'A'+j);
			if(v.find(s) == 0){
				fail[i][j] = i-k+1;
				break;
			}
		}
	}
	MSET(dp, -1);
	int len = rec(0, 0, 0);
	if(len == 0){
		cout << "0" << endl;
		return;
	}
	
	cout << rec2(0, 0, 0) << endl;
	
}

int main() {
	init();
    input();
    solve();
	return 0;
}






