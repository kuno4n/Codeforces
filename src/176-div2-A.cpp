
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
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
#define FIT(it,v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl

bool sq[4][4];

bool chk1(int x, int y){
	bool c = sq[x][y];
	if(sq[x][y+1] == c && sq[x+1][y+1] == c && sq[x+1][y] == c) return true;
	return false;
}

bool chk2(){
	bool res = false;
	REP(i, 3) REP(j, 3) if(chk1(i, j)) res = true;
	return res;
}


int main() {
    REP(i, 4) REP(j, 4){
		char c;
		cin >> c;
		if(c == '.') sq[i][j] = true;
		else sq[i][j] = false;
	}
	bool can = false;

	if(chk2()) can = true;
	REP(i, 4) REP(j, 4){
		sq[i][j] = !sq[i][j];
		if(chk2()) can = true;
		sq[i][j] = !sq[i][j];
	}

	if(can) cout << "YES";
	else cout << "NO";
	cout << endl;

    return 0;
}
