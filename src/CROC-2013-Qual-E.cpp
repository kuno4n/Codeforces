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

int n;
vector < pair<int , string> > tree[100010];
string target;
ull t, target_hash;
ull hash_table[300010];
int res;


void dfs(int node, int strsize, ull h){
	REP(i, SZ(tree[node])){
		ull _h = h;
		int _strsize = strsize;
		pair<int, string> _node = tree[node][i];
		REP(j, SZ(_node.second)){
			_h = _h * B + _node.second[j];
			hash_table[++_strsize] = _h;
			if(_strsize >= SZ(target) && _h - hash_table[_strsize - SZ(target)] * t == target_hash) res++;
		}
		dfs(_node.first, _strsize, _h);
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
	t = 1;
	REP(i, SZ(target)) t *= B;
	target_hash = 0;
	REP(i, SZ(target)) target_hash = target_hash * B + target[i];
	res = 0;
}

void solve() {
	hash_table[0] = 0;
	ull h = 0;
	dfs(0, 0, h);
	cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}
