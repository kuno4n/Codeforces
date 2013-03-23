
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


LL n, k;

bool C(LL m){
	if((k+m)*(k-m+1)/2 - (k-m) < n) return true;
	return false;
}


int main() {
	cin >> n >> k;
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	if(n > (k+2)*(k-1)/2 - (k-2)){
		cout << -1 << endl;
		return 0;
	}
	if(n <= k){
		cout << 1 << endl;
		return 0;
	}

	LL lo = 1;
	LL hi = k;
	while(hi - lo > 1){
		LL mi = (lo+hi) / 2;
		if(C(mi)) hi = mi;
		else lo = mi;
	}

	cout << (k-hi) + 2 << endl;
    
    return 0;
}
