
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

int n;
int p[100010];

int main() {
    cin >> n;
	if(n%4 == 2 || n%4 == 3){
		cout << -1 << endl;
		return 0;
	}

	int ptr1 = 1;
	int ptr2 = n;
	while(ptr2 - ptr1 + 1 >= 4){
		p[ptr2-1] = ptr1;
		p[ptr1] = ptr1+1;
		p[ptr1+1] = ptr2;
		p[ptr2] = ptr2-1;
		ptr1 += 2;
		ptr2 -= 2;
	}

	if(ptr1 == ptr2) p[ptr1] = ptr1;


	REP(i, n) cout << p[i+1] << " ";
	cout << endl;

    return 0;
}
