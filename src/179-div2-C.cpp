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

int n, m, k;
LL a[100010];
int l[100010], r[100010], d[100010], x[100010], y[100010];

int xx[100010], yy[100010];

LL all[400040], part[400040];

void add(int A, int B, LL x, int node, int left, int right){
	if(right<=left) return;
    if(A<=left && right<=B){
		all[node] += x;
		return;
	}
	if(!(right<=A) && !(B<=left)) part[node] += x * (min(right,B) - max(left, A));
	else return;
    
	int m = (left+right)/2;
	add(A, B, x, node*2+1, left, m);
	add(A, B, x, node*2+2, m, right);
    
    return;
}

LL sum(int A, int B, int node, int left, int right){
    LL res = 0;
	if(right<=left) return res;
	if(A<=left && right<=B){
		res += part[node];
		res += all[node] * (right-left);
		return res;
	}
	if(!(right<=A) && !(B<=left)) res += all[node] *(min(right,B) - max(left, A));
	else return res;
    
	int m = (left+right)/2;
	res += sum(A, B, node*2+1, left, m);
	res += sum(A, B, node*2+2, m, right);
    
    return res;
}

void init() {
    REP(i, 100010){
        xx[i] = 0;
        yy[i] = 0;
    }
}

void input() {
    cin >> n >> m >> k;
    REP(i, n) cin >> a[i];
    REP(i, m) cin >> l[i] >> r[i] >> d[i];
    REP(i, m){
        l[i]--;
        r[i]--;
    }
    REP(i, k) cin >> x[i] >> y[i];
    REP(i, k){
        x[i]--;
        y[i]--;
    }
}

void solve() {
	REP(i, 400040) all[i] = 0;
	REP(i, 400040) part[i] = 0;
    REP(i, n) add(i, i+1, a[i], 0, 0, n);    
    
    REP(i, k){
        xx[x[i]]++;
        yy[y[i]]++;
    }    
    LL imos = 0;
    REP(i, m){
        imos += xx[i];
        LL dd = d[i] * imos;
        add(l[i], r[i]+1, dd, 0, 0, n);
        imos -= yy[i];
    }
    REP(i, n) cout << sum(i, i+1, 0, 0, n) << " ";
    cout << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






