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

int k, d[110];

void init() {
}

void input() {
    cin >> k;
    REP(i, k) cin >> d[i];
}

void solve() {
    int cnt0 = 0, cnt1 = 0, cnt10 = 0, cnt11 = 0, cnt100 = 0;
    int _1 = 0, _10 = 0, _11 = 0;
    REP(i, k){
        if(d[i] == 0) cnt0++;
        else if(d[i] >= 1 && d[i] <= 9) {cnt1++; _1 = d[i];}
        else if(d[i] == 100) cnt100++;
        else if(d[i] % 10 == 0) {cnt10++; _10 = d[i];}
        else {cnt11++; _11 = d[i];}
    }
    int res = 0;
    VI vi;
    if(cnt0 > 0) {res++; vi.push_back(0);}
    if(cnt100 > 0) {res++; vi.push_back(100);}
    if(cnt1 > 0){
        res++;
        vi.push_back(_1);
        if(cnt10 > 0) {res++; vi.push_back(_10);}
    }
    else if(cnt10 > 0){
        res++;
        vi.push_back(_10);
        if(cnt1 > 0) {res++; vi.push_back(_1);}
    }
    else if(cnt11 > 0) {res++; vi.push_back(_11);}
    cout << res << endl;
    REP(i, SZ(vi)) cout << vi[i] << " ";
    cout << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






