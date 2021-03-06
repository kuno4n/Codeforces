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

    int tab[1<<18];
    
    // a番目の値をxに変える。　呼び出すときは update(a, x, 0, 0, n);
    void update(int a, int x, int node, int left, int right, int depth){
        if(a < left || right <= a) return;
        if(depth == n){ //if(left+1 == right) {
            tab[node] = x;
            return;
        }
        int m = (left+right)/2;
        int n1 = node*2 + 1;
        int n2 = node*2 + 2;
        update(a, x, n1, left, m, depth+1);
        update(a, x, n2, m, right, depth+1);
        tab[node] = ((n-depth)&1) ? (tab[n1]|tab[n2]) : (tab[n1]^tab[n2]);
    }


void init() {
}

void input() {
    cin >> n >> m;
    MSET(tab, 0);
    REP(i, (1<<n)){
		int x; cin >> x;
		update(i, x, 0, 0, (1<<n), 0);
	}
}

void solve() {
	REP(_, m){
		int a, x;
		cin >> a >> x; a--;
		update(a, x, 0, 0, (1<<n), 0);
		cout << tab[0] << endl;
	}
}

int main() {
	init();
    input();
    solve();
	return 0;
}






