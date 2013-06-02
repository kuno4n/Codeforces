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

int INF = (1<<29);

string s;

LL str2int(string s){
    LL res = 0;
    REP(i, SZ(s)){
        res *= 10;
        res += s[i]-'0';
    }
    return res;
}

void init() {
}

void input() {
    cin >> s;
}

void solve() {
    int a = 1;
    if(s[0] == '-'){
        a = -1;
        s = s.substr(1);
    }
    LL res = str2int(s) * a;
    res = max(res, str2int(s.substr(0, SZ(s)-1))*a);
    if(SZ(s) > 1) {
        string ss = s.substr(0, SZ(s)-2);
        ss.push_back(s[SZ(s)-1]);
        res = max(res, str2int(ss)*a);
    }
    cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






