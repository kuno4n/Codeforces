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
vector < pair<int , string> > tree[100010];
string target;
int res;

int next[300010][30];
int fail[300010];

void dfs(int node, int state){
	REP(i, SZ(tree[node])){
		int st = state;
		REP(j, SZ(tree[node][i].second)){
			st = next[st][tree[node][i].second[j] - 'a'];
			if(st == SZ(target)) res++;
		}
		dfs(tree[node][i].first, st);
	}
}

void init() {
}

void input() {
	cin >> n;
	REP(i, 100010) tree[i].clear();
	int node;
	string s;
	REP(i, n-1){
		cin >> node >> s;
		tree[node-1].PB(make_pair(i+1, s));
	}
	cin >> target;
	res = 0;

	for(int i = 1; i <= SZ(target); i++){
		if(i == 1) fail[i] = 0;
		else if(target[fail[i-1]] == target[i-1]) fail[i] = fail[i-1] + 1;
		else fail[i] = 0;
	}

	for(int i = 0; i <= SZ(target); i++){
		REP(j, 26){
			if(i != SZ(target) && j + 'a' == target[i]) 
				next[i][j] = i + 1;
			else if(i == 0)
				next[i][j] = 0;
			else next[i][j] = next[fail[i]][j];
		}
	}
}

void solve() {
	dfs(0, 0);
	cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}
