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

int n, k;
LL IP[100010];
set <LL> s;

LL mask1 = 255;

void init() {
}

void input() {
    cin >> n >> k;
    REP(i, n){
        LL a, b, c, d;
        char c1, c2, c3;
        cin >> a >> c1 >> b >> c2 >> c >> c3 >> d;
        IP[i] = (a<<24) + (b<<16) + (c<<8) + d;
    }
}

void solve() {
    LL mask = 0;
    for(int i = 31; i >= 0; i--){
        mask += ((LL)1<<i);
        s.clear();
        REP(j, n) s.insert(IP[j] & mask);
        if(SZ(s) == k){
            cout
            << ((mask>>24) & mask1)
            << '.'
            << ((mask>>16) & mask1)
            << '.'
            << ((mask>>8) & mask1)
            << '.'
            << (mask & mask1)
            << endl;
            return;
        }
        if(SZ(s) > k){
            cout << -1 << endl;
            return;
        }
    }
    
    
    cout << -1 << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






