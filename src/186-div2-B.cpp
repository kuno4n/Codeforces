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

int table[100010];
string s;
int m;

void init() {
    MSET(table, 0);
}

void input() {
    cin >> s;
    for(int i=1; i<SZ(s); i++){
        table[i] = table[i-1];
        if(s[i] == s[i-1]) table[i]++;
    }
    cin >> m;
    REP(i, m){
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << table[r]-table[l] << endl;
    }
}

void solve() {
}

int main() {
	init();
    input();
    solve();
	return 0;
}






