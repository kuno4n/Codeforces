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

VI G[100010];
int dist[3][100010];

void init() {
}

void input() {
}

void dfs(int node, int pa, int id, int d){
	dist[id][node] = d;
	REP(i, SZ(G[node])) if(G[node][i] != pa) dfs(G[node][i], node, id, d+1);
}

void solve() {
	int n, m, d;
	bool target[100010]; 
	MSET(target, false);
	
	cin >> n >> m >> d;
	REP(_, m){
		int p;
		cin >> p; p--;
		target[p] = true;
	}
	REP(_, n-1){
		int a, b;
		cin >> a >> b; a--; b--;
		G[a].PB(b);
		G[b].PB(a);
	}
	
	dfs(0, -1, 0, 0);
	int x, y, z;
	REP(i, n) if(target[i]) {x = i; break;}
	y = x;
	REP(i, n) if(target[i] && dist[0][i] > dist[0][y]) y = i;
	dfs(y, -1, 1, 0);
	z = y;
	REP(i, n) if(target[i] && dist[1][i] > dist[1][z]) z = i;
	dfs(z, -1, 2, 0);
	
	int res = 0;
	REP(i, n) if(dist[1][i] <= d && dist[2][i] <= d) res++;
	cout << res << endl;
	
}

int main() {
	init();
    input();
    solve();
	return 0;
}






