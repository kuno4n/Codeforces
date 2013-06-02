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

LL a[2000010];
int b, cnt;

void init() {
    MSET(a, 0);
}

void input() {
    cin >> b;
    REP(i, b) cin >> a[i];
    sort(a, a+b);
    reverse(a, a+b);
//    int bb = b;
//    cnt = 0;
//    while(bb){
//        cnt++;
//        bb /= 4;
//    }
}

void solve() {
    LL res = 0;
    while(b){
        LL tmp = 0;
        REP(i, b) tmp += a[i];
        res += tmp;
        b /= 4;
    }
    cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






