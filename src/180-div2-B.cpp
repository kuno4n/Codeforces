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

LL t, sx, sy, ex, ey;

void init() {
}

void input() {
    cin >> t >> sx >> sy >> ex >> ey;
}

void solve() {
    LL res = 0;
    REP(i, t){
        if(sx == ex && sy == ey){
            cout << res << endl;
            return;
        }
        
        res++;
        char c;
        cin >> c;
        if(c == 'E' && sx < ex) sx++;
        if(c == 'S' && sy > ey) sy--;;
        if(c == 'W' && sx > ex) sx--;
        if(c == 'N' && sy < ey) sy++;
    }
    if(sx == ex && sy == ey){
        cout << res << endl;
        return;
    }
    
    cout << -1 << endl;
    return;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






