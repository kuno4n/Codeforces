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

int n, m;
LL E[1010];
pair<LL, int> e[1010];
bool g[1010][1010];
bool removed[1010];

void init() {
}

void input() {
    cin >> n >> m;
    REP(i, n){
        LL a;
        cin >> a;
        e[i] = make_pair(a, i);
        E[i] = a;
    }
    MSET(g, false);
    REP(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a][b] = true;
        g[b][a] = true;
    }
}

void solve() {
    MSET(removed, false);
    sort(e, e+n);
    reverse(e, e+n);
    
    LL res = 0;
    REP(i, n){
        int a = e[i].second;
        REP(j, n) if(!removed[j] && g[a][j]) res += E[j];
        removed[a] = true;
    }
    cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






